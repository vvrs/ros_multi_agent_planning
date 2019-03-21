#include "vishnu_rudrasamudram_intern/Path2RViz.hpp"

paths2rviz::paths2rviz(ros::NodeHandle& nh):nh(nh)
{
    ros::Subscriber sub = nh.subscribe("agent_path",1000,&paths2rviz::agentPathCallback, this);
    ros::Rate rate(1);
    while(ros::ok()){
        publish_paths();
        ros::spinOnce();
        rate.sleep();
    }
}

paths2rviz::~paths2rviz()
{
}

void paths2rviz::agentPathCallback(const vishnu_rudrasamudram_intern::Path& msg)
{

        pubs_map[msg.id.data] = nh.advertise<nav_msgs::Path>(msg.id.data+"/path", 100);
        nav_msgs::Path temp_path;
        temp_path.header.frame_id = "map";
        for(const auto p : msg.poses)
        {
            geometry_msgs::PoseStamped temp_ps;
            temp_ps.header.frame_id = msg.id.data;
            temp_ps.pose.position.x = p.x;
            temp_ps.pose.position.y = p.y;

            temp_path.poses.push_back(temp_ps);
        }

        paths_map[msg.id.data] = temp_path;

}
void paths2rviz::publish_paths()
{
    for(const auto& p : pubs_map)
    {
        p.second.publish(paths_map[p.first]);
    }
}
int main(int argc, char** argv) 
{
    // ROS set-ups:
    ros::init(argc, argv, "path2rviz_node"); //node name

    ros::NodeHandle nh; // create a node handle; need to pass this to the class constructor

    paths2rviz p2r(nh);
 
    return 0;
} 