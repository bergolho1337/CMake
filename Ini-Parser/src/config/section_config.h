//
// Created by sachetto on 13/10/17.
//

#ifndef MONOALG3D_STIM_CONFIG_H
#define MONOALG3D_STIM_CONFIG_H

#include "config_common.h"

//#define SET_SPATIAL_STIM(name) EXPORT_FN void name(struct config *config, const uint32_t n_active, struct cell_node **ac, const bool adaptive)
//typedef SET_SPATIAL_STIM(set_spatial_stim_fn);

void print_section_config_values (struct config* s);

#endif //MONOALG3D_STIM_CONFIG_H
