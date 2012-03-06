cmake_minimum_required(VERSION 2.8)
project(geometry_experimental)

find_package(catkin REQUIRED)
find_package(ROS COMPONENTS roscpp)

catkin_stack()
catkin_project(geometry_experimental)

add_subdirectory(tf2_msgs)
add_subdirectory(tf2)
add_subdirectory(tf2_darc)