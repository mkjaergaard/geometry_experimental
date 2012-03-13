cmake_minimum_required(VERSION 2.8)
project(tf2)

find_package(catkin)
find_package(ROS REQUIRED COMPONENTS rosconsole)

include_directories(include)
include_directories(${ROS_INCLUDE_DIRS})

add_library(tf2 SHARED src/cache.cpp src/buffer_core.cpp src/static_cache.cpp)
target_link_libraries(tf2 ${ROS_LIBRARIES})

catkin_project(tf2
  INCLUDE_DIRS include
  DEPENDS rosconsole)
