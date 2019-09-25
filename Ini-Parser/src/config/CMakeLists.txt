set(SOURCE_FILES_CONFIG
		config_common.c config_common.h
		section_config.h section_config.c
		config_parser.c config_parser.h)

ADD_LIBRARY(config STATIC ${SOURCE_FILES_CONFIG})

TARGET_LINK_LIBRARIES(config config_helpers string utils dl)

