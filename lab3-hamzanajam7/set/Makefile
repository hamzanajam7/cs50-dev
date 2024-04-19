# Makefile - set
#
# Author: Hamza Najam

# Object files and libraries needed
OBJS = settest.o set.o ../lib/file.o ../lib/mem.o 
LIBS =

# Compiler settings
CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../lib

# Uncomment to enable verbose memory logging
#TESTING=-DMEMTEST

# Valgrind setup for memory leak detection
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

# Build the test program
settest: $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

# Dependencies for building object files
settest.o: set.h ../lib/file.h
set.o: set.h
../lib/file.o: ../lib/file.h

.PHONY: test valgrind clean

# Run tests using a file 'test.names' that should contain input data
test: settest test.names
	./settest

# Use valgrind to check for memory leaks during testing
valgrind: settest test.names
	$(VALGRIND) ./settest < test.names

# Clean up the build directory
clean:
	rm -rf *.dSYM  # Remove MacOS debugger info
	rm -f *~ *.o
	rm -f settest
	rm -f core
