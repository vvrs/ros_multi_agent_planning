/*
File : paths2rvis_node.cpp
Vishnu Rudrasamudram
vishnu.rudrasamudram@gmail.com
*/

#include "vishnu_rudrasamudram_intern/Path2RViz.hpp"

int main(int argc, char **argv)
{
    // ROS set-ups:
    ros::init(argc, argv, "path2rviz_node"); //node name

    ros::NodeHandle nh; // create a node handle; need to pass this to the class constructor

    multi_agent_planner::paths2rviz p2r(nh);

    return 0;
}