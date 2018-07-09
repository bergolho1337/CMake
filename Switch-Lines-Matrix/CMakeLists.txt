cmake_minimum_required(VERSION 2.8.9)
project(matrix_lines)

include_directories(include)

# The variable CMAKE_BINARY_DIR will be set to ${CMAKE_SOURCE_DIR}/bin
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)

# EXECUTABLE_OUTPUT_PATH is the place where CMake will store the executables
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

file(GLOB SOURCES "src/*.cxx")

add_executable(matrix_lines ${SOURCES})
