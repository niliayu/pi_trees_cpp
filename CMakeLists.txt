cmake_minimum_required(VERSION 3.5)
project(pi_trees)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES TaskStatus.h Task.cpp Task.h Sequence.cpp Sequence.h main.cpp Selector.cpp Selector.h ParallelOne.cpp ParallelOne.h ParallelAll.cpp ParallelAll.h Loop.cpp Loop.h Iterator.cpp Iterator.h)
add_executable(pi_trees ${SOURCE_FILES})