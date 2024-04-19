/*
* Hamza Najam
* file: set.c
* cs50 lab3
* date: 04/19/2024
* Description: This module defines a set structure with functionality to add, find, print, iterate over, and delete items.
*/

#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"

/**************** Local Types ****************/
typedef struct snode 
{
    char* key;
    void* item;
    struct snode *next;
} snode_t;

/**************** Global Types ****************/
typedef struct set 
{
    snode_t *head;
} set_t;

/**************** Functions ****************/

// Create a new set
set_t *set_new(void) 
{
    set_t *set = malloc(sizeof(set_t));
    if (!set) {
        return NULL; // Return NULL on memory allocation failure
    }
    set->head = NULL;
    return set;
}

// Insert a new key-item pair into the set
bool set_insert(set_t* set, const char* key, void* item) 
{
    if (!set || !key || !item || set_find(set, key) != NULL) 
    {
        return false; // Prevent insertion of duplicates or if any pointer is NULL
    }

    snode_t *new_node = malloc(sizeof(snode_t));
    if (!new_node) 
    {
        return false; // Return false on memory allocation failure
    }

    new_node->key = strdup(key); // Duplicate the key for safe storage
    if (!new_node->key) 
    {
        free(new_node);
        return false; // Clean up and return false if key duplication fails
    }

    new_node->item = item; // Attach the item
    new_node->next = set->head; // Insert at the beginning of the list
    set->head = new_node;

    return true;
}

// Find an item by its key in the set
void* set_find(set_t* set, const char* key) 
{
    if (!set || !key) 
    {
        return NULL; // Return NULL if set or key is NULL
    }

    for (snode_t* node = set->head; node; node = node->next) 
    {
        if (strcmp(node->key, key) == 0) {
            return node->item; // Return the item if the key matches
        }
    }
    return NULL; // Return NULL if no match is found
}

// Print the contents of the set
void set_print(set_t* set, FILE* fp, void (*itemprint)(FILE*, const char*, void*)) 
{
    if (fp && set) {
        fprintf(fp, "{");
        for (snode_t* node = set->head; node; node = node->next) {
            if (itemprint) 
            {
                itemprint(fp, node->key, node->item); // Use itemprint to display each node
                if (node->next) fprintf(fp, ", ");
            }
        }
        fprintf(fp, "}\n");
    } else {
        fputs("(null)\n", fp);
    }
}

// Iterate through each item in the set
void set_iterate(set_t* set, void* arg, void (*itemfunc)(void*, const char*, void*)) 
{
    if (set && itemfunc) {
        for (snode_t* node = set->head; node; node = node->next) 
        {
            itemfunc(arg, node->key, node->item); // Apply itemfunc to each node
        }
    }
}

// Delete the set and free all memory
void set_delete(set_t* set, void (*itemdelete)(void*)) 
{
    if (set) {
        snode_t *node = set->head;
        while (node) {
            snode_t *next = node->next;
            if (itemdelete) {
                itemdelete(node->item); // Use itemdelete if provided
            }
            free(node->key);
            free(node);
            node = next;
        }
        free(set);
    }
}
