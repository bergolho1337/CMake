SET(LIB_TYPE MODULE) #set the lib type

############## TEN TUSCHER 2006 ##############################
set(MODEL_FILE_CPU "library_1.cpp")
set(COMMON_HEADERS model_common.h library_1.h)

ADD_LIBRARY(library_1 ${LIB_TYPE} ${COMMON_HEADERS} ${MODEL_FILE_CPU})
#########################################################

############## TEN TUSCHER 2006 ##############################
set(MODEL_FILE_CPU "library_2.cpp")
set(COMMON_HEADERS model_common.h library_2.h)

ADD_LIBRARY(library_2 ${LIB_TYPE} ${COMMON_HEADERS} ${MODEL_FILE_CPU})
#########################################################