#include "shared.h"

unsigned int add (unsigned int a, unsigned int b)
{
    printf("Inside add()\n");
    return a + b;
}

unsigned int sub (unsigned int a, unsigned int b)
{
    printf("Inside sub()\n");
    return a - b;
}

unsigned int mult (unsigned int a, unsigned int b)
{
    printf("Inside mult()\n");
    return a * b;
}

void print (unsigned int r)
{
    printf("The result is %u\n",r);
}