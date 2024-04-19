/** 
 * Hamza Najam
 * hashtable.c , lab3
 * 01/23/2024
 */

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"          // Assume hash_jenkins is defined here
#include "hashtable.h"     // Assume necessary function prototypes are defined here
#include "../set/set.h"    // Set module API is included

// Hash table structure definition
typedef struct hashtable 
{
    set_t **buckets;     // Array of set pointers for buckets
    int size;            // Number of buckets in the hash table
} hashtable_t;

// Create a new hash table
hashtable_t* hashtable_new(int size) 
{
    if (size <= 0) return NULL;

    hashtable_t *hash_table = malloc(sizeof(hashtable_t));
    if (!hash_table) return NULL;

    hash_table->buckets = calloc(size, sizeof(set_t*));
    if (!hash_table->buckets) 
    {
        free(hash_table);
        return NULL;
    }

    hash_table->size = size;
    for (int i = 0; i < size; i++) 
    {
        hash_table->buckets[i] = set_new();
        if (!hash_table->buckets[i]) {
            // Clean up previously allocated sets if initialization fails
            while (--i >= 0) set_delete(hash_table->buckets[i], NULL);
            free(hash_table->buckets);
            free(hash_table);
            return NULL;
        }
    }
    return hash_table;
}

// Insert a key-item pair into the hash table
bool hashtable_insert(hashtable_t *hash_table, const char *key, void *item) 
{
    if (!hash_table || !key || !item) return false;
    int index = hash_jenkins(key, hash_table->size);
    return set_insert(hash_table->buckets[index], key, item);
}

// Find an item by key in the hash table
void* hashtable_find(hashtable_t *hash_table, const char *key) 
{
    if (!hash_table || !key) return NULL;
    int index = hash_jenkins(key, hash_table->size);
    return set_find(hash_table->buckets[index], key);
}

// Print the contents of the hash table
void hashtable_print(hashtable_t *hash_table, FILE *fp, void (*itemprint)(FILE*, const char*, void*)) 
{
    if (fp && hash_table) {
        for (int i = 0; i < hash_table->size; i++) {
            fprintf(fp, "Bucket %d: ", i);
            set_print(hash_table->buckets[i], fp, itemprint);
            fprintf(fp, "\n");
        }
    } else 
    {
        fputs("(null)\n", fp);
    }
}

// Iterate over all items in the hash table
void hashtable_iterate(hashtable_t *hash_table, void *arg, void (*itemfunc)(void*, const char*, void*)) 
{
    if (hash_table && itemfunc) {
        for (int i = 0; i < hash_table->size; i++) {
            set_iterate(hash_table->buckets[i], arg, itemfunc);
        }
    }
}

// Delete the hash table and free its memory
void hashtable_delete(hashtable_t *hash_table, void (*itemdelete)(void*)) 
{
    if (hash_table) {
        for (int i = 0; i < hash_table->size; i++) {
            set_delete(hash_table->buckets[i], itemdelete);
        }
        free(hash_table->buckets);
        free(hash_table);
    }
}
