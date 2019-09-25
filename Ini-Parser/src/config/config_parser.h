/*
 * opts.h
 *
 *  Created on: 27/05/2011
 *      Author: sachetto
 */

#ifndef MONOALG3D_CONFIG_PARSER_H
#define MONOALG3D_CONFIG_PARSER_H

#include <getopt.h>

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//#include "domain_config.h"
#include "../common_types/common_types.h"

#define START_REFINING 1700
#define DOMAIN_OPT 1800
#define EXTRA_DATA_OPT 1900
#define STIM_OPT 2000
#define ASSEMBLY_MATRIX_OPT 2100
#define LINEAR_SYSTEM_SOLVER_OPT 2200
#define UPDATE_MONODOMAIN_SOLVER_OPT 2300
#define DRAW_OPT 3000
#define SAVE_OPT 3100
#define SAVE_STATE_OPT 3200
#define RESTORE_STATE_OPT 3300
#define MAX_V_OPT 3400
#define MIN_V_OPT 3500
#define BETA 4000
#define CM 5000
#define VISUALIZATION_PAUSED_OPT 5100

struct user_options 
{
    char *config_file;

    struct string_voidp_hash_entry *section_config_1;
    struct string_voidp_hash_entry *section_config_2;
    struct string_voidp_hash_entry *section_config_3;

};


void display_usage( char** argv );

struct user_options* new_user_options();

void print_info_options (struct user_options *options);

void get_config_file(int argc, char**argv, struct user_options *user_args);
int parse_config_file(void* user, const char* section, const char* name, const char* value);

void free_user_options(struct user_options *s);

#endif /* MONOALG3D_CONFIG_PARSER_H */
