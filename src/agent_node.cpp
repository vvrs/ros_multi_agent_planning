#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Pose2D.h"

#include <sstream>
#include <ctime>
#include <iostream>

#include "vishnu_rudrasamudram_intern/Algorithm.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "agent");

    ros::NodeHandle nh;
    
    // Create a publisher (agent_feedback)
    // TODO:: Add namespace explicitly
    ros::Publisher agentFeedbackPub = nh.advertise<geometry_msgs::Pose2D>("/agent_feedback",100);

    // Temperorily publish random pose
    srand(time(NULL));

    //Set the loop to publish at a certain rate
    ros::Rate rate(10);

    while(ros::ok()){
        geometry_msgs::Pose2D msg;

        // Random x,y value between 0 and 10
        msg.x = rand()%10;
        msg.y = rand()%10;
        msg.theta = 0;

        agentFeedbackPub.publish(msg);

        rate.sleep();
    }
}