/*
File : Path2RViz.hpp
Vishnu Rudrasamudram
vishnu.rudrasamudram@gmail.com
*/

#pragma once

#define RATE 10

#include "ros/ros.h"
#include "nav_msgs/Path.h"
#include "geometry_msgs/PoseStamped.h"
#include "vishnu_rudrasamudram_intern/Path.h"

#include <stdio.h>
#include <map>
namespace multi_agent_planner
{
class paths2rviz
{
    /**
     * @class paths2rviz
     * @brief Makes the paths compatible with rviz for visualization
     * 
     */
  private:
    // Received from agent nodes
    std::map<std::string, nav_msgs::Path> paths_map;

    // To send to rviz (publish)
    std::map<std::string, ros::Publisher> pubs_map;


    ros::NodeHandle nh;

  public:
  /**
   * @brief Construct a new paths2rviz object
   * 
   * @param nh Node handle
   */
    paths2rviz(ros::NodeHandle &nh);

    /**
     * @brief Callback to receive message from agent
     * 
     * @param msg Path with 'id' and 'poses'
     */
    void agentPathCallback(const vishnu_rudrasamudram_intern::Path &msg);

    /**
     * @brief Publishes all the paths appending id to the topic
     * 
     */
    void publish_paths();

    /**
     * @brief Destroy the paths2rviz object
     * 
     */
    ~paths2rviz();
};
} // namespace multi_agent_planner