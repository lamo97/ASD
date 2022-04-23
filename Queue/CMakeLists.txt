cmake_minimum_required(VERSION 3.21)
project(Queue)

set(CMAKE_CXX_STANDARD 11)

add_executable(Queue TestMain.cpp Queue.h Queue.cpp)
