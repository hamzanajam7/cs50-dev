### Hashtable Overview

A hashtable is an efficient data structure that stores pairs of keys and items. Designed to handle large collections effectively, a hashtable organizes data into an array of sets based on hash values, allowing for faster retrieval compared to other collection types.

In your `hashtable.c` file, you should implement a hashtable that pairs `char*` keys with `void*` items. The functions to manage these hashtables are outlined in `hashtable.h`, which includes comprehensive documentation for each function.

### Functions Provided

- `hashtable_t* hashtable_new(const int num_slots);` - Creates a new hashtable with a specified number of slots.
- `bool hashtable_insert(hashtable_t* ht, const char* key, void* item);` - Inserts a new key-item pair into the hashtable.
- `void* hashtable_find(hashtable_t* ht, const char* key);` - Retrieves the item associated with a given key.
- `void hashtable_print(hashtable_t* ht, FILE* fp, void (*itemprint)(FILE* fp, const char* key, void* item));` - Prints each key-item pair in the hashtable.
- `void hashtable_iterate(hashtable_t* ht, void* arg, void (*itemfunc)(void* arg, const char* key, void* item));` - Applies a function to each key-item pair in the hashtable.
- `void hashtable_delete(hashtable_t* ht, void (*itemdelete)(void* item));` - Deletes the hashtable and frees associated resources, applying a specified function to each item.

### Implementation Details

The hashtable is implemented as an array of sets, where each set holds the key-item pairs that hash to the same slot. This structure is optimal for balancing load and ensuring quick access.

### Relevant Files

- `.gitignore` - Specifies untracked files that Git should ignore.
- `hash.c` - Contains hash functions used by the hashtable.
- `hash.h` - Header file with hash function declarations.
- `hashtable.c` - Contains the hashtable implementation.
- `hashtable.h` - Header file with hashtable function declarations.
- `hashtabletest.c` - Contains tests for validating the hashtable implementation.
- `Makefile` - Used to compile the project.
- `README.md` - Provides detailed information about the project.

### Compilation Instructions

Compile the project by running the `make` command. This command compiles all source files and links them into executable binaries as defined in the Makefile.

### Testing

Extensive testing is conducted through the `hashtabletest.c` file, which examines a wide array of test cases to ensure robustness and functionality of the hashtable implementation.