#include "ros/ros.h"
#include "geometry_msgs/Pose2D.h"
#include "vishnu_rudrasamudram_intern/Algorithm.hpp"
#include "vishnu_rudrasamudram_intern/GetPlan.h"
#include <boost/shared_ptr.hpp>

class PlanServer
{

private:
    geometry_msgs::Pose2D location;
public:
    PlanServer(ros::NodeHandle& nh);
    bool getPlan_Server(vishnu_rudrasamudram_intern::GetPlan::Request &req,
                   vishnu_rudrasamudram_intern::GetPlan::Response &res);
    void callBack(const geometry_msgs::Pose2D& msg);
    ~PlanServer();
protected:
    ros::Subscriber sub;
};

PlanServer::PlanServer(ros::NodeHandle& nh)
{
    ros::ServiceServer plan_service = nh.advertiseService("get_plan", &PlanServer::getPlan_Server, this);
    // sub = nh.subscribe("agent_feedback",1000,&PlanServer::callBack, this);
    ROS_INFO("Ready to send plan...");
    ros::spin();
}

PlanServer::~PlanServer()
{
}

void PlanServer::callBack(const geometry_msgs::Pose2D& msg)
{
    location = msg;
}


bool PlanServer::getPlan_Server(vishnu_rudrasamudram_intern::GetPlan::Request &req,
                   vishnu_rudrasamudram_intern::GetPlan::Response &res)
{

    std::vector<std::vector<int>> world_state(GRID_SIZE_H, std::vector<int>(GRID_SIZE_W, FREE_CELL));

    boost::shared_ptr<geometry_msgs::Pose2D const> sharedPose;
    geometry_msgs::Pose2D pose_;
    sharedPose = ros::topic::waitForMessage<geometry_msgs::Pose2D>("/agent_feedback");

    if(sharedPose != NULL){
        pose_ = *sharedPose;
    }

    std::pair<int, int> a = {pose_.x,pose_.y};
    std::pair<int, int> b = {req.goal.x, req.goal.y};

    multi_agent_planner::Dijkstra c;
    std::vector<std::pair<int, int>> path = c.Search(world_state, a, b);

    vishnu_rudrasamudram_intern::Path pathMsg;
    geometry_msgs::Pose2D temp;
    for (const auto p : path)
    {
        temp.x = p.first;
        temp.y = p.second;
        temp.theta = 0;

        pathMsg.poses.push_back(temp);
    }
    res.path = pathMsg;
    ROS_INFO("Sent the path...");

    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc,argv,"planning_server");
    ros::NodeHandle nh;
    PlanServer ps(nh);   
    
    return 0;
}