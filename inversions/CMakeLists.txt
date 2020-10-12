cmake_minimum_required(VERSION 3.17)
project(inversions)

set(CMAKE_CXX_STANDARD 17)

add_executable(inversions
        inversions_test.cpp inversions.hpp)
