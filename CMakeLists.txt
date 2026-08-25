cmake_minimum_required(VERSION 3.10)
project(CSC1060_Capstone_Project CXX)

set(CMAKE_CXX_STANDARD 17)
find_package(SDL2 REQUIRED CONFIG)
add_executable(program_output main.cpp)

target_link_libraries(CSC1060_Capstone_Project PRIVATE SDL2::SDL2 SDL2::SDL2main)
