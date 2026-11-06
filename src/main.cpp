#include <rclcpp/rclcpp.hpp>
#include "intro_node.hpp"

int main(int argc, char** argv)
{
    rclcpp::init(argc,argv);

    auto node = std::make_shared<IntroNode>();

    RCLCPP_INFO(node->get_logger(),"Hello ROS2");

    rclcpp::spin(node);
    rclcpp::shutdown;
    return 0;
}
