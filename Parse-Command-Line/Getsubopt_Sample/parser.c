#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <getopt.h>

int main(int argc, char **argv)
{
    char *const token[] = {
        [0]   = "ro",
        [1]   = "rw",
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
                printf("subopts = %s\n",subopts);
                while (*subopts != '\0' && !errfnd) 
                {
                    int subopt = getsubopt(&subopts, token, &value); 
                    //printf("\tSuboption = %d\n",subopt);
                }
                break;

            default:
                fprintf(stderr,"ERROR\n");
        }
    }

    exit(EXIT_SUCCESS);
}