# vishnu_rudrasamudram_intern

Multi-agent scenario with decentralized planning

### Overview

This is a package to demonstrate multi-agent scenario with decentralized planning in a grid world.This is a package to demonstrate multi-agent scenario with decentralized planning in a grid world. The final result can be seen below,

![rviz_display](docs/result.png)


### Installation
#### Building  

> Make sure that you have ROS installed and workspace is created

```git clone https://github.com/vvrs/vishnu_rudrasamudram_intern.git```  
```cd ~/catkin_ws```  
```catkin_make```

### Usage  
  
- Use 'add_agent.launch' to create a node for a new agent  

```roslaunch vishnu_rudrasamudram_intern add_agent.launch```

- Run 'plan_server_node' to get the path for a given agent  

```rosrun vishnu_rudrasamudram_intern plan_server_node```   

### Launch Files
##### add_agent.launch
Use this launch file to add new agent to the environment. When launching the new agent, make sure to provide `robot_id`. Otherwise, the new node kills the old node because of the name conflict. Use, x,y,theta to provide initial location. 

###### Arguments
* **robot_id** : Default `robot_0'
* **x** : Default `0`  
* **y** : Default `0`
* **theta** : Default `0`  

##### planner_and_viz.launch
This launches planner server node, and rviz node for visualization of the path.

### Nodes

##### agent_node

##### plan_server_node

##### paths2rviz_node

