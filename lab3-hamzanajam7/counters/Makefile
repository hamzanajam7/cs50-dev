# Makefile - counters 
# Hamza Najam

# Object files and libraries
OBJS = counterstest.o counters.o ../lib/file.o ../lib/mem.o 
LIBS =

# Compiler flags
CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../lib
CC = gcc
MAKE = make

# Valgrind for memory leaks
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

# Uncomment the following to enable verbose memory logging
#TESTING=-DMEMTEST

# Compilation rules
counterstest: $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

# Dependencies for object files
counterstest.o: counters.h ../lib/file.h
counters.o: counters.h
../lib/file.o: ../lib/file.h

# Phony targets for build management
.PHONY: test valgrind clean

# Testing rules
test: counterstest test.names
	./counterstest < test.names

valgrind: counterstest test.names
	$(VALGRIND) ./counterstest < test.names

# Cleaning up unnecessary files
clean:
	rm -rf *.dSYM          # MacOS debugger info
	rm -f *~ *.o
	rm -f counterstest
	rm -f core
