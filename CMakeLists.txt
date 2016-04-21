cmake_minimum_required(VERSION 3.5)
project(pi_trees)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES pi_trees_lib/headers/TaskStatus.h pi_trees_lib/Task.cpp pi_trees_lib/headers/Task.h pi_trees_lib/Sequence.cpp pi_trees_lib/headers/Sequence.h main.cpp pi_trees_lib/Selector.cpp pi_trees_lib/headers/Selector.h pi_trees_lib/ParallelOne.cpp pi_trees_lib/headers/ParallelOne.h pi_trees_lib/ParallelAll.cpp pi_trees_lib/headers/ParallelAll.h pi_trees_lib/Loop.cpp pi_trees_lib/headers/Loop.h pi_trees_lib/Iterator.cpp pi_trees_lib/headers/Iterator.h pi_trees_lib/IgnoreFailure.cpp pi_trees_lib/headers/IgnoreFailure.h pi_trees_lib/AutoRemoveSequence.cpp pi_trees_lib/headers/AutoRemoveSequence.h pi_trees_ros/MonitorTask.cpp pi_trees_ros/headers/MonitorTask.h pi_trees_ros/ServiceClientTask.cpp pi_trees_ros/headers/ServiceClientTask.h pi_trees_ros/ActionClientTask.cpp pi_trees_ros/headers/ActionClientTask.h)
add_executable(pi_trees ${SOURCE_FILES})