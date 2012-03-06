cmake_minimum_required(VERSION 2.8)
project(tf2_darc)

find_package(catkin)
find_package(ROS REQUIRED COMPONENTS catkin roscpp tf2)
find_package(darc)

include_directories(include)
include_directories(${ROS_INCLUDE_DIRS})
include_directories(${darc_INCLUDE_DIRS})

add_library(tf2_darc SHARED
  src/transform_listener.cpp src/transform_broadcaster.cpp src/buffer.cpp)

target_link_libraries(tf2_darc tf2)

catkin_project(tf2_darc
  INCLUDE_DIRS include
  LIBRARIES tf2_darc)
