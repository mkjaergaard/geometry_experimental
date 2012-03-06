#ifndef TF2_DARC_TRANSFORMLISTENER_H
#define TF2_DARC_TRANSFORMLISTENER_H

#include <darc/subcomponent.h>
#include <darc/pubsub/subscriber.h>
#include <std_msgs/Empty.h>
#include <tf2_msgs/TFMessage.h>
#include <tf2_darc/buffer.h>

namespace tf2
{

class TransformListener : darc::Subcomponent, public tf2::Buffer
{
protected:
  darc::pubsub::Subscriber<tf2_msgs::TFMessage> tf_subscriber_;
  darc::pubsub::Subscriber<tf2_msgs::TFMessage> tf_static_subscriber_;

  //  tf2::BufferCore buffer_;

public:
  TransformListener(darc::Component * owner) :
    darc::Subcomponent(owner),
    tf_subscriber_(this, "/tf", boost::bind( &TransformListener::tfHandler, this, _1 )),
    tf_static_subscriber_(this, "/tf_static", boost::bind( &TransformListener::tfStaticHandler, this, _1 ))
  {
  }

protected:

  /// Callback function for ros message subscriptoin
  void tfHandler(const tf2_msgs::TFMessageConstPtr msg);
  void tfStaticHandler(const tf2_msgs::TFMessageConstPtr msg);
  void tfImpl(const tf2_msgs::TFMessageConstPtr& msg, bool is_static);

};
}

#endif
