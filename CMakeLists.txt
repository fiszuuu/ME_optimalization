cmake_minimum_required(VERSION 3.17)
project(metalsheet.cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(metalsheet metalsheet.cpp classes.h tests.h)
