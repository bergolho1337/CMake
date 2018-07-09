#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TENTUSSCHER 19
#define NOBLE 4

const double init_tentusscher[19] = {-85.23f, 0.00621f, 0.4712f, 0.0095f, 0.00172f, 0.7444f, 0.7045f, 3.373e-5f, 0.7888f, 0.9755f, 0.9953f, 0.999998f, 2.42e-8f, 0.000126f, 3.64f, 0.00036f, 0.9073f, 8.604f, 136.89f};
const double init_noble[4] = {-75.5344986658f, 0.060546727200f, 0.725900135500f, 0.470923970800f};

int main ()
{
    int n = 100;
    double **sv = (double**)malloc(sizeof(double*)*n);
    for (int i = 0; i < n; i++)
    {
        if (i < 50)
        {
            sv[i] = (double*)malloc(sizeof(double)*TENTUSSCHER);
            memcpy(sv[i],init_tentusscher,sizeof(double)*TENTUSSCHER);
        }
            
        else
        {
            sv[i] = (double*)malloc(sizeof(double)*NOBLE);
            memcpy(sv[i],init_noble,sizeof(double)*NOBLE);
        }
    }

    // Printing initial conditions
    for (int i = 0; i < n; i++)
    {
        if (i < 50)
        {
            for (int j = 0; j < TENTUSSCHER; j++)
                printf("%.4lf ",sv[i][j]);
            printf("\n");
        }
            
        else
        {
            for (int j = 0; j < NOBLE; j++)
                printf("%.4lf ",sv[i][j]);
            printf("\n");
        }    
    }

    // Free memory
    for (int i = 0; i < n; i++)
        free(sv[i]);
    free(sv);

    return 0;
    
}