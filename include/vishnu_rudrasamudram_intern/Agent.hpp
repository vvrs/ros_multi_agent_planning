#pragma once

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Pose2D.h"
#include "vishnu_rudrasamudram_intern/Position.h"
#include "vishnu_rudrasamudram_intern/Path.h"
#include "vishnu_rudrasamudram_intern/GetPlan.h"
#include "vishnu_rudrasamudram_intern/UpdateGoal.h"

#include <sstream>
#include <ctime>
#include <iostream>

namespace multi_agent_planner
{
class Agent
{
  private:
    ros::NodeHandle nh;
    vishnu_rudrasamudram_intern::Position location;
    vishnu_rudrasamudram_intern::Path m_path_msg;
    ros::Publisher agentFeedbackPub;
    ros::Publisher agentPathPub;
    ros::ServiceServer plan_service;

  public:
    Agent(ros::NodeHandle &nh, std::string robot_id, int x, int y, int theta);
    bool updateGoal_Server(vishnu_rudrasamudram_intern::UpdateGoal::Request &req,
                           vishnu_rudrasamudram_intern::UpdateGoal::Response &res);
    void publishFeedBack();
    void publishPath();
    void updatePose(geometry_msgs::Pose2D &pose);
    ~Agent();
};

} // namespace multi_agent_planner