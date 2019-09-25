// ------------------------------------------------------------------
// Example that demonstrates the use of the 'ini.h' library
// It is used to read a file on the INI format
// ------------------------------------------------------------------
// Compile and build:
// $ ./recompile_project.sh
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ini_parser/ini.h"
#include "string/sds.h"
#include "utils/file_utils.h"
#include "config_helpers/config_helpers.h"
#include "config/config_parser.h"

#define PRINT_LINE "======================================================================"

/*
// Structure that stores the User configurations
struct user_options
{
    double dt;
    double tmax;
    char output_file[100];
    char extra_file[100];
}typedef user_options;

// Print the usage
void Usage (const char pName[])
{
    printf("%s\n",PRINT_LINE);
    printf("Usage:> %s <input_file.ini>\n",pName);
    printf("<input_file.ini> = Input file on the INI format\n");
    printf("%s\n",PRINT_LINE);
    exit(EXIT_FAILURE);
    
}

// Parse function that needs to be implemented by the user
int parse_config_file (void *user, const char *section, const char *name, const char *value)
{
    user_options *pconfig = (user_options*) user;

    // Check the section and the name from each line and parse value to the appropriate type
    if (MATCH_SECTION_AND_NAME(MAIN_SECTION,"dt"))
        pconfig->dt = strtod(value,NULL);
    else if (MATCH_SECTION_AND_NAME(MAIN_SECTION,"tmax"))
        pconfig->tmax = strtod(value,NULL);
    else if (MATCH_SECTION_AND_NAME(MAIN_SECTION,"output_file"))
        strcpy(pconfig->output_file,value);
    else if (MATCH_SECTION_AND_NAME(EXTRA_DATA_SECTION,"extra_file"))
        strcpy(pconfig->extra_file,value);
    else
        fprintf(stderr, "Invalid name %s in section %s on the config file!\n", name, section);
}
*/

int main (int argc, char *argv[])
{

    struct user_options *options = new_user_options();

    get_config_file(argc,argv,options);

    if(options->config_file) 
    {
        // Here we parse the config file
        if(ini_parse(options->config_file, parse_config_file, options) < 0) 
        {
            fprintf(stderr, "Error: Can't load the config file %s\n", options->config_file);
            exit(EXIT_FAILURE);
        }
    }
    else 
    {
        fprintf(stderr, "\nError: The config file is mandatory.\n\n");
        display_usage(argv);
        exit(EXIT_FAILURE);
    }    

    print_info_options(options);

    free_user_options(options);

    return 0;
}