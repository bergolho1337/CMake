cmake_minimum_required(VERSION 2.8.9)
project(Graph)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(Graph src/graph.cpp main.cpp)

TARGET_LINK_LIBRARIES(Graph m)
