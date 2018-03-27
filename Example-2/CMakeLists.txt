cmake_minimum_required(VERSION 2.8.9)
project(directory_example)

# Bring the headers into the project
include_directories(include)

# Can manually add the source files using the SET command 
# set(SOURCES src/main.cpp src/Student.cpp)

# However, we could achieve the same using the FILE command with a wildcard
# This will include all the files on the /src folder that has the .cpp extension
file(GLOB SOURCES "src/*.cpp")

add_executable(testStudent ${SOURCES}) 