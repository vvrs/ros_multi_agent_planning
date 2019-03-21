#include "vishnu_rudrasamudram_intern/PlanServer.hpp"

multi_agent_planner::PlanServer::PlanServer(ros::NodeHandle& nh)
{
    ros::ServiceServer plan_service = nh.advertiseService("get_plan", &PlanServer::getPlan_Server, this);
    // sub = nh.subscribe("agent_feedback",1000,&PlanServer::callBack, this);
    ROS_INFO("Ready to send plan...");
    ros::spin();
}

multi_agent_planner::PlanServer::~PlanServer()
{
}

void multi_agent_planner::PlanServer::callBack(const vishnu_rudrasamudram_intern::Position& msg)
{
    location = msg;
}


bool multi_agent_planner::PlanServer::getPlan_Server(vishnu_rudrasamudram_intern::GetPlan::Request &req,
                   vishnu_rudrasamudram_intern::GetPlan::Response &res)
{

    ROS_INFO("Get Plan Service called...");

    std::vector<std::vector<int>> world_state(GRID_SIZE_H, std::vector<int>(GRID_SIZE_W, FREE_CELL));

    boost::shared_ptr<vishnu_rudrasamudram_intern::Position const> sharedPose;
    vishnu_rudrasamudram_intern::Position pose_;
    sharedPose = ros::topic::waitForMessage<vishnu_rudrasamudram_intern::Position>("/agent_feedback");

    if(sharedPose != NULL){
        pose_ = *sharedPose;
    }

    std::pair<int, int> a = {pose_.position.x,pose_.position.y};
    std::pair<int, int> b = {req.goal.x, req.goal.y};

    multi_agent_planner::Dijkstra c;
    std::vector<std::pair<int, int>> path = c.Search(world_state, a, b);

    vishnu_rudrasamudram_intern::Path pathMsg;
    geometry_msgs::Pose2D temp;
    for (const auto p : path)
    {
        temp.x = p.first;
        temp.y = p.second;
        temp.theta = 0;

        pathMsg.poses.push_back(temp);
    }
    pathMsg.id.data = req.id.data;
    res.path = pathMsg;
    ROS_INFO("Sent the path...");

    return true;
}