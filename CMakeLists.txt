cmake_minimum_required(VERSION 3.9)
project(MachineLearning)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})

MESSAGE(STATUS "Armadillo libraries: ${ARMADILLO_LIBRARIES}")

add_subdirectory(src)
add_subdirectory(tests)

add_executable(main main.cpp)

target_link_libraries(main moriorgames_ml)
target_link_libraries(main ${ARMADILLO_LIBRARIES})
