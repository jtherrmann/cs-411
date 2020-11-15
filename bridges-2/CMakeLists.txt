cmake_minimum_required(VERSION 3.17)
project(bridges_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(bridges_2
        build.hpp
        build_test2.cpp build.cpp)
