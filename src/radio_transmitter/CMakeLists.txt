cmake_minimum_required(VERSION 3.8)
project(radio_transmitter)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(talker_node src/talker_node.cpp)
add_executable(radio_transmitter_node src/radio_transmitter_node.cpp)
add_executable(smartphone_node src/smartphone_node.cpp)

target_include_directories(talker_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_include_directories(radio_transmitter_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_include_directories(smartphone_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(talker_node PUBLIC c_std_99 cxx_std_17)
target_compile_features(radio_transmitter_node PUBLIC c_std_99 cxx_std_17)
target_compile_features(smartphone_node PUBLIC c_std_99 cxx_std_17)

install(TARGETS talker_node radio_transmitter_node smartphone_node DESTINATION lib/${PROJECT_NAME})

ament_target_dependencies(radio_transmitter_node rclcpp std_msgs)
ament_target_dependencies(smartphone_node rclcpp std_msgs)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
