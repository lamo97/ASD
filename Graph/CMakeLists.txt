cmake_minimum_required(VERSION 3.21)
project(Graph)

set(CMAKE_CXX_STANDARD 11)

add_executable(Graph TestMain.cpp Graph.h LinkedList.h Queue.h)
