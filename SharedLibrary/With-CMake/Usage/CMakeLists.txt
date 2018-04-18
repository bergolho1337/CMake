# ***********************************************************************************************
# Example of using a shared library
# ***********************************************************************************************

cmake_minimum_required(VERSION 2.8.9)
project(main)

# Add the folder of the shared library
set(PROJECT_LINK_LIBS libshared.so)
link_directories(~/Documentos/Github/CMake/SharedLibrary/With-CMake/Generator)
include_directories(~/Documentos/Github/CMake/SharedLibrary/With-CMake/Generator)

# Generate the executable from the sources and linking with the library
add_executable(main main.c)
target_link_libraries(main ${PROJECT_LINK_LIBS})
    