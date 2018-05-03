// ------------------------------------------------------------------
// Example that demonstrates the use of the 'ini.h' library
// It is used to read a file on the INI format
// ------------------------------------------------------------------
// Compile and build:
// $ cmake -H./ -Bbuild
// $ cmake --build build 
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ini_parser/ini.h"
#include "ini_parser/ini_file_sections.h"

#define PRINT_LINE "======================================================================"

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

int main (int argc, char *argv[])
{
    // Check if the user do not pass the INI file
    if (argc-1 != 1)
        Usage(argv[0]);
    
    // Allocate the user_options structure
    user_options *options = (user_options*)malloc(sizeof(user_options));
    
    // To parse the INI file we need to pass the path to the file, a user-defined parse function 
    // and a structure to store the variables from the INI file
    if (ini_parse(argv[1],parse_config_file,options) < 0) 
    {
        fprintf (stderr, "Error: Can't load the config file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    printf("%s\n",PRINT_LINE);
    printf("dt = %lf\n",options->dt);
    printf("tmax = %lf\n",options->tmax);
    printf("output_file = %s\n",options->output_file);
    printf("extra_file = %s\n",options->extra_file);
    printf("%s\n",PRINT_LINE);

    free(options);

    return 0;
}