/*
* Hamza Najam
* file: hashtabletest.c
* cs50 lab3
* date: 04/19/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "file.h"

// Forward declarations for utility functions
static void item_print(FILE *fp, const char *key, void *item);
static void item_delete(void *item); // No operation needed, placeholder for consistency

int main(void) 
{
    // Creating a new hashtable with 10 slots
    printf("Creating hashtable...\n");
    hashtable_t *hashtable = hashtable_new(10);
    if (hashtable == NULL) 
    {
        fprintf(stderr, "Error: Failed to create a new hashtable.\n");
        return EXIT_FAILURE;
    }

    // Insert key-item pairs into the hashtable
    char *keys[] = {"K1", "K2", "K3", "K4", "K5"};
    char *values[] = {"V1", "V2", "V3", "V4", "V5"};

    printf("Inserting items...\n");
    for (int i = 0; i < 5; i++) 
    {
        if (!hashtable_insert(hashtable, keys[i], values[i])) 
        {
            fprintf(stderr, "Error: Insertion failed for key %s.\n", keys[i]);
        }
    }

    // Testing item retrieval
    printf("\nTesting hashtable_find...\n");
    for (int i = 0; i < 5; i++) {
        char *found = hashtable_find(hashtable, keys[i]);
        if (found) {
            printf("Item found for key %s: %s\n", keys[i], found);
        } else {
            printf("No item found for key: %s\n", keys[i]);
        }
    }

    // Test printing functionality
    printf("\nTesting hashtable_print...\n");
    hashtable_print(hashtable, stdout, item_print);

    // Clean up and free resources
    printf("\nDeleting hashtable...\n");
    hashtable_delete(hashtable, item_delete);
    printf("Hashtable tests completed.\n");

    return EXIT_SUCCESS;
}

// Print function for a key-item pair
static void item_print(FILE *fp, const char *key, void *item) 
{
    if (item) 
    {
        fprintf(fp, "%s: %s\n", key, (char*) item);
    }
}

// Delete function for an item
static void item_delete(void *item) 
{
    // Function is a placeholder as items are not dynamically allocated
}
