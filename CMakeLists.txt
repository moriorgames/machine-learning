cmake_minimum_required(VERSION 3.9)
project(MachineLearning)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_executable(
        main
        main.cpp
)
