# ==================================================================
# This file is responsible for generating the shared libraries
# ==================================================================

SET(LIB_TYPE MODULE) #set the lib type
SET( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/shared_libs )


############## FUNCTIONS 1 ##############################
set(MODEL_FILE_CPU "functions1.c")
set(COMMON_HEADERS model_common.h functions1.h)

ADD_LIBRARY(functions1 ${LIB_TYPE} ${COMMON_HEADERS} ${MODEL_FILE_CPU})

#########################################################

############## FUNCTIONS 2 ##############################
set(MODEL_FILE_CPU "functions2.c")
set(COMMON_HEADERS model_common.h functions2.h)

ADD_LIBRARY(functions2 ${LIB_TYPE} ${COMMON_HEADERS} ${MODEL_FILE_CPU})

#########################################################

############## FUNCTIONS 3 ##############################
set(MODEL_FILE_CPU "functions3.c")
set(COMMON_HEADERS model_common.h functions3.h)

ADD_LIBRARY(functions3 ${LIB_TYPE} ${COMMON_HEADERS} ${MODEL_FILE_CPU})

#########################################################