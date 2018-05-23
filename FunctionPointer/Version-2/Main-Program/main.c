// ----------------------------------------------------------------------------
// This program demonstrates how to load a Dynamic Loaded Library (.so)
// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "../Shared-Library/model_common.h"
#include <dlfcn.h>      // We need to link this library during compilation

void fillVector (double *v, const int N)
{
    int i;
    for (i = 0; i < N; i++)
        v[i] = i+1;
}

void printVector (double *v, const int N)
{
    int i;
    for (i = 0; i < N; i++)
        printf("%.2lf ",v[i]);
    printf("\n");
}

// Try open a shared library by the given path
// On sucess returns a pointer to the handle of the function
void* open_shared_library (const char library_path[])
{
    printf("[+] Opening shared library %s ...\n",library_path);
    void *handle = dlopen (library_path, RTLD_LAZY);
    if (!handle) 
    {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }
    return handle;
}

int main ()
{
    const int N = 5;

    double *v1 = (double*)malloc(sizeof(double)*N);
    double *v2 = (double*)malloc(sizeof(double)*N);
    double *v3 = (double*)malloc(sizeof(double)*N);

    fillVector(v1,N);
    fillVector(v2,N);
    fillVector(v3,N);
    
    printf("Array 1\n");
    printVector(v1,N);
    printf("Array 2\n");
    printVector(v2,N);
    printf("Array 3\n");
    printVector(v3,N);

    // Handle to the DL library file
    // Pass the path to shared_libs folder
    void *handle;
    sample_function_fn **func_array = (sample_function_fn**)malloc(sizeof(sample_function_fn*)*3);
    handle = open_shared_library("../Shared-Library/shared_libs/libfunctions1.so");

    func_array[0] = dlsym(handle, "sample_function");

    handle = open_shared_library("../Shared-Library/shared_libs/libfunctions2.so");
    func_array[1] = dlsym(handle, "sample_function");

    handle = open_shared_library("../Shared-Library/shared_libs/libfunctions3.so");
    func_array[2] = dlsym(handle, "sample_function");

    // Use the same function pointer as defined on the 'model_common' header file
    //sample_function_fn *func1 = dlsym(handle, "sample_function");

    //handle = open_shared_library("../Shared-Library/shared_libs/libfunctions2.so");
    //sample_function_fn *func2 = dlsym(handle, "sample_function");

    //handle = open_shared_library("../Shared-Library/shared_libs/libfunctions3.so");
    //sample_function_fn *func3 = dlsym(handle, "sample_function");

    // Call the function through the function pointer
    fprintf(stdout,"[!] Calling function 1 (double)\n");
    //func1(v1,N);
    func_array[0](v1,N);
    printVector(v1,N);

    fprintf(stdout,"[!] Calling function 2 (triple)\n");
    //func2(v2,N);
    func_array[1](v2,N);
    printVector(v2,N);

    fprintf(stdout,"[!] Calling function 3 (quadruple)\n");
    //func3(v3,N); 
    func_array[2](v3,N);
    printVector(v3,N);

    free(v1);
    free(v2);
    free(v3);
    free(func_array);

    return 0;
}