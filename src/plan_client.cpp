#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

#include "ros/ros.h"
#include "vishnu_rudrasamudram_intern/GetPlan.h"
#include "vishnu_rudrasamudram_intern/UpdateGoal.h"

// std::map<std::string, std::vector<int>> robot_waypoints;

// void initializeMap(std::vector<std::string>>& node_ids)

bool updateGoal_Server(vishnu_rudrasamudram_intern::UpdateGoal::Request &req,
                              vishnu_rudrasamudram_intern::UpdateGoal::Response &res)
{
    // ROS_INFO("updateGoal called...");

    // // ros::ServiceClient client = nh.serviceClient<vishnu_rudrasamudram_intern::GetPlan>("get_plan");

    // vishnu_rudrasamudram_intern::GetPlan srv;

    // srv.request.goal.x = req.goal.x;
    // srv.request.goal.y = req.goal.y;
    // srv.request.id.data = req.id.data;
    // // if (client.call(srv))
    // if (ros::service::call("get_plan",srv))
    // {
    //     vishnu_rudrasamudram_intern::Path path = srv.response.path;
    //     vishnu_rudrasamudram_intern::Path pathMsg;
    //     geometry_msgs::Pose2D temp;
    //     for (const auto p : path.poses)
    //     {
    //         temp.x = p.x;
    //         temp.y = p.y;
    //         temp.theta = p.theta;

    //         pathMsg.poses.push_back(temp);
    //     }
    //     // pathMsg.id.data = req.id.data;
    //     // res.path = pathMsg;
    //     // m_path_msg = pathMsg;
    //     res.response.data = "Path received...";
    // }
    // else
    // {
    //     ROS_ERROR("Failed to call service get_plan");
    //     return 1;
    // }

    res.response.data = req.id.data;
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "get_plan_client");
    if(argc != 4)
    {
        ROS_INFO("usage : plan_client_node <X> <Y> <Robot ID>");
        return 1;
    }

    ros::NodeHandle nh;

    ros::ServiceServer plan_service = nh.advertiseService("update_goal", updateGoal_Server);
    // ros::ServiceClient client = nh.serviceClient<vishnu_rudrasamudram_intern::GetPlan>("get_plan");

    // vishnu_rudrasamudram_intern::GetPlan srv;

    // srv.request.goal.x = atoi(argv[1]);
    // srv.request.goal.y = atoi(argv[2]);
    // srv.request.id.data = argv[3];
    // if(client.call(srv)){
    //     vishnu_rudrasamudram_intern::Path p = srv.response.path;
    //     std::cout<<"Robot ID : "<<p.id.data<<"\n";
    //     std::cout<<"Path : \n";
    //     for(int i=0;i<p.poses.size();++i)
    //         std::cout<<p.poses[i].x<<" "<<p.poses[i].y<<std::endl;
    // }
    // else
    // {
    //     ROS_ERROR("Failed to call service get_plan");
    //     return 1;
    // }
    ros::spin();
    return 0;
}