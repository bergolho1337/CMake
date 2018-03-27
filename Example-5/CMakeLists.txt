# ***********************************************************************************************
# Example of using a shared library
# ----------------------------------------------------------------------------------------------
#  
# -----------------------------------------------------------------------------------------------
# ***********************************************************************************************

cmake_minimum_required(VERSION 2.8.9)
project(TestLibrary)

# Add the folder of the shared library
set(PROJECT_LINK_LIBS libtestStudent.so)
link_directories(~/Documentos/Github/CMake/Example-3/build)
include_directories(~/Documentos/Github/CMake/Example-3/include)

# Generate the executable from the sources and linking with the library
add_executable(libtest libtest.cpp)
target_link_libraries(libtest ${PROJECT_LINK_LIBS})
    