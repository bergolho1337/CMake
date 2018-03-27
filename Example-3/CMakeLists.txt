# ***********************************************************************************************
# Example for building a shared library
# ----------------------------------------------------------------------------------------------
# A shared library ... 
# ***********************************************************************************************

cmake_minimum_required(VERSION 2.8.9)
project(directory_test)

# Set the CMake build type to be a Release
set(CMAKE_BUILD_TYPE Release)

# Bring the headers into the project
include_directories(include)

# Include on the SOURCE variable all the files on the /src folder that has the .cpp extension
file(GLOB SOURCES "src/*.cpp")

# Generate the shared library from the sources
add_library(testStudent SHARED ${SOURCES})

# Set the location of the library installation -- i.e /usr/lib 
# Use "sudo make install" to apply
install(TARGETS testStudent DESTINATION /usr/lib)  

