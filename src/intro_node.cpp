#include "intro_node.hpp"
#include <chrono>
#include <functional>

using namespace std::chrono_literals;

// 构造函数
IntroNode::IntroNode() : Node("intro_node")
{
    // 1. 造喇叭（发布者）
    publisher_ = this->create_publisher<std_msgs::msg::String>("intro/out", 10);

    // 2. 造耳朵（订阅者）：收到消息后，交给 topic_callback 处理
    // std::bind 的作用是把类的成员函数打包成底层可以调用的格式
    subscription_ = this->create_subscription<std_msgs::msg::String>(
        "intro/in", 10, 
        std::bind(&IntroNode::topic_callback, this, std::placeholders::_1)
    );

    // 3. 造闹钟（定时器）：每 1 秒执行一次 timer_callback
    timer_ = this->create_wall_timer(
        1s, 
        std::bind(&IntroNode::timer_callback, this)
    );
}

// 定时器回调函数
void IntroNode::timer_callback()
{
    counter_++;
    auto message = std_msgs::msg::String();
    message.data = "My_ID: " + std::to_string(counter_);
    publisher_->publish(message);
    
    // 打印一下证明发了
    RCLCPP_INFO(this->get_logger(), "Sending: '%s'", message.data.c_str());
}

// 订阅者回调函数
void IntroNode::topic_callback(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "Received: '%s'", msg->data.c_str());
}