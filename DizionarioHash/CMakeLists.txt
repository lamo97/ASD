cmake_minimum_required(VERSION 3.21)
project(DizionarioHash)

set(CMAKE_CXX_STANDARD 11)

add_executable(DizionarioHash TestMain.cpp Dizionario.h LinkedList.h)
