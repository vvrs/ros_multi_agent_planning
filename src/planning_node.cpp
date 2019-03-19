#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Pose2D.h"
#include "vishnu_rudrasamudram_intern/Path.h"

#include "vishnu_rudrasamudram_intern/Algorithm.hpp"

#include <sstream>
#include <ctime>
#include <iostream>






int main(int argc, char **argv)
{
    ros::init(argc, argv, "planner");

    ros::NodeHandle nh;

    std::vector<std::vector<int> > world_state(GRID_SIZE_H,std::vector<int>(GRID_SIZE_W,FREE_CELL));
    std::pair<int, int> a = {0, 0};
    std::pair<int, int> b = {5, 0};

    multi_agent_planner::Dijkstra c;
    std::vector<std::pair<int, int>> path = c.Search(world_state, a, b);

    // Create a publisher (agent_feedback)
    // TODO:: Add namespace explicitly
    ros::Publisher planningPathPub = nh.advertise<vishnu_rudrasamudram_intern::Path>("/plan",100);

    while(ros::ok()){
        vishnu_rudrasamudram_intern::Path pathMsg;
        geometry_msgs::Pose2D temp;
         for(const auto p : path)
         {
            temp.x = p.first;
            temp.y = p.second;
            temp.theta = 0;

            pathMsg.poses.push_back(temp);
         }

        planningPathPub.publish(pathMsg);

        ROS_INFO("Publishing the path...\n");

        ros::spinOnce();

        sleep(2);


    }
    
}