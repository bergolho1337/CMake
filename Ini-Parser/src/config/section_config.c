//
// Created by sachetto on 13/10/17.
//

#include "section_config.h"
#include <dlfcn.h>
#include "../utils/file_utils.h"

#include "../single_file_libraries/stb_ds.h"
#include "../config_helpers/config_helpers.h"

void print_section_config_values(struct config* s) 
{

    if(s == NULL) {
        print_to_stdout_and_file("No Section configuration.\n");
        return;
    }
    
    struct string_hash_entry *tmp = s->config_data;

    if(shlen(tmp) == 1)
    {
        print_to_stdout_and_file("Section parameter:\n");
    }
    else if(shlen(tmp)  > 1)
    {
        print_to_stdout_and_file("Section parameters:\n");
    }

    STRING_HASH_PRINT_KEY_VALUE_LOG(tmp);

}