#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef void (*sample_function)(double*,int);

void double_vector (double *v, int n)
{
    int i;
    for (i = 0; i < n; i++)
        v[i] *= 2.0;
}

void triple_vector (double *v, int n)
{
    int i;
    for (i = 0; i < n; i++)
        v[i] *= 3.0;
}

void quadruple_vector (double *v, int n)
{
    int i;
    for (i = 0; i < n; i++)
        v[i] *= 4.0;
}

void fillVector (double *v, const int N)
{
    int i;
    for (i = 0; i < N; i++)
        v[i] = i+1;
}

void printVector (double *v, const int N)
{
    int i;
    for (i = 0; i < N; i++)
        printf("%.2lf ",v[i]);
    printf("\n");
}

int main ()
{
    const int N = 5;

    double *v = (double*)malloc(sizeof(double)*N);
    fillVector(v,N);
    printVector(v,N);

    sample_function *func_array = (sample_function*)malloc(sizeof(sample_function)*3);
    
    func_array[0] = double_vector;
    func_array[1] = triple_vector;
    func_array[2] = quadruple_vector;

    func_array[0](v,N);
    printf("double_vector\n");
    printVector(v,N);

    func_array[1](v,N);
    printf("triple_vector\n");
    printVector(v,N);

    func_array[2](v,N);
    printf("quadruple_vector\n");
    printVector(v,N);

    free(func_array);
    free(v);

    return 0;
}