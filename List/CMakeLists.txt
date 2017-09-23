cmake_minimum_required(VERSION 3.7)
project(List)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MyList.cpp MyList.h)
add_executable(List ${SOURCE_FILES})