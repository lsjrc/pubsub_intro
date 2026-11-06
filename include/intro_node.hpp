#ifndef INTRO_NODE_HPP
#define INTRO_NODE_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

class IntroNode : public rclcpp::Node
{
public:
    IntroNode();

private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    rclcpp::TimerBase::SharedPtr timer_;
    int counter_ = 0;
    void timer_callback();
    void topic_callback(const std_msgs::msg::String::SharedPtr msg);
};

#endif