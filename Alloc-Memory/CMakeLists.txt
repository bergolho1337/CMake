# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)

# Project's name

project(main)

# Include header file
#include(functionpointer)

# Set the output folder where your program will be created

# The variable CMAKE_BINARY_DIR will be set to ${CMAKE_SOURCE_DIR}/bin
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)

# EXECUTABLE_OUTPUT_PATH is the place where CMake will store the executables
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")

# Add executable 
add_executable(main ${PROJECT_SOURCE_DIR}/main.c)