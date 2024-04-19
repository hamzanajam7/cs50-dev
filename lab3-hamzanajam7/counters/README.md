### Counters Overview

A counter set is a collection of unique integer keys, each associated with a count value. This collection functions as a set, meaning each key is unique and can appear only once. Initially, the counter set is empty. The count for each key increases by one each time the `counters_add` function is invoked using that key. The value of any counter can be accessed by providing its key.

In your `counters.c` file, you should implement this set of integer counters, which are identified by non-negative integer keys. The functions that operate on these counters are specified in `counters.h`. You will find more detailed documentation within that file.

### Functions Provided

- `counters_t* counters_new(void);` - Initializes a new set of counters.
- `int counters_add(counters_t* ctrs, const int key);` - Increments the counter for a specified key.
- `int counters_get(counters_t* ctrs, const int key);` - Retrieves the current count for a specified key.
- `bool counters_set(counters_t* ctrs, const int key, const int count);` - Sets the counter for a specified key to a specified count.
- `void counters_print(counters_t* ctrs, FILE* fp);` - Prints all counters to the specified file.
- `void counters_iterate(counters_t* ctrs, void* arg, void (*itemfunc)(void* arg, const int key, const int count));` - Applies a function to each counter in the set.
- `void counters_delete(counters_t* ctrs);` - Frees all resources associated with the counter set.

### Implementation Details

The counters are implemented using a linked list structure.

### Relevant Files

- `counters.c` - Contains the implementation of the counters.
- `counters.h` - Header file with declarations for the counter functions.
- `counterstest.c` - Contains tests for the counters implementation.
- `Makefile` - Used to compile the project.
- `README.md` - Provides detailed information about the project.

### Compilation Instructions

Compile the project by executing the `make` command in your terminal. This will build the necessary executable files from the source code provided in the project files.