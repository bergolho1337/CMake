#include "functions1.h"

// We use the MACRO for the function pointer and we implement it 
// Double the values of the array
// ** Do not put the 'fn' on the argument **
FUNCTION(sample_function) 
{
    int i;
    for (i = 0; i < n; i++)
        v[i] *= 2.0;
}



