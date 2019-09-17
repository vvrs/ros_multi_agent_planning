# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "ros_multi_agent_planning: 2 messages, 2 services")

set(MSG_I_FLAGS "-Iros_multi_agent_planning:/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg;-Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg;-Ivishnu_rudrasamudram_intern:/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(ros_multi_agent_planning_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/srv/UpdateGoal.srv" NAME_WE)
add_custom_target(_ros_multi_agent_planning_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ros_multi_agent_planning" "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/srv/UpdateGoal.srv" "geometry_msgs/Pose2D:std_msgs/String"
)

get_filename_component(_filename "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/srv/GetPlan.srv" NAME_WE)
add_custom_target(_ros_multi_agent_planning_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ros_multi_agent_planning" "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/srv/GetPlan.srv" "geometry_msgs/Pose2D:ros_multi_agent_planning/Path:std_msgs/String"
)

get_filename_component(_filename "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Path.msg" NAME_WE)
add_custom_target(_ros_multi_agent_planning_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ros_multi_agent_planning" "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Path.msg" "geometry_msgs/Pose2D:std_msgs/String"
)

get_filename_component(_filename "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Position.msg" NAME_WE)
add_custom_target(_ros_multi_agent_planning_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ros_multi_agent_planning" "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Position.msg" "geometry_msgs/Pose2D:std_msgs/String"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(ros_multi_agent_planning
  "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Path.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose2D.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/String.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ros_multi_agent_planning
)
_generate_msg_cpp(ros_multi_agent_planning
  "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Position.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose2D.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/String.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ros_multi_agent_planning
)

### Generating Services
_generate_srv_cpp(ros_multi_agent_planning
  "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/srv/UpdateGoal.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose2D.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/String.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ros_multi_agent_planning
)
_generate_srv_cpp(ros_multi_agent_planning
  "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/srv/GetPlan.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose2D.msg;/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Path.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/String.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ros_multi_agent_planning
)

