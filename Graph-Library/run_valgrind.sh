#!/bin/bash
PNAME="./bin/Graph"

if [ ! -f $PNAME ]; then
	./recompile_project.sh
fi

# Run valgrind to check for heap memory leaks ...
valgrind --leak-check=full ./$PNAME