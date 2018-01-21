cmake_minimum_required(VERSION 3.9)
project(MachineLearning)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

if ("$ENV{DEBUG_MODE}" STREQUAL "true")
    set(CMAKE_BUILD_TYPE Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    MESSAGE(STATUS "Executing Code Coverage...")
endif()

add_subdirectory(src)
add_subdirectory(tests)

add_executable(main read_minst_main.cpp)

target_link_libraries(main moriorgames_ml)
