cmake_minimum_required(VERSION 3.10)
project(homework1)


include_directories(include/)
add_library(sum src/sum.cpp)
add_library(subtract src/subtract.cpp)
add_executable(main src/main.cpp)
target_link_libraries(main sum subtract)
