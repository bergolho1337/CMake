cmake_minimum_required(VERSION 2.8.9)
project(VTK_Output)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

FIND_PACKAGE(VTK REQUIRED)
INCLUDE(${VTK_USE_FILE})

ADD_EXECUTABLE(VTK_Output vtk_output.cxx main.cxx)

TARGET_LINK_LIBRARIES(VTK_Output ${VTK_LIBRARIES})
 
