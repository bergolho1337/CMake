#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include "../include/timer.h"

using namespace std;

// Number of switch lines operations
const int NSWITCHES = 10000;

void fillMatrix (double **A, const int nrows, const int mcol)
{
    for (int i = 0; i < nrows; i++)
        for (int j = 0; j < mcol; j++)
            A[i][j] = rand() % 10;
}

void printMatrix (double **A, const int nrows, const int mcol)
{
    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < mcol; j++)
            cout << setw(4) << A[i][j] << " ";
        cout << endl;
    }
}

void swapLinesByCopy (double **A, const int i, const int j, const int mcol)
{
    for (int k = 0; k < mcol; k++)
    {
        double aux = A[i][k];
        A[i][k] = A[j][k];
        A[j][k] = aux;
    }
}

void swapLinesByReference (double **A, const int i, const int j)
{
    swap(A[i],A[j]);
}

double benchmark_1 (double **A, const int nrows, const int mcol)
{
    double start, finish;
    GET_TIME(start);

    for (int k = 0; k < NSWITCHES; k++)
    {
        int lin1 = rand() % nrows;
        int lin2 = rand() % nrows;

        swapLinesByCopy(A,lin1,lin2,mcol);
    }

    GET_TIME(finish);
    return finish - start;
}

double benchmark_2 (double **A, const int nrows, const int mcol)
{
    double start, finish;
    GET_TIME(start);

    for (int k = 0; k < NSWITCHES; k++)
    {
        int lin1 = rand() % nrows;
        int lin2 = rand() % nrows;

        swapLinesByReference(A,lin1,lin2);
    }

    GET_TIME(finish);
    return finish - start;
}

int main ()
{
    double elapsed_1, elapsed_2;
    const int nrows = 10;
    const int mcol = 10;

    double **A = (double**)malloc(sizeof(double*)*nrows);
    for (int i = 0; i < nrows; i++)
        A[i] = (double*)malloc(sizeof(double)*mcol);

    fillMatrix(A,nrows,mcol);

    elapsed_1 = benchmark_1(A,nrows,mcol);    
    elapsed_2 = benchmark_2(A,nrows,mcol);

    cout << fixed << setprecision(10) << "[Benchmark 1] Switching lines by copying = " << elapsed_1 << endl;
    cout << fixed << setprecision(10) << "[Benchmark 2] Switching lines by swap pointers = " << elapsed_2 << endl;


    for (int i = 0; i < nrows; i++)
        free(A[i]);
    free(A);

    return 0;
}