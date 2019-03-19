#include "ros/ros.h"
#include "vishnu_rudrasamudram_intern/Algorithm.hpp"
#include "vishnu_rudrasamudram_intern/GetPlan.h"

bool GetPlanServer(vishnu_rudrasamudram_intern::GetPlan::Request &req,
                   vishnu_rudrasamudram_intern::GetPlan::Response &res)
{

    std::vector<std::vector<int>> world_state(GRID_SIZE_H, std::vector<int>(GRID_SIZE_W, FREE_CELL));
    std::pair<int, int> a = {0, 0};
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
    res.path = pathMsg;
    ROS_INFO("Sent the path...");

    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc,argv,"planning_server");
    ros::NodeHandle nh;

    ros::ServiceServer plan_service = nh.advertiseService("get_plan", GetPlanServer);
    ROS_INFO("Ready to send plan...");
    ros::spin();
    
    return 0;
}