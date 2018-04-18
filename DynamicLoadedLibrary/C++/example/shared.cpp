// Built from g++
//  $ g++ -c -Wall -Werror -fPIC shared.cpp
//  $ g++ -shared -o libshared.so shared.o

#include <iostream>

using namespace std;

extern "C" void hello ()
{
    cout << "Hello world from a shared library written in C++ !!!" << endl;
}

extern "C" int password (int magic_number)
{
    if (magic_number % 2 == 0)
        return 1;
    else
        return 0;
}