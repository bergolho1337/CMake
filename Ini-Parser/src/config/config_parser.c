#include <assert.h>
#include <string.h>

#include "../ini_parser/ini_file_sections.h"
#include "../string/sds.h"
#include "../utils/file_utils.h"
#include "config_parser.h"
#include "section_config.h"

#include "../single_file_libraries/stb_ds.h"
#include "../config_helpers/config_helpers.h"

static const char *opt_string = "c:abn:g:m:t:r:d:z:e:f:jR:D:G:k:v:qh?";
static const struct option long_options[] = {
        {"config_file", required_argument, NULL, 'c'},
        {"use_adaptivity", no_argument, NULL, 'a'},
        {"abort_on_no_activity", no_argument, NULL, 'b'},
        {"vm_threshold", required_argument, NULL, 'v'},
        {"num_threads", required_argument, NULL, 'n'},
        {"use_gpu", required_argument, NULL, 'g'},
        {"print_rate", required_argument, NULL, 'p'},
        {"max_cg_its", required_argument, NULL, 'm'},
        {"cg_tolerance", required_argument, NULL, 't'},
        {"refinement_bound", required_argument, NULL, 'r'},
        {"derefinement_bound", required_argument, NULL, 'd'},
        {"dt_pde", required_argument, NULL, 'z'},
        {"dt_ode", required_argument, NULL, 'e'},
        {"simulation_time", required_argument, NULL, 'f'},
        {"use_preconditioner", no_argument, NULL, 'j'},
        {"refine_each", required_argument, NULL, 'R'},
        {"derefine_each", required_argument, NULL, 'D'},
        {"gpu_id", required_argument, NULL, 'G'},
        {"model_file_path", required_argument, NULL, 'k'},
        {"beta", required_argument, NULL, BETA},
        {"cm", required_argument, NULL, CM},
        {"start_adapting_at", required_argument, NULL, START_REFINING},
        {"domain", required_argument, NULL, DOMAIN_OPT}, //Complex option in the format --domain "name='domain', start_dx=250.0" ...
        {"save_result", required_argument, NULL, SAVE_OPT}, //Complex option
        {"assembly_matrix", required_argument, NULL, ASSEMBLY_MATRIX_OPT}, //Complex option
        {"extra_data", required_argument, NULL, EXTRA_DATA_OPT}, //Complex option
        {"stimulus", required_argument, NULL, STIM_OPT}, //Complex option
        {"save_state", required_argument, NULL, SAVE_STATE_OPT}, //Complex option
        {"restore_state", required_argument, NULL, RESTORE_STATE_OPT}, //Complex option
        {"linear_system_solver", required_argument, NULL, LINEAR_SYSTEM_SOLVER_OPT}, //Complex option
        {"update_monodomain", required_argument, NULL, UPDATE_MONODOMAIN_SOLVER_OPT}, //Complex option
        {"visualize", no_argument, NULL, DRAW_OPT},
        {"visualization_max_v", required_argument, NULL, MAX_V_OPT},
        {"visualization_min_v", required_argument, NULL, MIN_V_OPT},
        {"start_simulation_unpaused", no_argument, NULL, VISUALIZATION_PAUSED_OPT},
        {"quiet", no_argument, NULL, 'q'},
        {"help", no_argument, NULL, 'h'},
        {NULL, no_argument, NULL, 0}};


void display_usage(char **argv) {

    printf("Usage: %s [configuration_file_path]\n\n", argv[0]);
    printf("Options:\n");
    printf("--config_file | -c [configuration_file_path]. Simulation configuration file. Mandatory!\n");
    
    printf("--help | -h. Shows this help and exit \n");
    exit(EXIT_FAILURE);
}

struct user_options *new_user_options() 
{

    struct user_options *user_args = (struct user_options *)malloc(sizeof(struct user_options));

    user_args->config_file = NULL;

    user_args->section_config_1 = NULL;
    sh_new_arena(user_args->section_config_1);
    shdefault(user_args->section_config_1, NULL);

    user_args->section_config_2 = NULL;
    sh_new_arena(user_args->section_config_2);
    shdefault(user_args->section_config_2, NULL);

    user_args->section_config_3 = NULL;
    sh_new_arena(user_args->section_config_3);
    shdefault(user_args->section_config_3, NULL);

    return user_args;
}

