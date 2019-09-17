/*
File : PlanServer.hpp
Vishnu Rudrasamudram
vishnu.rudrasamudram@gmail.com
*/

#pragma once

#include "ros/ros.h"
#include "geometry_msgs/Pose2D.h"
#include "ros_multi_agent_planning/Algorithm.hpp"
#include "ros_multi_agent_planning/GetPlan.h"
#include "ros_multi_agent_planning/Position.h"
#include <boost/shared_ptr.hpp>
#include <map>
namespace multi_agent_planner
{
class PlanServer
{
/**
 * @class PlanServer
 * @brief Implements '/get_plan' service
 * 
 */
private:
  // Location of the requested agent
  ros_multi_agent_planning::Position location;

  // To maintain separate records for the agents
  std::map<std::string, geometry_msgs::Pose2D> pos_map;

public:

  /**
   * @brief Construct a new Plan Server object
   * 
   * @param nh Node Handle
   */
  PlanServer(ros::NodeHandle &nh);

  /**
   * @brief Callback for get_plan service
   * 
   * @param req Agent's id and goal location
   * @param res Path from Agent's current location to the goal location
   * @return true Successfull
   * @return false Failure
   */
  bool getPlan_Server(ros_multi_agent_planning::GetPlan::Request &req,
                      ros_multi_agent_planning::GetPlan::Response &res);
  /**
   * @brief Callback for /agent_feedback
   * 
   * @param msg 
   */
  void callBack(const ros_multi_agent_planning::Position &msg);

  /**
   * @brief Destroy the Plan Server object
   * 
   */
  ~PlanServer();

protected:
  ros::Subscriber sub;
};
} // namespace multi_agent_planner