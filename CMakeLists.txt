cmake_minimum_required(VERSION 3.25)
project(cplusplus)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(cplusplus
         main.cpp Account.h Account.cpp Account.cpp)
