/*
    Example that demonstrate the usage of Dinamically Loaded Libraries. 
    
    Compilation:
        $ gcc -o foo foo.c -ldl
    Execution:
        $ ./foo

*/

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>      // We need to link this library during compilation

int main ()
{
    // Handle to the DL library file
    void *handle;

    // Function pointer that receives a double and returns a double
    double (*cosine) (double);
    double (*power) (double,double);

    char *error;

    // Open the mathematical library using the LAZY flag, which means
    // "Resolve undefined symbols as code from the dynamic library is executed"
    handle = dlopen("/usr/lib64/libm.so.6",RTLD_LAZY);
    if (!handle)
    {
        fputs(dlerror(),stderr);
        exit(1);
    }

    // Here, we search for the function that calculates the cosine of x 
    // And we store the handle to that function on the pointer *cosine
    cosine = dlsym(handle,"cos");
    if ((error = dlerror()) != NULL)
    {
        fputs(error,stderr);
        exit(1);
    }

    // Here, we search for the function that calculates the power of x 
    // And we store the handle to that function on the pointer *cosine
    power = dlsym(handle,"pow");
    if ((error = dlerror()) != NULL)
    {
        fputs(error,stderr);
        exit(1);
    }

    // Now, we use the function pointers from the shared library
    printf("%f\n",(*cosine)(2.0));
    printf("%f\n",(*power)(2.0,4.0));

    dlclose(handle);

    return 0;
}