### CS50 Set Overview

A set is a data structure that stores unique key-item pairs in an unordered fashion. Each key within a set is distinct and can only appear once. The set starts empty and grows as new key-item pairs are added. While items can be retrieved using their respective keys, the structure does not support the removal or updating of existing pairs. Each item is uniquely identified by its key.

`set.c` implementation should manage sets of `void*` items associated with `char*` keys. The functionalities of these sets are detailed in the `set.h` file, which includes comprehensive comments and documentation.

### Functions Provided

- `set_t* set_new(void);` - Initializes a new empty set.
- `bool set_insert(set_t* set, const char* key, void* item);` - Adds a new key-item pair to the set, ensuring the key is unique.
- `void* set_find(set_t* set, const char* key);` - Retrieves the item associated with a specified key.
- `void set_print(set_t* set, FILE* fp, void (*itemprint)(FILE* fp, const char* key, void* item));` - Prints the contents of the set to a file using a custom print function.
- `void set_iterate(set_t* set, void* arg, void (*itemfunc)(void* arg, const char* key, void* item));` - Applies a function to every key-item pair in the set.
- `void set_delete(set_t* set, void (*itemdelete)(void* item));` - Frees all resources associated with the set and optionally applies a function to delete each item.

### Implementation Details

The set is implemented using a linked list to store the key-item pairs. This approach allows for efficient traversal and modification of the set while ensuring that each key remains unique.

### Relevant Files

- `set.c` - Contains the implementation of the set.
- `set.h` - Header file with declarations for set functions.
- `settest.c` - Includes tests for verifying the functionality of the set.
- `Makefile` - Used to compile the project.
- `README.md` - Provides detailed information about the set implementation.

### Compilation Instructions

Compile the project by executing the `make` command in your terminal. This command compiles all source files and links them to create executable binaries, as defined in the Makefile.

### Testing

Comprehensive testing is conducted through the `settest.c` file, which uses a variety of test cases to ensure the robustness and functionality of the set implementation.