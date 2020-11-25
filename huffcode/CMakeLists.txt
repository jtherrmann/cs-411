cmake_minimum_required(VERSION 3.17)
project(huffcode)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(huffcode
        huffcode.cpp
        huffcode.hpp
        huffcode_test.cpp)
