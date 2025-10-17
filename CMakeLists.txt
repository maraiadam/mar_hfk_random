cmake_minimum_required(VERSION 3.8)
project(collision_alert_pkg)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)

set(ament_dependencies
  rclcpp
  sensor_msgs
  std_msgs
)

add_executable(distance_sensor_node src/distance_sensor_node.cpp)
ament_target_dependencies(distance_sensor_node ${ament_dependencies} )
add_executable(collision_alert_node src/collision_alert_node.cpp)
ament_target_dependencies(collision_alert_node ${ament_dependencies} )

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})

install(TARGETS
  distance_sensor_node
  collision_alert_node
  DESTINATION lib/${collision_alert_pkg})

install(DIRECTORY launch
  DESTINATION share/${collision_alert_pkg}/)
  
ament_package()