void get_config_file(int argc, char **argv, struct user_options *user_args) 
{

    optind = 0;

    int opt = 0;

    int option_index;

    opt = getopt_long(argc, argv, opt_string, long_options, &option_index);

    while(opt != -1) 
    {
        if(opt == 'c') 
        {
            user_args->config_file = optarg;
            return;
        }
        opt = getopt_long(argc, argv, opt_string, long_options, &option_index);
    }

    // We reset the index after parsing the config_file
    optind = 1;
}

void set_common_data(struct config* config, const char *key, const char *value) {

    if(strcmp(key, "main_function") == 0) {
        config->main_function_name = strdup(value);
        config->main_function_name_was_set = true;
    }
    if(strcmp(key, "init_function") == 0) {
        config->init_function_name = strdup(value);
        config->init_function_name_was_set = true;
    }
    if(strcmp(key, "end_function") == 0) {
        config->end_function_name = strdup(value);
        config->end_function_name_was_set = true;
    }
    else if(strcmp(key, "library_file") == 0) {
        config->library_file_path = strdup(value);
    }
    else {
        shput_dup_value(config->config_data, key, value);
    }

}

int parse_config_file(void *user, const char *section, const char *name, const char *value) 
{
    struct user_options *pconfig = (struct user_options *)user;

    if(SECTION_STARTS_WITH(FIRST_SECTION)) 
    {

        struct config *tmp = (struct config *) shget(pconfig->section_config_1, section);

        if (tmp == NULL) 
        {
            tmp = alloc_and_init_config_data();
            shput(pconfig->section_config_1, section, tmp);
        }

        if (MATCH_NAME("name")) 
        {
            fprintf(stderr,
                    "name is a reserved word and should not be used inside a stimulus config section. Found in %s. "
                    "Exiting!\n",
                    section);
            exit(EXIT_FAILURE);
        }
        else 
        {
            set_common_data(tmp, name, value);
        }

    }
    else if(SECTION_STARTS_WITH(SECOND_SECTION)) 
    {

        struct config *tmp = (struct config *) shget(pconfig->section_config_2, section);

        if (tmp == NULL) 
        {
            tmp = alloc_and_init_config_data();
            shput(pconfig->section_config_2, section, tmp);
        }

        if (MATCH_NAME("name")) 
        {
            fprintf(stderr,
                    "name is a reserved word and should not be used inside a stimulus config section. Found in %s. "
                    "Exiting!\n",
                    section);
            exit(EXIT_FAILURE);
        }
        else 
        {
            set_common_data(tmp, name, value);
        }

    } 
    else if(SECTION_STARTS_WITH(THIRD_SECTION)) 
    {

        struct config *tmp = (struct config *) shget(pconfig->section_config_3, section);

        if (tmp == NULL) 
        {
            tmp = alloc_and_init_config_data();
            shput(pconfig->section_config_3, section, tmp);
        }

        if (MATCH_NAME("name")) 
        {
            fprintf(stderr,
                    "name is a reserved word and should not be used inside a stimulus config section. Found in %s. "
                    "Exiting!\n",
                    section);
            exit(EXIT_FAILURE);
        }
        else 
        {
            set_common_data(tmp, name, value);
        }

    }
    else 
    {
        fprintf(stderr, "\033[33;5;7mInvalid name %s in section %s on the config file!\033[0m\n", name, section);
        return 0;
    }

    return 1;
}


void print_info_options (struct user_options *options)
{
    print_to_stdout_and_file(LOG_LINE_SEPARATOR);
    struct string_voidp_hash_entry *e1 = options->section_config_1;
    print_section_config_values((struct config*) e1->value);
    print_to_stdout_and_file(LOG_LINE_SEPARATOR);

    print_to_stdout_and_file(LOG_LINE_SEPARATOR);
    struct string_voidp_hash_entry *e2 = options->section_config_2;
    print_section_config_values((struct config*) e2->value);
    print_to_stdout_and_file(LOG_LINE_SEPARATOR);

    print_to_stdout_and_file(LOG_LINE_SEPARATOR);
    struct string_voidp_hash_entry *e3 = options->section_config_3;
    print_section_config_values((struct config*) e3->value);
    print_to_stdout_and_file(LOG_LINE_SEPARATOR);
}

void free_user_options(struct user_options *s) 
{

    if(s->section_config_1) 
    {
        STIM_CONFIG_HASH_FOR_EACH_KEY_APPLY_FN_IN_VALUE(s->section_config_1, free_config_data);
        shfree(s->section_config_1);
    }

    free(s);
}
