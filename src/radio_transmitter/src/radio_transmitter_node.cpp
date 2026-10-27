#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class RadioTransmitterNode : public rclcpp::Node
{
public:
    RadioTransmitterNode()
    : Node("radio_transmitter_node")
    {
        publisher_ = this->create_publisher<std_msgs::msg::String>(
            "/robot_news", 10);

        timer_ = this->create_wall_timer(
            333ms,   // ~3 Hz
            std::bind(&RadioTransmitterNode::publishMessage, this));
    }

private:
    void publishMessage()
    {
        auto msg = std_msgs::msg::String();
        msg.data = "ITU – Programming Techniques for Robotics Course";

        publisher_->publish(msg);

        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", msg.data.c_str());
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::spin(std::make_shared<RadioTransmitterNode>());

    rclcpp::shutdown();
    return 0;
}
