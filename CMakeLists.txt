cmake_minimum_required(VERSION 3.0.2)
project(ssg_test)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package(
  LIBRARIES ssg_test
  CATKIN_DEPENDS roscpp std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(manipulator_test src/manipulator_test.cpp)
add_dependencies(manipulator_test ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(manipulator_test ${catkin_LIBRARIES})
