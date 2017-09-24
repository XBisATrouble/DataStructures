cmake_minimum_required(VERSION 3.7)
project(skipList)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SkipList.cpp SkipList.h)
add_executable(skipList ${SOURCE_FILES})