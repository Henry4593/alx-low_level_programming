#!/bin/bash

# Compiling all source files for the program
gcc -fpic -c -Wall -pedantic -Werror -Wextra -std=gnu89 *.c

# Compiling Shared Library for the program to use
gcc -shared -o liball.so *.o

# Removing all Object files
rm -fr *.o
