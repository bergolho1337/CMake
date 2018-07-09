#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <getopt.h>

int main(int argc, char **argv)
{
    enum {
        RO_OPT = 0,
        RW_OPT,
        NAME_OPT
    };
    char *const token[] = {
        [RO_OPT]   = "ro",
        [RW_OPT]   = "rw",
        [NAME_OPT] = "name",
        NULL
    };
    char *subopts;
    char *value;
    int opt;

    int readonly = 0;
    int readwrite = 0;
    char *name = NULL;
    int errfnd = 0;

    while ((opt = getopt(argc, argv, "o:")) != -1) 
    {
        switch (opt) 
        {
            case 'o':
                subopts = optarg;
                while (*subopts != '\0' && !errfnd) 
                {
                    switch (getsubopt(&subopts, token, &value)) 
                    {
                        case RO_OPT:
                        readonly = 1;
                        break;

                        case RW_OPT:
                            readwrite = 1;
                            break;

                        case NAME_OPT:
                            if (value == NULL) 
                            {
                                fprintf(stderr, "Missing value for "
                                        "suboption '%s'\n", token[NAME_OPT]);
                                errfnd = 1;
                                continue;
                            }

                        name = value;
                        break;

                        default:
                            fprintf(stderr, "No match found "
                                    "for token: /%s/\n", value);
                            errfnd = 1;
                            break;
                    }
                }
                if (readwrite && readonly) 
                {
                    fprintf(stderr, "Only one of '%s' and '%s' can be "
                            "specified\n", token[RO_OPT], token[RW_OPT]);
                    errfnd = 1;
                }
            break;

            default:
                errfnd = 1;
        }
    }

    if (errfnd || argc == 1) 
    {
        fprintf(stderr, "\nUsage: %s -o <suboptstring>\n", argv[0]);
        fprintf(stderr, "suboptions are 'ro', 'rw', "
                "and 'name=<value>'\n");
        exit(EXIT_FAILURE);
    }

    /* Remainder of program... */

    exit(EXIT_SUCCESS);
}