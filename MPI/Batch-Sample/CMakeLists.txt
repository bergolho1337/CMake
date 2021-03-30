cmake_minimum_required(VERSION 2.8)

PROJECT(mpi_batch)

# Require MPI for this project:
FIND_PACKAGE(MPI REQUIRED)
if (MPI_FOUND)
    INCLUDE_DIRECTORIES(${MPI_INCLUDE_PATH})
else ()
    MESSAGE("MPI library not found")
endif()

SET(CMAKE_CXX_COMPILE_FLAGS ${CMAKE_CXX_COMPILE_FLAGS} ${MPI_COMPILE_FLAGS})
SET(CMAKE_CXX_LINK_FLAGS ${CMAKE_CXX_LINK_FLAGS} ${MPI_LINK_FLAGS})
SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin )

if (MPI_FOUND)
    ADD_EXECUTABLE(mpi_batch mpi_batch.c)
    ADD_EXECUTABLE(serial serial.c)
else ()
    ADD_EXECUTABLE(serial serial.c)
endif()

if (MPI_FOUND)
    TARGET_LINK_LIBRARIES(mpi_batch ${MPI_LIBRARIES} m)
    TARGET_LINK_LIBRARIES(serial m)    
else ()
    TARGET_LINK_LIBRARIES(serial m)
endif()
