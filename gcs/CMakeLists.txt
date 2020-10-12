cmake_minimum_required(VERSION 3.17)
project(gcs)

set(CMAKE_CXX_STANDARD 17)

add_executable(gcs
        contigsum_test.cpp contigsum.hpp)
