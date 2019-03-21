/*
File : agent_node.cpp
Vishnu Rudrasamudram
vishnu.rudrasamudram@gmail.com
*/

#include "vishnu_rudrasamudram_intern/Agent.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "agent_node"); // Node name is replaced with new name to maintain uniqueness
    ros::NodeHandle nh;

    // Initialize an agent
    std::string robot_id = argv[1];
    int init_x = atoi(argv[2]);
    int init_y = atoi(argv[3]);
    int init_theta = atoi(argv[4]);

    vishnu_rudrasamudram_intern::Position init_p;
    init_p.id.data = robot_id;
    init_p.position.x = init_x;
    init_p.position.y = init_y;
    init_p.position.theta = init_theta;

    // Create agent with initial values and robot id
    multi_agent_planner::Agent agent_(nh, robot_id, init_x, init_y, init_theta);
    return 0;
}