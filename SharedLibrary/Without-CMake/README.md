
### Shared library guide

A library is a file containing compiled code from various object files stuffed into a single file. It may contain a group of functions that are used in a particular context. For example, the ‘pthread’ library is used when thread related functions are to be used in the program.

A library can be of two main types:

 - Static library
 - Shared library

Shared Libraries are the libraries that can be linked to any program at run-time. They provide a means to use code that can be loaded anywhere in the memory. Once loaded, the shared library code can be used by any number of programs. So, this way the size of programs(using shared library) and the memory footprint can be kept low as a lot of code is kept common in form of a shared library.

Shared libraries provide modularity to the development environment as the library code can be changed, modified and recompiled without having to re-compile the applications that use this library.

This example demonstrate how to build a simple shared library using the GNU-GCC Compiler.

This folder contains 3 files.

 - **main.c** = Driver program that will be executed to test the library
 - **shared.h** = Header file containing the functions from the shared library
 - **shared.c** = Source file with the implementation of the shared library functions

The first step to build a shared library is to compile its source code into object code (-c flag) and put it on a independent position (-fPIC flag).

```sh
$ gcc -c -Wall -Werror -fPIC shared.c
```
Next, we need to generate the shared library from the object file.

```sh
$ gcc -shared -o libshared.so shared.o
```
Now, to proper use the shared library ``libshared.so`` that we just create it, we need to compile the source code for the driver program that actually uses the functions from the library. In order to do that, we must specify the location where the shared library is located in out system (-L flag) and tell the linker the name of the shared library (-l flag).

```sh
$ gcc -L<path-to-shared-library> -Wall main.c -o main -lshared
```
The final step is to export the location of the shared library to the ``LD_LIBRARY_PATH`` variable of the system. By doing that, when the program is executed the system can find the location of the library and used it.

```sh
$ export LD_LIBRARY_PATH=<path-to-shared-library>:$LD_LIBRARY_PATH
```
Then just execute the driver program.

```sh
$ ./main
```

