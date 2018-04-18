#include <iostream>
#include <dlfcn.h>

using namespace std;

int main ()
{
    char *error;
    cout << "C++ dlopen demo" << endl;

    // Open the library
    cout << "Opening 'libshared.so'" << endl;
    void *handle = dlopen("./libshared.so",RTLD_LAZY);
    if (!handle)
    {
        cerr << "Cannot open library: " << dlerror() << endl;
        return 1;
    }

    // Typedef the function pointers
    typedef void (*hello_t)();
    typedef int (*password_t)(int);
    
    // Reset any error
    dlerror();
    
    // Load the symbol from the shared library
    cout << "Loading symbol hello" << endl;
    hello_t hello = (hello_t)dlsym(handle,"hello");
    error = dlerror();
    if ((error = dlerror()) != NULL)
    {
        cerr << "Cannot load symbol 'hello': " << error << endl;
        dlclose(handle);
        return 1;
    }

    cout << "Loading symbol password" << endl;
    password_t password = (password_t)dlsym(handle,"password");
    error = dlerror();
    if ((error = dlerror()) != NULL)
    {
        cerr << "Cannot load symbol 'password': " << error << endl;
        dlclose(handle);
        return 1;
    }

    // Use the symbol to do the calculations
    hello();
    int pass_value = 3;
    if (password(pass_value))
        cout << "[+] LOCK OPEN !!" << endl;
    else
        cout << "[-] FAIL !!" << endl;
    
    // Close the library
    cout << "Closing library ..." << endl;
    dlclose(handle);

    return 0;
}
