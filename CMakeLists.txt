cmake_minimum_required(VERSION 3.5)
project(pi_trees)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES TaskStatus.h Task.cpp Task.h Sequence.cpp Sequence.h main.cpp)
add_executable(pi_trees ${SOURCE_FILES})