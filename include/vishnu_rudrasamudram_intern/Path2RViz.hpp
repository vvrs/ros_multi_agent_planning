#pragma once

#include "ros/ros.h"
#include "nav_msgs/Path.h"
#include "geometry_msgs/PoseStamped.h"
#include "vishnu_rudrasamudram_intern/Path.h"

#include <stdio.h>
#include <map>

class paths2rviz
{
private:
    std::map<std::string, nav_msgs::Path> paths_map;
    std::map<std::string, ros::Publisher> pubs_map;
    ros::NodeHandle nh;
public:
    paths2rviz(ros::NodeHandle& nh);
    void agentPathCallback(const vishnu_rudrasamudram_intern::Path& msg);
    void publish_paths();
    ~paths2rviz();
};