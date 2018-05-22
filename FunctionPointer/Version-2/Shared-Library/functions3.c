#include "functions3.h"

// Quadriple the values of the array
FUNCTION(sample_function) 
{
    int i;
    for (i = 0; i < n; i++)
        v[i] *= 4.0;
}