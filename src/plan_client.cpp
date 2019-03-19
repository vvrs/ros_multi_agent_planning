#include <iostream>
#include <cstdlib>
#include <vector>

#include "ros/ros.h"
#include "vishnu_rudrasamudram_intern/GetPlan.h"


int main(int argc, char **argv)
{
    ros::init(argc, argv, "get_plan_client");
    if(argc != 3)
    {
        ROS_INFO("usage : plan_client_node X Y");
        return 1;
    }

    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<vishnu_rudrasamudram_intern::GetPlan>("get_plan");

    vishnu_rudrasamudram_intern::GetPlan srv;

    srv.request.goal.x = atoi(argv[1]);
    srv.request.goal.y = atoi(argv[2]);

    if(client.call(srv)){
        vishnu_rudrasamudram_intern::Path p = srv.response.path;
        for(int i=0;i<p.poses.size();++i)
            std::cout<<p.poses[i].x<<" "<<p.poses[i].y<<std::endl;
    }
    else
    {
        ROS_ERROR("Failed to call service get_plan");
        return 1;
    }
    return 0;
}