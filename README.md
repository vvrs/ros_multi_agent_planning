# vishnu_rudrasamudram_intern

Multi-agent scenario with decentralized planning

### Overview

This is a package to demonstrate multi-agent scenario with decentralized planning in a grid world.


### Installation

#### Dependencies
**Boost** Library
#### Building  

> Make sure that you have ROS installed and workspace is created

```bash git clone https://github.com/vvrs/vishnu_rudrasamudram_intern.git```  
```bash cd ~/catkin_ws```  
```bash catkin_make```

### Usage  
  
- Use 'add_agent.launch' to create a node for a new agent  
```bash roslaunch vishnu_rudrasamudram_intern add_agent.launch```

- Run 'plan_server_node' to get the path for a given agent  
```bash rosrun vishnu_rudrasamudram_intern plan_server_node```   

### Launch Files
##### add_agent.launch
###### Arguments
    - **robot_id** : Default `robot_0`  
    - **x** : Default `0`  
    - **y** : Default `0`
    - **theta** : Default `0`  

### Nodes

##### agent_node

##### plan_server_node

