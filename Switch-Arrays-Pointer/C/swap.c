#include <stdio.h>
#include <stdlib.h>

void swap (double **a, double **b)
{
    double *tmp = *a;
    *a = *b;
    *b = tmp;
}

int main ()
{
	double *u = (double*)malloc(sizeof(double)*5);
	double *v = (double*)malloc(sizeof(double)*5);
	for (int i = 0; i < 5; i++) u[i] = i, v[i] = 9-i;
	printf("u before swapping\n");
	for (int i = 0; i < 5; i++)
	printf("%lf ",u[i]);
	printf("\n");
	printf("v before swapping\n");
	for (int i = 0; i < 5; i++)
	printf("%lf ",v[i]);
	printf("\n");

	swap(&u,&v);

	printf("u after swapping\n");
	for (int i = 0; i < 5; i++)
	printf("%lf ",u[i]);
	printf("\n");
	printf("v after swapping\n");
	for (int i = 0; i < 5; i++)
	printf("%lf ",v[i]);
	printf("\n");

	return 0;
}

