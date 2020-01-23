cmake_minimum_required(VERSION 3.15)
project(2048)

set(CMAKE_CXX_STANDARD 20)

add_executable(2048 main.cpp main.h mechanics.cpp UI.cpp)
set(CMAKE_CXX_FLAGS "-lncurses")