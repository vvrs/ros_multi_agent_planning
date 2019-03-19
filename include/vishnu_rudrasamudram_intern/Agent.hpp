#pragma once

#include "vishnu_rudrasamudram_intern/Algorithm.hpp"

#include <ros/ros.h>

namespace multi_agent_planner{
/*
    This is going to be the main class for the agent to interact
    using ROS
*/

class Agent
{
private:
    /*! ROS Node handle */
    ros::NodeHandle& nodeHandle_;

public:
    /*!
     * Constructor
     * @param nodeHandle the ROS node handle
     */
    Agent(std::string name);

    /*!
     * Destructor
     */
    virtual ~Agent();

// private:
//     /*!
//      * Reads and verifies the ROS parameters.
//      * @return true if successful.
//      */
//     bool readParams();




};

}