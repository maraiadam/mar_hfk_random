#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/range.hpp"
#include "std_msgs/msg/string.hpp"
#include <memory>

class CollisionAlertNode : public rclcpp::Node
{
public:
  CollisionAlertNode() : Node("collision_alert"), threshold_(0.3)
  {
    subscription_ = this->create_subscription<sensor_msgs::msg::Range>(
        "distance", 10,
        std::bind(&CollisionAlertNode::callback, this, std::placeholders::_1));

    publisher_ = this->create_publisher<std_msgs::msg::String>("collision_warning", 10);

    RCLCPP_INFO(this->get_logger(), "Collision alert node started.");
  }

private:
  void callback(const sensor_msgs::msg::Range::SharedPtr msg)
  {
    if (msg->range < threshold_)
    {
      auto warning = std_msgs::msg::String();
      warning.data = "⚠️ COLLISION WARNING! Object at " + std::to_string(msg->range) + " m";
      publisher_->publish(warning);
      RCLCPP_WARN(this->get_logger(), "%s", warning.data.c_str());
    }
    else
    {
      RCLCPP_INFO(this->get_logger(), "Safe distance: %.2f m", msg->range);
    }
  }

  double threshold_;
  rclcpp::Subscription<sensor_msgs::msg::Range>::SharedPtr subscription_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CollisionAlertNode>());
  rclcpp::shutdown();
  return 0;
}
