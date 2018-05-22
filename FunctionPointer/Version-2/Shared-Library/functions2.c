#include "functions2.h"

// Triple the values of the array
FUNCTION(sample_function) 
{
    int i;
    for (i = 0; i < n; i++)
        v[i] *= 3.0;
}