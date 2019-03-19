#pragma once

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Pose2D.h"

#include "vishnu_rudrasamudram_intern/Algorithm.hpp"

// #include

namespace multi_agent_planner
{
/*
    This is going to be the main class for the agent to interact
    using ROS
*/

class Agent
{
  private:
    /*! ROS Node handle */
    ros::NodeHandle &nodeHandle_;

    geometry_msgs::Pose2D location;

    ros::Publisher agentFeedbackPub;

    ros::ServiceServer goalUpdateServer;

    Dijkstra algorithm_;
    std::vector<std::vector<int> > world_state(GRID_SIZE_H,std::vector<int>(GRID_SIZE_W,FREE_CELL));

  public:
    
    Agent(ros::NodeHandle& nodeHandle, int id, geometry_msgs::Pose2D& startPose);
    void SetPosition(geometry_msgs::Pose2D& pos);
    virtual ~Agent();
private:
bool serviceCallback(std_srvs::Trigger::Request& request,
                     std_srvs::Trigger::Response& response);


};
} // namespace multi_agent_planner