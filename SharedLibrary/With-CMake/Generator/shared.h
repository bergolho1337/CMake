// Shared library example
// ----------------------------------------------------------
// Step 1) Compile the source code of the shared library
//        into an object file and on a independent position.
//   
//      $ gcc -c -Wall -Werror -fPIC shared.c
//
// Step 2) Generate the shared library from the object file
//
//      $ gcc -shared -o libshared.so shared.o
// ----------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

extern unsigned int add (unsigned int a, unsigned int b);
extern unsigned int sub (unsigned int a, unsigned int b);
extern unsigned int mult (unsigned int a, unsigned int b);
extern void print (unsigned int r);
