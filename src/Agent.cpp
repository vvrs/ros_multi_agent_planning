#include "vishnu_rudrasamudram_intern/Agent.hpp"

multi_agent_planner::Agent::Agent(ros::NodeHandle &nh, std::string robot_id, int x, int y, int theta)
{
    nh = nh;
    agentFeedbackPub = nh.advertise<vishnu_rudrasamudram_intern::Position>("/agent_feedback", 100);
    agentPathPub = nh.advertise<vishnu_rudrasamudram_intern::Path>("/agent_path", 100);
    plan_service = nh.advertiseService("update_goal", &Agent::updateGoal_Server, this);
    // Set initial msg data
    location.id.data = robot_id;
    location.position.x = x;
    location.position.y = y;
    location.position.theta = theta;
    agentFeedbackPub.publish(location);
    ros::Rate rate(1);
    while(ros::ok()){
        publishFeedBack();
        publishPath();
        ros::spinOnce();
        rate.sleep();
    }
    std::cout << "Agent " << robot_id << " node is running ...\n";
}

bool multi_agent_planner::Agent::updateGoal_Server(vishnu_rudrasamudram_intern::UpdateGoal::Request &req,
                              vishnu_rudrasamudram_intern::UpdateGoal::Response &res)
{
    ROS_INFO("updateGoal called...");

    ros::ServiceClient client = nh.serviceClient<vishnu_rudrasamudram_intern::GetPlan>("get_plan");

    vishnu_rudrasamudram_intern::GetPlan srv;

    srv.request.goal.x = req.goal.x;
    srv.request.goal.y = req.goal.y;
    srv.request.id.data = req.id.data;
    if (client.call(srv))
    {
        vishnu_rudrasamudram_intern::Path path = srv.response.path;
        vishnu_rudrasamudram_intern::Path pathMsg;
        geometry_msgs::Pose2D temp;
        for (const auto p : path.poses)
        {
            temp.x = p.x;
            temp.y = p.y;
            temp.theta = p.theta;

            pathMsg.poses.push_back(temp);
        }
        pathMsg.id.data = req.id.data;
        // res.path = pathMsg;
        m_path_msg = pathMsg;
        res.response.data = "Path received...";
    }
    else
    {
        ROS_ERROR("Failed to call service get_plan");
        return 1;
    }
    // vishnu_rudrasamudram_intern::GetPlan srv;

    // srv.request.goal.x = req.goal.x;
    // srv.request.goal.y = req.goal.y;
    // srv.request.id.data = req.id.data;

    // if(ros::service::call("get_plan",srv))
    // {
    //     res.response.data = "Path Received...";
    // }
    // else
    // {
    //     ROS_INFO("Failed to call the service...");
    //     return 1;
    // }

    // res.response.data = "Sucess...";
    return true;
}

void multi_agent_planner::Agent::publishFeedBack()
{
    // std::cout << "Feedback publisher " << location.id << std::endl;
    // std::cout << "Feedback publisher x " << location.position.x << std::endl;
    // std::cout << "Feedback publisher y " << location.position.y << std::endl;
    // std::cout << "Feedback publisher theta " << location.position.theta << std::endl;
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


