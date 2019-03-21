#!/bin/bash

commands=(
    # TEST 1 - launch two agents robot_0 and robot_1
    "roslaunch vishnu_rudrasamudram_intern add_agent.launch"
    "roslaunch vishnu_rudrasamudram_intern add_agent.launch robot_id:=robot_1 x:=3 y:=5"
    # Launch plannng service and rviz
    "roslaunch vishnu_rudrasamudram_intern planner_and_viz.launch"
)

set finalCommand=""
for (( i = 0; i < ${#commands[@]} ; i++ )); do
    export finalCommand+="--tab -e 'bash -c \"sleep 5; ${commands[$i]}\"' "
done
# export finalCommand+="--tab -e 'bash -c \"sleep 2; rosservice call /update_goal \"goal:
#   x: 9.0
#   y: 9.0
#   theta: 0.0
# id:
#   data: 'robot_1'\""

eval "gnome-terminal "$finalCommand