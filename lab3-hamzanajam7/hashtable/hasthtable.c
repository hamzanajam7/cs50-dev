/*
* Hamza Najam
* file: hashtable.c
* cs50 lab3
* date: 04/19/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "hashtable.h"
#include "../set/set.h"

typedef struct hashtable 
{
    set_t **buckets;
    int capacity;
} hashtable_t;

// Function to create a new hashtable with a specified number of buckets
hashtable_t* hashtable_new(int capacity) 
{
    if (capacity <= 0) {
        return NULL;
    }

    hashtable_t *ht = malloc(sizeof(hashtable_t));
    if (!ht) {
        return NULL;
    }

    ht->buckets = calloc(capacity, sizeof(set_t*));
    if (!ht->buckets) {
        free(ht);
        return NULL;
    }

    ht->capacity = capacity;
    for (int i = 0; i < capacity; i++) 
    {
        ht->buckets[i] = set_new();
        if (!ht->buckets[i]) {
            // Clean up previously allocated sets if initialization fails
            while (i-- > 0) {
                set_delete(ht->buckets[i], NULL);
            }
            free(ht->buckets);
            free(ht);
            return NULL;
        }
    }
    return ht;
}

// Function to insert a key-item pair into the hashtable
bool hashtable_insert(hashtable_t* ht, const char* key, void* item) 
{
    if (!ht || !key || !item) {
        return false;
    }
    int index = hash_jenkins(key, ht->capacity);
    return set_insert(ht->buckets[index], key, item);
}

// Function to find an item by its key in the hashtable
void* hashtable_find(hashtable_t* ht, const char* key) 
{
    if (!ht || !key) {
        return NULL;
    }
    int index = hash_jenkins(key, ht->capacity);
    return set_find(ht->buckets[index], key);
}

// Function to print the contents of the hashtable
void hashtable_print(hashtable_t* ht, FILE* fp, void (*itemprint)(FILE*, const char*, void*)) 
{
    if (!fp) 
    {
        fputs("Error: Output file pointer is null.\n", stderr);
        return;
    }
    if (ht) 
    {
        for (int i = 0; i < ht->capacity; i++) {
            fprintf(fp, "Bucket %d: ", i);
            set_print(ht->buckets[i], fp, itemprint);
            fprintf(fp, "\n");
        }
    } else 
    {
        fputs("Error: Hashtable is null.\n", fp);
    }
}

// Function to iterate over all items in the hashtable
void hashtable_iterate(hashtable_t* ht, void* arg, void (*itemfunc)(void*, const char*, void*)) 
{
    if (ht && itemfunc) 
    {
        for (int i = 0; i < ht->capacity; i++) 
        {
            set_iterate(ht->buckets[i], arg, itemfunc);
        }
    }
}

// Function to delete the hashtable and free its memory
void hashtable_delete(hashtable_t* ht, void (*itemdelete)(void*)) 
{
    if (ht) {
        for (int i = 0; i < ht->capacity; i++) 
        {
            set_delete(ht->buckets[i], itemdelete);
        }
        free(ht->buckets);
        free(ht);
    }
}

