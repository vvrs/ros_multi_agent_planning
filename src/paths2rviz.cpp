/*
File : paths2rviz.cpp
Vishnu Rudrasamudram
vishnu.rudrasamudram@gmail.com
*/

#include "vishnu_rudrasamudram_intern/Path2RViz.hpp"

multi_agent_planner::paths2rviz::paths2rviz(ros::NodeHandle &nh) : nh(nh)
{
    ros::Subscriber sub = nh.subscribe("agent_path", 1000, &paths2rviz::agentPathCallback, this);
    ros::Rate rate(RATE);
    while (ros::ok())
    {
        publish_paths();
        ros::spinOnce();
        rate.sleep();
    }
}

multi_agent_planner::paths2rviz::~paths2rviz()
{
}

void multi_agent_planner::paths2rviz::agentPathCallback(const vishnu_rudrasamudram_intern::Path &msg)
{
    // declare publisher for each agent
    pubs_map[msg.id.data] = nh.advertise<nav_msgs::Path>(msg.id.data + "/path", 100);

    // store agent's path to publish
    nav_msgs::Path temp_path;
    temp_path.header.frame_id = "map";
    for (const auto p : msg.poses)
    {
        geometry_msgs::PoseStamped temp_ps;
        temp_ps.header.frame_id = msg.id.data;
        temp_ps.pose.position.x = p.x;
        temp_ps.pose.position.y = p.y;

        temp_path.poses.push_back(temp_ps);
    }

    paths_map[msg.id.data] = temp_path;
}
void multi_agent_planner::paths2rviz::publish_paths()
{
    for (const auto &p : pubs_map)
    {
        p.second.publish(paths_map[p.first]);
    }
}