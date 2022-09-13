cmake_minimum_required(VERSION 3.17)
project(TSLAM)

set(CMAKE_CXX_STANDARD 20)

add_executable(TSLAM main.cpp src/frame.cpp)