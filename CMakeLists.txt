cmake_minimum_required(VERSION 2.8.3)
project(ros_trees_cpp)

find_package(catkin_simple REQUIRED)
find_package(Boost REQUIRED COMPONENTS system thread)
catkin_simple()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

cs_add_library(task src/Task.cpp)
cs_add_library(auto_remove_sequence src/AutoRemoveSequence.cpp)
cs_add_library(ignore_failure src/IgnoreFailure.cpp)
cs_add_library(iterator src/Iterator.cpp)
cs_add_library(loop src/Loop.cpp)
cs_add_library(parallel_all src/ParallelAll.cpp)
cs_add_library(parallel_one src/ParallelOne.cpp)
cs_add_library(selector src/Selector.cpp)
cs_add_library(sequence src/Sequence.cpp)
cs_add_library(callbacktask src/CallbackTask.cpp)

#cs_add_executable(action_client_task src/ActionClientTask.cpp)
#cs_add_executable(monitor_task src/MonitorTask.cpp)
#cs_add_executable(service_client_task src/ServiceClientTask.cpp)
cs_add_executable(patrol_tree src/patrol_tree.cpp)

target_link_libraries(patrol_tree task)

cs_install()
cs_export()
    