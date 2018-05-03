// ------------------------------------------------------------------
// Example that demonstrates the use of the 'getopt.h' library
// It is used to parse command line options
// ------------------------------------------------------------------
// Compile and build:
// $ cmake -H./ -Bbuild
// $ cmake --build build 
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>     // Library used to parse command line options

#define PRINT_LINE "======================================================================"

// List of command line options. If the letter option is follow by a colon them the option requires a an argument.
static const char *opt_string =   "c:d:ah";

static const struct option long_options[] = {
        { "create_file", required_argument, NULL, 'c'},
        { "delete_file", required_argument, NULL, 'd'},
        { "append_file", no_argument, NULL, 'a'},
        { "help", no_argument, NULL, 'h' },
        { NULL, no_argument, NULL, 0 }
};

void Usage (const char pName[])
{
    printf("%s\n",PRINT_LINE);
    printf("Usage:> %s -option\n",pName);
    printf("option =\n");
    printf("\t-c <name_of_file> = create file\n");
    printf("\t-d <name_of_file> = delete file\n");
    printf("\t-a = append file\n");
    printf("\t-h = help\n");
    printf("%s\n",PRINT_LINE);
    exit(EXIT_FAILURE);
    
}

int main (int argc, char *argv[])
{
    int opt;
    int option_index = 0;
    // Get the command line options based on the configured options:
    opt = getopt_long(argc,argv,opt_string,long_options,&option_index);

    while (opt != -1)
    {
        switch (opt)
        {
            case 'c': printf("[+] Creating file '%s' ...\n",optarg);
                      break;
            case 'd': printf("[-] Deleting file '%s' ...\n",optarg);
                      break;
            case 'a': printf("[*] Appending to file ...\n");
                      break;
            case 'h': Usage(argv[0]);
                      break;
            default:  printf("[-] ERROR ! Invalid option\n");
                      break;

        }
        opt = getopt_long(argc,argv,opt_string,long_options,&option_index);
    }

    return 0;
}