cmake_minimum_required(VERSION 2.6)
project(fmt CXX)

set(CMAKE_CXX_COMPILER clang++)
add_definitions(-std=c++11)

add_executable(test test.cpp)
add_executable(usage usage.cpp)