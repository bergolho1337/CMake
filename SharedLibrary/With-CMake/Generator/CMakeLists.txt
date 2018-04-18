# ***********************************************************************************************
# Example for building a shared library
# ----------------------------------------------------------------------------------------------
# A shared library ... 
# ***********************************************************************************************

cmake_minimum_required(VERSION 2.8.9)
project(shared)

# Set the CMake build type to be a Release
set(CMAKE_BUILD_TYPE Release)

# Bring the headers into the project
include_directories()

# Include on the SOURCE variable all the source files
file(GLOB SOURCES "*.c")

# Generate the shared library from the sources
add_library(shared SHARED ${SOURCES})

# Set the location of the library installation -- i.e /usr/lib 
# Use "sudo make install" to apply
install(TARGETS shared DESTINATION /usr/lib)  

