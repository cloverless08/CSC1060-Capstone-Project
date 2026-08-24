cmake_minimum_required(VERSION 3.10)
project(CSC1060_Capstone_Project CXX)

set(CMAKE_CXX_STANDARD 17)

# 1. Locate the GLFW3 package on your system
find_package(glfw3 3.3 REQUIRED)

# 2. Define your executable target
add_executable(CSC1060_Capstone_Project main.cpp)

# 3. Link the GLFW library to your executable
target_link_libraries(CSC1060_Capstone_Project PRIVATE glfw)
