/*
File : Agent.cpp
Vishnu Rudrasamudram
vishnu.rudrasamudram@gmail.com
*/

#include "ros_multi_agent_planning/Agent.hpp"

multi_agent_planner::Agent::Agent(ros::NodeHandle &nh, std::string robot_id, int x, int y, int theta):nh(nh)
{
    agentFeedbackPub = nh.advertise<ros_multi_agent_planning::Position>("/agent_feedback", 100);
    agentPathPub = nh.advertise<ros_multi_agent_planning::Path>("/agent_path", 100);
    plan_service = nh.advertiseService("update_goal", &Agent::updateGoal_Server, this);
    // Set initial msg data
    location.id.data = robot_id;
    location.position.x = x;
    location.position.y = y;
    location.position.theta = theta;
    agentFeedbackPub.publish(location);
    ros::Rate rate(RATE);
    while (ros::ok())
    {
        publishFeedBack();
        publishPath();
        ros::spinOnce();
        rate.sleep();
    }
    std::cout << "Agent " << robot_id << " node is running ...\n";
}

bool multi_agent_planner::Agent::updateGoal_Server(ros_multi_agent_planning::UpdateGoal::Request &req,
                                                   ros_multi_agent_planning::UpdateGoal::Response &res)
{
    ROS_INFO("updateGoal called...");

    ros::ServiceClient client = nh.serviceClient<ros_multi_agent_planning::GetPlan>("get_plan");

    // Prepare service call to get_plan
    ros_multi_agent_planning::GetPlan srv;

    srv.request.goal.x = req.goal.x;
    srv.request.goal.y = req.goal.y;
    srv.request.id.data = req.id.data;

    // service call
    if (client.call(srv))
    {
        ros_multi_agent_planning::Path path = srv.response.path;
        ros_multi_agent_planning::Path pathMsg;
        geometry_msgs::Pose2D temp;
        for (const auto p : path.poses)
        {
            temp.x = p.x;
            temp.y = p.y;
            temp.theta = p.theta;

            pathMsg.poses.push_back(temp);
        }
        pathMsg.id.data = req.id.data;
        m_path_msg = pathMsg;
        res.response.data = "Path received...";
    }
    else
    {
        ROS_ERROR("Failed to call service get_plan");
        return 1;
    }

    return true;
}

void multi_agent_planner::Agent::publishFeedBack()
{
    agentFeedbackPub.publish(location);
}

void multi_agent_planner::Agent::publishPath()
{
    agentPathPub.publish(m_path_msg);
}

void multi_agent_planner::Agent::updatePose(geometry_msgs::Pose2D &pose)
{
    location.position = pose;
}

multi_agent_planner::Agent::~Agent()
{
}
