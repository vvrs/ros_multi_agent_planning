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

  private:
    vishnu_rudrasamudram_intern::Position location;
    std::map<std::string, geometry_msgs::Pose2D> pos_map;
  public:
    PlanServer(ros::NodeHandle &nh);
    bool getPlan_Server(vishnu_rudrasamudram_intern::GetPlan::Request &req,
                        vishnu_rudrasamudram_intern::GetPlan::Response &res);
    void callBack(const vishnu_rudrasamudram_intern::Position &msg);
    ~PlanServer();

  protected:
    ros::Subscriber sub;
};
} // namespace multi_agent_planner