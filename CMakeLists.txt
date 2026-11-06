cmake_minimum_required(VERSION 3.8)
project(pubsub_intro)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(include)
add_executable(intro_node src/main.cpp src/intro_node.cpp)

ament_target_dependencies(intro_node rclcpp std_msgs)

install(TARGETS intro_node
DESTINATION lib/${PROJECT_NAME}
)

ament_package()