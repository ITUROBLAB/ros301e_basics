#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class SmartphoneNode : public rclcpp::Node
{
public:
    SmartphoneNode()
    : Node("smartphone_node")
    {
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "/robot_news",
            1000,
            std::bind(&SmartphoneNode::callbackReceiveRadioData,
                      this,
                      std::placeholders::_1));
    }

private:
    void callbackReceiveRadioData(
        const std_msgs::msg::String::SharedPtr msg) const
    {
        RCLCPP_INFO(this->get_logger(),
                    "Message received: %s",
                    msg->data.c_str());
    }

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::spin(std::make_shared<SmartphoneNode>());

    rclcpp::shutdown();
    return 0;
}