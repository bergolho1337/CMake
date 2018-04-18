
### Dinamically Loaded Libraries

Dynamically loaded (DL) libraries are libraries that are loaded at times other than during the 
startup of a program. They're particularly useful for implementing plugins or modules, because they 
permit waiting to load the plugin until it's needed.

They're also useful for implementing interpreters that wish to occasionally compile their code 
into machine code and use the compiled version for efficiency purposes, all without stopping.

In Linux, DL libraries aren't actually special from the point-of-view of their format; they are 
built as standard object files or standard shared libraries as discussed above. The main difference
is that the libraries aren't automatically loaded at program link time or start-up; instead, there 
is an API for opening a library, looking up symbols, handling errors, and closing the library. 
C users will need to include the header file ``<dlfcn.h>`` to use this API.

In C the DL libraries can be used very easily, since the symbol table of the functions from the library has the equivalence of the symbol name with the function name. But in C++, as it is possible to overwrite functions the symbols table are quite different from C. 

On C++, the compiler set some random string as the symbol name of a function and only him can understand it. To proper use the DL libraries in C++ you need to define the functions of the libraries with the ``extern "C"`` mark, meaning that is a C-like function.

The C example demonstrate its usage by loading the mathematical library ``<math.h>``. 

Instead, the C++ example shows how to build a shared library from source using a ``Makefile`` and demonstrate how to proper define the functions of the shared library if you are using a ``.cpp`` file. This was done by adding the ``extern "C"`` keyword before its implementation.

