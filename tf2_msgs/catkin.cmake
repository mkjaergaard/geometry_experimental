cmake_minimum_required(VERSION 2.8)
project(tf2_msgs)

add_message_files(
  DIRECTORY msg
  FILES TF2Error.msg TFMessage.msg)

add_service_files(
  DIRECTORY srv
  FILES FrameGraph.srv)

generate_messages(DEPENDENCIES std_msgs geometry_msgs)

catkin_project(tf2_msgs)

