#include <tf2_darc/transform_listener.h>
#include <ros/console.h>

using namespace tf2;

void TransformListener::tfHandler(const tf2_msgs::TFMessageConstPtr msg)
{
  tfImpl(msg, false);
}
void TransformListener::tfStaticHandler(const tf2_msgs::TFMessageConstPtr msg)
{
  tfImpl(msg, true);
}

void TransformListener::tfImpl(const tf2_msgs::TFMessageConstPtr& msg, bool is_static)
{
  const tf2_msgs::TFMessage& msg_in = *msg;
  for (unsigned int i = 0; i < msg_in.transforms.size(); i++)
  {
    std::string authority = "todo";
    try
    {
      setTransform(msg_in.transforms[i], authority, is_static);
    }
    
    catch (TransformException& ex)
    {
      ///\todo Use error reporting
      std::string temp = ex.what();
      ROS_ERROR("Failure to set recieved transform from %s to %s with error: %s\n", msg_in.transforms[i].child_frame_id.c_str(), msg_in.transforms[i].header.frame_id.c_str(), temp.c_str());
    }
  }
};