### Generating Module File
_generate_module_cpp(ros_multi_agent_planning
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ros_multi_agent_planning
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(ros_multi_agent_planning_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(ros_multi_agent_planning_generate_messages ros_multi_agent_planning_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/srv/UpdateGoal.srv" NAME_WE)
add_dependencies(ros_multi_agent_planning_generate_messages_cpp _ros_multi_agent_planning_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/srv/GetPlan.srv" NAME_WE)
add_dependencies(ros_multi_agent_planning_generate_messages_cpp _ros_multi_agent_planning_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Path.msg" NAME_WE)
add_dependencies(ros_multi_agent_planning_generate_messages_cpp _ros_multi_agent_planning_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Position.msg" NAME_WE)
add_dependencies(ros_multi_agent_planning_generate_messages_cpp _ros_multi_agent_planning_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ros_multi_agent_planning_gencpp)
add_dependencies(ros_multi_agent_planning_gencpp ros_multi_agent_planning_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ros_multi_agent_planning_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(ros_multi_agent_planning
  "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Path.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose2D.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/String.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ros_multi_agent_planning
)
_generate_msg_eus(ros_multi_agent_planning
  "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Position.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose2D.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/String.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ros_multi_agent_planning
)

### Generating Services
_generate_srv_eus(ros_multi_agent_planning
  "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/srv/UpdateGoal.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose2D.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/String.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ros_multi_agent_planning
)
_generate_srv_eus(ros_multi_agent_planning
  "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/srv/GetPlan.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose2D.msg;/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Path.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/String.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ros_multi_agent_planning
)

### Generating Module File
_generate_module_eus(ros_multi_agent_planning
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ros_multi_agent_planning
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(ros_multi_agent_planning_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(ros_multi_agent_planning_generate_messages ros_multi_agent_planning_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/srv/UpdateGoal.srv" NAME_WE)
add_dependencies(ros_multi_agent_planning_generate_messages_eus _ros_multi_agent_planning_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/srv/GetPlan.srv" NAME_WE)
add_dependencies(ros_multi_agent_planning_generate_messages_eus _ros_multi_agent_planning_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Path.msg" NAME_WE)
add_dependencies(ros_multi_agent_planning_generate_messages_eus _ros_multi_agent_planning_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Position.msg" NAME_WE)
add_dependencies(ros_multi_agent_planning_generate_messages_eus _ros_multi_agent_planning_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ros_multi_agent_planning_geneus)
add_dependencies(ros_multi_agent_planning_geneus ros_multi_agent_planning_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ros_multi_agent_planning_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(ros_multi_agent_planning
  "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Path.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose2D.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/String.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ros_multi_agent_planning
)
_generate_msg_lisp(ros_multi_agent_planning
  "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Position.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose2D.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/String.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ros_multi_agent_planning
)

### Generating Services
_generate_srv_lisp(ros_multi_agent_planning
  "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/srv/UpdateGoal.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose2D.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/String.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ros_multi_agent_planning
)
_generate_srv_lisp(ros_multi_agent_planning
  "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/srv/GetPlan.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose2D.msg;/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Path.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/String.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ros_multi_agent_planning
)

### Generating Module File
_generate_module_lisp(ros_multi_agent_planning
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ros_multi_agent_planning
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(ros_multi_agent_planning_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(ros_multi_agent_planning_generate_messages ros_multi_agent_planning_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/srv/UpdateGoal.srv" NAME_WE)
add_dependencies(ros_multi_agent_planning_generate_messages_lisp _ros_multi_agent_planning_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/srv/GetPlan.srv" NAME_WE)
add_dependencies(ros_multi_agent_planning_generate_messages_lisp _ros_multi_agent_planning_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Path.msg" NAME_WE)
add_dependencies(ros_multi_agent_planning_generate_messages_lisp _ros_multi_agent_planning_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Position.msg" NAME_WE)
add_dependencies(ros_multi_agent_planning_generate_messages_lisp _ros_multi_agent_planning_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ros_multi_agent_planning_genlisp)
add_dependencies(ros_multi_agent_planning_genlisp ros_multi_agent_planning_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ros_multi_agent_planning_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(ros_multi_agent_planning
  "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Path.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose2D.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/String.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ros_multi_agent_planning
)
_generate_msg_nodejs(ros_multi_agent_planning
  "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Position.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose2D.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/String.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ros_multi_agent_planning
)

### Generating Services
_generate_srv_nodejs(ros_multi_agent_planning
  "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/srv/UpdateGoal.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose2D.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/String.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ros_multi_agent_planning
)
_generate_srv_nodejs(ros_multi_agent_planning
  "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/srv/GetPlan.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose2D.msg;/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Path.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/String.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ros_multi_agent_planning
)

### Generating Module File
_generate_module_nodejs(ros_multi_agent_planning
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ros_multi_agent_planning
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(ros_multi_agent_planning_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(ros_multi_agent_planning_generate_messages ros_multi_agent_planning_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/srv/UpdateGoal.srv" NAME_WE)
add_dependencies(ros_multi_agent_planning_generate_messages_nodejs _ros_multi_agent_planning_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/srv/GetPlan.srv" NAME_WE)
add_dependencies(ros_multi_agent_planning_generate_messages_nodejs _ros_multi_agent_planning_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Path.msg" NAME_WE)
add_dependencies(ros_multi_agent_planning_generate_messages_nodejs _ros_multi_agent_planning_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Position.msg" NAME_WE)
add_dependencies(ros_multi_agent_planning_generate_messages_nodejs _ros_multi_agent_planning_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ros_multi_agent_planning_gennodejs)
add_dependencies(ros_multi_agent_planning_gennodejs ros_multi_agent_planning_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ros_multi_agent_planning_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(ros_multi_agent_planning
  "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Path.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose2D.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/String.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ros_multi_agent_planning
)
_generate_msg_py(ros_multi_agent_planning
  "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Position.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose2D.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/String.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ros_multi_agent_planning
)

### Generating Services
_generate_srv_py(ros_multi_agent_planning
  "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/srv/UpdateGoal.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose2D.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/String.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ros_multi_agent_planning
)
_generate_srv_py(ros_multi_agent_planning
  "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/srv/GetPlan.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose2D.msg;/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Path.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/String.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ros_multi_agent_planning
)

### Generating Module File
_generate_module_py(ros_multi_agent_planning
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ros_multi_agent_planning
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(ros_multi_agent_planning_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(ros_multi_agent_planning_generate_messages ros_multi_agent_planning_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/srv/UpdateGoal.srv" NAME_WE)
add_dependencies(ros_multi_agent_planning_generate_messages_py _ros_multi_agent_planning_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/srv/GetPlan.srv" NAME_WE)
add_dependencies(ros_multi_agent_planning_generate_messages_py _ros_multi_agent_planning_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Path.msg" NAME_WE)
add_dependencies(ros_multi_agent_planning_generate_messages_py _ros_multi_agent_planning_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vishnu/catkin_ws/src/ros_multi_agent_planning/msg/Position.msg" NAME_WE)
add_dependencies(ros_multi_agent_planning_generate_messages_py _ros_multi_agent_planning_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ros_multi_agent_planning_genpy)
add_dependencies(ros_multi_agent_planning_genpy ros_multi_agent_planning_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ros_multi_agent_planning_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ros_multi_agent_planning)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ros_multi_agent_planning
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(ros_multi_agent_planning_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(ros_multi_agent_planning_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET vishnu_rudrasamudram_intern_generate_messages_cpp)
  add_dependencies(ros_multi_agent_planning_generate_messages_cpp vishnu_rudrasamudram_intern_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ros_multi_agent_planning)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ros_multi_agent_planning
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(ros_multi_agent_planning_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(ros_multi_agent_planning_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET vishnu_rudrasamudram_intern_generate_messages_eus)
  add_dependencies(ros_multi_agent_planning_generate_messages_eus vishnu_rudrasamudram_intern_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ros_multi_agent_planning)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ros_multi_agent_planning
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(ros_multi_agent_planning_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(ros_multi_agent_planning_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET vishnu_rudrasamudram_intern_generate_messages_lisp)
  add_dependencies(ros_multi_agent_planning_generate_messages_lisp vishnu_rudrasamudram_intern_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ros_multi_agent_planning)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ros_multi_agent_planning
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(ros_multi_agent_planning_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(ros_multi_agent_planning_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET vishnu_rudrasamudram_intern_generate_messages_nodejs)
  add_dependencies(ros_multi_agent_planning_generate_messages_nodejs vishnu_rudrasamudram_intern_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ros_multi_agent_planning)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ros_multi_agent_planning\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ros_multi_agent_planning
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(ros_multi_agent_planning_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(ros_multi_agent_planning_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET vishnu_rudrasamudram_intern_generate_messages_py)
  add_dependencies(ros_multi_agent_planning_generate_messages_py vishnu_rudrasamudram_intern_generate_messages_py)
endif()
