//
// Created by sachetto on 05/10/17.
//

// Every model need to implement the functions described in this model file in order to be loaded correctly from the
// edo solver. This models_library should compile without using any dependency of our codebase

#ifndef MONOALG3D_MODEL_COMMON_H
#define MONOALG3D_MODEL_COMMON_H

#define EXPORT_FN

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define GET_SIMPLE_FUNCTION(name) EXPORT_FN void name ()
typedef GET_SIMPLE_FUNCTION (get_simple_function_fn);

#define DO_CALCULATION_FUNCTION(name) EXPORT_FN double name (const double x)
typedef DO_CALCULATION_FUNCTION (do_calculation_fn);


#endif // MONOALG3D_MODEL_COMMON_H