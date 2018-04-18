// Sample program that uses the shared library "libshared.so"
// ------------------------------------------------------------------------------------------------
// Step 1) Compile the source code that uses the shared library by specifing the location where
//        ".so" file is located. (The -L flag specify that !)
// Step 2) Tell the linker the name of the shared library (The -l flag specify this !)
// Step 3) Export the location of the shared library to LD_LIBRARY_PATH variable of the system, so
//       when the program is executed the system can find the library and used it.
//          
//  $ export LD_LIBRARY_PATH=/home/berg/Documentos/Github/CMake/SharedLibrary/Without-CMake:$LD_LIBRARY_PATH
// ------------------------------------------------------------------------------------------------
// Compilation:
// $ gcc -L/home/berg/Documentos/Github/CMake/SharedLibrary/Without-CMake -Wall main.c -o main -lshared
//
// Execute:
// ./main 

#include <stdio.h>
#include "shared.h"

int main ()
{
    unsigned int a = 5;
    unsigned int b = 4;
    unsigned int result = 0;

    printf("Add\n");
    result = add(a,b);
    print(result);

    printf("Sub\n");
    result = sub(a,b);
    print(result);

    printf("Mult\n");
    result = mult(a,b);
    print(result);

    return 0;
}
