/*
File : plan_server_node.cpp
Vishnu Rudrasamudram
vishnu.rudrasamudram@gmail.com
*/

#include "ros_multi_agent_planning/PlanServer.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "planning_server");
    ros::NodeHandle nh;
    multi_agent_planner::PlanServer ps(nh);

    return 0;
}