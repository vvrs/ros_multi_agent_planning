/*
File : PlanServer.hpp
Vishnu Rudrasamudram
vishnu.rudrasamudram@gmail.com
*/

#pragma once

#include "ros/ros.h"
#include "geometry_msgs/Pose2D.h"
#include "vishnu_rudrasamudram_intern/Algorithm.hpp"
#include "vishnu_rudrasamudram_intern/GetPlan.h"
#include "vishnu_rudrasamudram_intern/Position.h"
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
  vishnu_rudrasamudram_intern::Position location;

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
  bool getPlan_Server(vishnu_rudrasamudram_intern::GetPlan::Request &req,
                      vishnu_rudrasamudram_intern::GetPlan::Response &res);
  /**
   * @brief Callback for /agent_feedback
   * 
   * @param msg 
   */
  void callBack(const vishnu_rudrasamudram_intern::Position &msg);

  /**
   * @brief Destroy the Plan Server object
   * 
   */
  ~PlanServer();

protected:
  ros::Subscriber sub;
};
} // namespace multi_agent_planner