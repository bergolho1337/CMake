/*
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
Author: Lucas Berg

Serial version of the program. 
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
COMPILATION:
    Just run the script for compilation, which builds the binary file using CMake.

    $ ./recompile_project.sh
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
EXECUTE:
    
    $ ./bin/serial
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
PLOT RESULTS:
    $ cd scripts; python plot_functions.py; cd ..
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PRINT_LINE "==================================================================================================================================="

const int TOTAL_NUMBER_SIMULATIONS = 16;        // Total number of simulations
const double MAX_X_AXIS = 1.0;                  // Limit of the x-axis
const double DX = 0.01;                         // Size of the discretization

struct simulation_data
{
    int id;                     // Simulation index
    double a;                   // Coefficient 'a' of the linear function
    double b;                   // Coefficient 'b' of the linear function
};

double f (const double x, const double a, const double b) { return (a*x + b); }  // Linear function

struct simulation_data* generate_all_simulations (const int total_number_simulations)
{
    struct simulation_data *result = (struct simulation_data*)malloc(sizeof(struct simulation_data)*total_number_simulations);

    for (int i = 0; i < total_number_simulations; i++)
    {
        result[i].id = i;

        // Linear function form: f(x) = 1.0 * x + (i+1) --> Shift over the y-axis
        result[i].a = 1.0;
        result[i].b = (double)(i+1);
    }

    return result;
}

void solve_simulation (struct simulation_data s)
{
    FILE *file;
    char filename[100];
    
    int np = nearbyint(MAX_X_AXIS/DX);
    sprintf(filename,"outputs/simulation-%d.dat",s.id);
    file = fopen(filename,"w+");

    // DEBUG
    printf("[DEBUG] Solving linear function: f(x) = %g.x + %g (Simulation %d)\n",s.a,s.b,s.id);

    // Calculate the image of the function
    for (int i = 0; i < np; i++)
    {
        double x = i*DX;

        // Call the linear function using the parameters from the current simulation
        double y = f(x,s.a,s.b);

        // Write the output into a file
        fprintf(file,"%g %g\n",x,y);
    }
    fclose(file);
}

void print_all_simulations (struct simulation_data *the_simulations, const int total_number_simulations)
{
    for (int i = 0; i < total_number_simulations; i++)
    {
        printf("%s\n",PRINT_LINE);
        printf(">> SIMULATION %d\n",the_simulations[i].id);
        printf("Parameters:\n");
        printf(">>>> a = %g\n",the_simulations[i].a);
        printf(">>>> b = %g\n",the_simulations[i].b);
        printf("%s\n",PRINT_LINE);
    }
}

int main(int argc, char** argv) 
{
    // Generate all the simulations
    int total_number_simulations = TOTAL_NUMBER_SIMULATIONS;
    
    struct simulation_data *the_simulations = generate_all_simulations(total_number_simulations);
    print_all_simulations(the_simulations,total_number_simulations);

    for (int s = 0; s < TOTAL_NUMBER_SIMULATIONS; s++)   // Simulation loop
    {
        solve_simulation(the_simulations[s]);
    }

    free(the_simulations);      // Free memory
    
    return EXIT_SUCCESS;

}

