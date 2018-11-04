#include "library_1.h"

extern "C" GET_SIMPLE_FUNCTION(get_simple_function) 
{
    printf("Library 1 here!\n");
}

extern "C" DO_CALCULATION_FUNCTION(do_calculation) 
{
    return x*x;
}