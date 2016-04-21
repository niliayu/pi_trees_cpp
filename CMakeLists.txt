cmake_minimum_required(VERSION 2.8.3)
project(ros_trees_cpp)

find_package(catkin_simple REQUIRED)
find_package(Boost REQUIRED COMPONENTS system thread)
catkin_simple()

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

cs_add_executable(ros_trees_cpp src/ActionClientTask.cpp)
cs_add_executable(ros_trees_cpp src/MonitorTask.cpp)
cs_add_executable(ros_trees_cpp src/ServiceClientTask.cpp)

cs_install()
cs_export()
    