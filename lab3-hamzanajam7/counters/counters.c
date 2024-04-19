/*
* Hamza Najam
* file: counter.c
* cs50 lab3
* date: 04/19/2024
*/

#include <stdlib.h>
#include <stdio.h>
#include "counters.h"

typedef struct cnode {
    int key;
    int count;
    struct cnode *next;
} cnode_t;

typedef struct counters {
    cnode_t *head;
} counters_t;

/* Forward declaration of private helper functions */
static cnode_t *new_cnode(int key);

/* Initialize a new counter collection */
counters_t* counters_new(void) {
    counters_t *new_counters = malloc(sizeof(counters_t));
    if (new_counters == NULL) {
        return NULL;
    }
    new_counters->head = NULL;
    return new_counters;
}

/* Increment or add a counter for the given key */
int counters_add(counters_t *counters, int key) {
    if (counters == NULL || key < 0) {
        return 0;
    }

    cnode_t **indirect = &(counters->head);
    while (*indirect != NULL) {
        if ((*indirect)->key == key) {
            return ++((*indirect)->count);
        }
        indirect = &((*indirect)->next);
    }

    *indirect = new_cnode(key);
    return (*indirect) ? (*indirect)->count : 0;
}

/* Get the count for a given key */
int counters_get(counters_t *counters, int key) {
    if (counters == NULL || key < 0) {
        return 0;
    }

    cnode_t *current = counters->head;
    while (current) {
        if (current->key == key) {
            return current->count;
        }
        current = current->next;
    }
    return 0;
}

/* Set the count for a given key */
bool counters_set(counters_t *counters, int key, int count) {
    if (counters == NULL || key < 0 || count < 0) {
        return false;
    }

    for (cnode_t *node = counters->head; node != NULL; node = node->next) {
        if (node->key == key) {
            node->count = count;
            return true;
        }
    }
    return false;
}

/* Print all counters to the given file */
void counters_print(counters_t *counters, FILE *fp) {
    if (counters == NULL) {
        fprintf(fp, "(null)");
        return;
    }
    if (fp != NULL) {
        fputc('{', fp);
        for (cnode_t *node = counters->head; node; node = node->next) {
            fprintf(fp, "%d=%d", node->key, node->count);
            if (node->next) {
                fprintf(fp, ", ");
            }
        }
        fputc('}', fp);
    }
}

/* Apply a function to each counter */
void counters_iterate(counters_t *counters, void *arg, void (*func)(void*, int, int)) {
    if (counters && func) {
        for (cnode_t *node = counters->head; node; node = node->next) {
            func(arg, node->key, node->count);
        }
    }
}

/* Delete all counters and free the structure */
void counters_delete(counters_t *counters) {
    if (counters) {
        cnode_t *current = counters->head;
        while (current) {
            cnode_t *next = current->next;
            free(current);
            current = next;
        }
        free(counters);
    }
}

/* Helper function to create a new node */
static cnode_t *new_cnode(int key) {
    cnode_t *node = malloc(sizeof(cnode_t));
    if (node == NULL) {
        return NULL;
    }
    node->key = key;
    node->count = 1;
    node->next = NULL;
    return node;
}
