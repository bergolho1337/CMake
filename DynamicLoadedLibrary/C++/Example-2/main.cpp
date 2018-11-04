#include <iostream>
#include <dlfcn.h>
#include "models_library/model_common.h"

using namespace std;

int main ()
{
    // Opening shared library
    void *handle = dlopen ("shared_libs/liblibrary_2.so", RTLD_LAZY);
    if (!handle) 
    {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }
    char *error;
    get_simple_function_fn *simple_function_pointer = (get_simple_function_fn*)dlsym(handle,"get_simple_function");
    if ((error = dlerror()) != NULL)  
    {
        fprintf(stderr, "%s\n", error);
        fprintf(stderr, "Function not found in the provided model library\n");
        return 1;
    }
    do_calculation_fn *do_calculation_pointer = (do_calculation_fn*)dlsym(handle,"do_calculation");
    if ((error = dlerror()) != NULL)  
    {
        fprintf(stderr, "%s\n", error);
        fprintf(stderr, "Function not found in the provided model library\n");
        return 1;
    }
    simple_function_pointer();
    cout << do_calculation_pointer(2.0) << endl;
}