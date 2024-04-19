# Makefile for CS50 Lab3
#   Builds and compiles all the data structures.
#
# Makefile for 'bag' module
#
# David Kotz, April 2016, 2017, 2019, 2021
# updated by Xia Zhou, July 2016, 2018, January 2019

OBJS = ../set/set.o hash.o hashtable.o ../lib/file.o ../lib/mem.o hashtabletest.o
LIBS =

# uncomment the following to turn on verbose memory logging
TESTING=-DMEMTEST
CFLAGS = -g -Wall -pedantic -std=gnu11 -ggdb $(TESTING) -I../lib
CC = gcc
MAKE = make
# for memory-leak tests
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

hashtabletest: $(OBJS)
			$(CC) $(CFLAGS) $^ $(LIBS) -o $@

hashtabletest.o: hashtable.h hash.h     ../lib/file.h ../set/set.h
hashtable.o: hashtable.h hash.h ../set/set.h
../lib/file.o: ../lib/file.h

.PHONY: test valgrind clean

# expects a file `test.names` to exist; it can contain any text.
test: hashtabletest
				./hashtabletest

# expects a file `test.names` to exist; it can contain any text.
valgrind: hashtabletest
					$(VALGRIND) ./hashtabletest

clean:
		rm -rf *.dSYM
		rm -f *~ *.o
		rm -f hashtabletest
		rm -f core
