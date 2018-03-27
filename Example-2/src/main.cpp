// **************************************************************************
// How to build with CMake:
// Create a build folder to store the executable and auxiliary files
//      $ mkdir build; cd build
// Execute CMake and build the Makefile
//      $ cmake ..
// Compile the source files and generate the executable
//      $ make
// Execute the program
//      $ ./testStudent 
// **************************************************************************
// If you add other source files to the project you need to reexecute the 
// cmake command, since this will update the Makefile.
// **************************************************************************

#include <iostream>
#include "../include/Student.h"

using namespace std;

int main ()
{
    // Testing the Student class
    Student s1("Joe");
    Student s2("Maria");
    Student s3("Bob");

    s1.display();
    s2.display();
    s3.display();

    return 0;
}