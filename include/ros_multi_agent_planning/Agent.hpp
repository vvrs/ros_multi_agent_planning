/*
File : Agent.hpp
Vishnu Rudrasamudram
vishnu.rudrasamudram@gmail.com
*/

#pragma once

#include "ros/ros.h"

// msgs
#include "std_msgs/String.h"
#include "geometry_msgs/Pose2D.h"
#include "ros_multi_agent_planning/Position.h"
#include "ros_multi_agent_planning/Path.h"
#include "ros_multi_agent_planning/GetPlan.h"
#include "ros_multi_agent_planning/UpdateGoal.h"

// C++_ specific
#include <sstream>
#include <ctime>
#include <iostream>

#define RATE 10

namespace multi_agent_planner
{
  /**
   * @class Agent
   * @brief Implements the Agent method to publish the feedback and provide a service
   */
class Agent
{
private:
  ros::NodeHandle nh; //Node hadler for the node that uses this class
  ros_multi_agent_planning::Position location; //To publish the agent's feedback
  ros_multi_agent_planning::Path m_path_msg; //To get and store path from path planning service

  // Publishers
  ros::Publisher agentFeedbackPub; 
  ros::Publisher agentPathPub;

  // Services
  ros::ServiceServer plan_service;

public:
  /**
 * @brief Construct a new Agent object
 * 
 * @param nh Node handler
 * @param robot_id Agent's id to create one
 * @param x Initial x
 * @param y Initial y
 * @param theta Initial theta (we are assuming that the yaw is always zero)
 */
  Agent(ros::NodeHandle &nh, std::string robot_id, int x, int y, int theta);

  /**
   * @brief Service callback function for '/update_goal'
   * 
   * @param req id and position (x,y,theta)
   * @param res just an acknowledgement
   * @return true succeful processing of request
   * @return false no response
   */
  bool updateGoal_Server(ros_multi_agent_planning::UpdateGoal::Request &req,
                         ros_multi_agent_planning::UpdateGoal::Response &res);

  /**
  * @brief Publishes robots current location
  * 
  */
  void publishFeedBack();
  /**
   * @brief Publishes the global path the agent is currently traversing
   * 
   */
  void publishPath();

  /**
   * @brief Update the pose of the agent 
   * 
   * @param pose Next pose
   */
  void updatePose(geometry_msgs::Pose2D &pose);

  /**
   * @brief Destroy the Agent object
   * 
   */
  ~Agent();
};

} // namespace multi_agent_planner