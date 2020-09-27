cmake_minimum_required(VERSION 3.17)
project(bridges)

set(CMAKE_CXX_STANDARD 14)

add_executable(bridges
        build_test.cpp build.cpp build.h)
