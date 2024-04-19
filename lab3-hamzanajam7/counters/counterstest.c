/*
* Hamza Najam
* file: counterstest.c
* cs50 lab3
* date: 04/19/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include "counters.h"

/* Forward declarations for utility functions */
static void print_counter(void *arg, const int key, int count);

/* Main function that performs a series of tests on the counters implementation */
int main(void) {
    /* Initialize the counters */
    counters_t *myCounters = counters_new();
    if (!myCounters) {
        fprintf(stderr, "Error: Could not initialize counters.\n");
        return EXIT_FAILURE;
    }

    /* Adding elements and setting values */
    printf("Adding elements and setting initial values...\n");
    for (int index = 0; index < 5; index++) {
        counters_add(myCounters, index);
        counters_set(myCounters, index, index * 2);
    }

    /* Test repetitive addition to the same key */
    printf("Performing multiple additions to a single key...\n");
    int keyToAdd = 3;
    for (int times = 1; times <= 20; times++) {
        counters_add(myCounters, keyToAdd);
    }

    /* Retrieving and displaying all counter values */
    printf("Retrieving and displaying all counter values...\n");
    for (int key = 0; key < 5; key++) {
        int count = counters_get(myCounters, key);
        printf("Key %d: Count = %d\n", key, count);
    }

    /* Display all counters */
    printf("Current state of all counters:\n");
    counters_print(myCounters, stdout);
    printf("\n");

    /* Using an iteration function to print each counter */
    printf("Iterating over all counters:\n");
    counters_iterate(myCounters, NULL, print_counter);

    /* Clean up and exit */
    printf("Deleting all counters and freeing memory...\n");
    counters_delete(myCounters);
    printf("All tests completed successfully.\n");

    return EXIT_SUCCESS;
}

/* Helper function to print the key and count during iteration */
static void print_counter(void *arg, const int key, int count) {
    printf("Key %d: Count %d\n", key, count);
}
