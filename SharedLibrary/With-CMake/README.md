
### Shared library guide

A library is a file containing compiled code from various object files stuffed into a single file. It may contain a group of functions that are used in a particular context. For example, the ‘pthread’ library is used when thread related functions are to be used in the program.

A library can be of two main types:

 - Static library
 - Shared library

Shared Libraries are the libraries that can be linked to any program at run-time. They provide a means to use code that can be loaded anywhere in the memory. Once loaded, the shared library code can be used by any number of programs. So, this way the size of programs(using shared library) and the memory footprint can be kept low as a lot of code is kept common in form of a shared library.

Shared libraries provide modularity to the development environment as the library code can be changed, modified and recompiled without having to re-compile the applications that use this library.

This example demonstrate how to build a simple shared library using **CMake**.

The first step is to compile the shared library which is located on the Generator folder. Once in this folder build the shared library by calling **CMake**. We move the ``libshared.so`` file to the root folder, but it is not necessary.

```sh
$ cd build; cmake ..; make
$ mv libshared.so ../
```

The second step is to proper use the shared library. This procedure is done by the program located on the Usage folder. Enter this directory and compile the code using **CMake** and then execute it normally.

```sh
$ cd build; cmake ..; make
$ ./main
```