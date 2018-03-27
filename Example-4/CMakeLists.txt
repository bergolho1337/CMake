# ***********************************************************************************************
# Example for building a static library
# ----------------------------------------------------------------------------------------------
# A statically-linked library is created at compile time to contain all of the code code 
# relating the library — essentially it makes copies of any dependency code, including that 
# in other libraries. 
# -----------------------------------------------------------------------------------------------
# To debug a static library we could use the 'nm' command to print the list of symbols from
# object and binary files.
# ***********************************************************************************************

cmake_minimum_required(VERSION 2.8.9)
project(directory_test)

# Set the CMake build type to be a Release
set(CMAKE_BUILD_TYPE Release)

# Bring the headers into the project
include_directories(include)

# Include on the SOURCE variable all the files on the /src folder that has the .cpp extension
file(GLOB SOURCES "src/*.cpp")

# Generate the static library from the sources
add_library(testStudent STATIC ${SOURCES})

# Set the location of the library installation -- i.e /usr/lib 
# Use "sudo make install" to apply
install(TARGETS testStudent DESTINATION /usr/lib)  

