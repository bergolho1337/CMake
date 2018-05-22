#ifndef MODEL_COMMON_H
#define MODEL_COMMON_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

// Define this variable in order to export properly the function
#define EXPORT_FN

// TEMPLATE OF THE FUNCTION
#define FUNCTION(name) EXPORT_FN void name (double *v, int n)
typedef FUNCTION(sample_function_fn);

#endif
