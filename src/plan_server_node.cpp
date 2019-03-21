#include "vishnu_rudrasamudram_intern/PlanServer.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "planning_server");
    ros::NodeHandle nh;
    multi_agent_planner::PlanServer ps(nh);

    return 0;
}