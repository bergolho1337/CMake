# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)

# Project's name
project(main)

# Add a sub directory where the ini_parser library is implemented
add_subdirectory(ini_parser)

# Add executable 
add_executable(main ${PROJECT_SOURCE_DIR}/main.c)

# Add the dependencies of the main program
add_dependencies(main ini_parser)

# Add the link libraries
target_link_libraries(main ini_parser)

# Set the output folder where your program will be created
# The variable CMAKE_BINARY_DIR will be set to ${CMAKE_SOURCE_DIR}/bin
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)

# EXECUTABLE_OUTPUT_PATH is the place where CMake will store the executables
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
