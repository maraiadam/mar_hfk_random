#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/range.hpp"
#include <random>

class DistanceSensorNode : public rclcpp::Node
{
public:
  DistanceSensorNode() : Node("distance_sensor")
  {
    publisher_ = this->create_publisher<sensor_msgs::msg::Range>("distance", 10);
    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(500),
        std::bind(&DistanceSensorNode::publish_distance, this));

    RCLCPP_INFO(this->get_logger(), "Distance sensor node started.");
  }

private:
  void publish_distance()
  {
    sensor_msgs::msg::Range msg;
    msg.header.frame_id = "sensor_frame";
    msg.min_range = 0.1;
    msg.max_range = 2.0;

    std::uniform_real_distribution<float> dist(0.1, 2.0);
    msg.range = dist(rng_);

    publisher_->publish(msg);
    RCLCPP_INFO(this->get_logger(), "Published distance: %.2f m", msg.range);
  }

  rclcpp::Publisher<sensor_msgs::msg::Range>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  std::mt19937 rng_{std::random_device{}()};
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<DistanceSensorNode>());
  rclcpp::shutdown();
  return 0;
}
