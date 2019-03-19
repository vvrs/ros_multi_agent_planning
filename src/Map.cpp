#include "ros/ros.h"
#include "std_msgs/Int32MultiArray.h"
#include "std_msgs/MultiArrayDimension.h"

#include <iostream>
#include <vector>
#include <array>

#define H (10)
#define W (10)


int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<std_msgs::Int32MultiArray>("matrix_pub", 1);
    ros::Rate loop_rate(10);
    std_msgs::Int32MultiArray map_;
    
    std::vector<std::vector<int>> array(H, std::vector<int>(W,1));

    // fill out message:
    map_.layout.dim.push_back(std_msgs::MultiArrayDimension());
    map_.layout.dim.push_back(std_msgs::MultiArrayDimension());
    map_.layout.dim[0].label = "height";
    map_.layout.dim[1].label = "width";
    map_.layout.dim[0].size = H;
    map_.layout.dim[1].size = W;
    map_.layout.dim[0].stride = H*W;
    map_.layout.dim[1].stride = W;
    map_.layout.data_offset = 0;
    std::vector<int> vec(W*H, 0);
    for (int i=0; i<H; i++)
        for (int j=0; j<W; j++)
            vec[i*W + j] = array[i][j];
    map_.data = vec;

    while (ros::ok())
    {
        pub.publish(map_);
        loop_rate.sleep();
    }

    return 0;
}