cmake_minimum_required(VERSION 2.6)
project(fmt CXX)

add_definitions(--std=c++0x)

add_executable(test test.cpp)
add_executable(usage usage.cpp)
add_executable(usage_custom usage_custom.cpp)
add_executable(test_static test_static.cpp)
