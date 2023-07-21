# cmake_minimum_required(VERSION <specify CMake version here>)
cmake_minimum_required(VERSION 3.25)

project(Algorithm)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(BAEKJOON)
include_directories(PROGRAMMERS)

add_executable(out BAEKJOON/Basic/1016.cpp)
