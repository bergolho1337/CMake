CXX = g++
CXXFLAGS = -Wall -Werror

all: foo

# Compile the driver program linking the "dlfcn.h" library
# Adds the dependency to the shared library
foo: foo.cpp libshared.so
	$(CXX) $(CXXFLAGS) -o $@ $< -ldl

# Compile instructions for the shared library
libshared.so: shared.cpp
	$(CXX) -c $(CXXFLAGS) -fPIC $<
	$(CXX) -shared -o $@ shared.o

clean:
	rm -f foo libshared.so *.o

.PHONY: clean
