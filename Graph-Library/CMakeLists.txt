cmake_minimum_required(VERSION 2.8.9)
project(Graph)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
SET(CMAKE_C_STANDARD 99)

ADD_EXECUTABLE(Graph graph.c main.c)

TARGET_LINK_LIBRARIES(Graph m)
 
