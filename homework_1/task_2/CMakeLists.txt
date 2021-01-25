cmake_minimum_required(VERSION 3.10)
project(homework1_task2)

# tell cmake where to look for *.hpp , *.h files
include_directories(include/)

# create library " libipb_arithmetic "
add_library(ipb_arithmetic src/sum.cpp src/subtract.cpp)       # creates libipb_arithmetic.a)

# add executable main
add_executable(main src/main.cpp)

# tell the linker to bind these objects together
target_link_libraries(main ipb_arithmetic)
