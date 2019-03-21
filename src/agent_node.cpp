#include "vishnu_rudrasamudram_intern/Agent.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "agent_node");
    ros::NodeHandle nh;

    std::string robot_id = argv[1];
    int init_x = atoi(argv[2]);
    int init_y = atoi(argv[3]);
    int init_theta = atoi(argv[4]);

    vishnu_rudrasamudram_intern::Position init_p;
    init_p.id.data = robot_id;
    init_p.position.x = init_x;
    init_p.position.y = init_y;
    init_p.position.theta = init_theta;

    multi_agent_planner::Agent agent_(nh, robot_id, init_x, init_y, init_theta);
    ros::Rate rate(10);
    while (ros::ok())
    {

        // agent_.updatePose(init_p);
        agent_.publishFeedBack();
        agent_.publishPath();
        // ros::spin();
        // rate.sleep()
    }
    return 0;
}