/*
* Hamza Najam
* file: settest.c
* cs50 lab3
* date: 04/19/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "set.h"
#include <string.h>


// Function to print items
void itemprint(FILE* fp, const char* key, void* item) 
{
    char* item_printed = item;
    fprintf(fp, "(%s, %s)", key, item_printed);
}

// Function to delete an item (assuming item is dynamically allocated)
void itemdelete(void* item) 
{
  if (item != NULL){
    free(item); // if there is any memory leak then there is an issue otherwise this is fine
  }
}

void iterationfunction(void *arg, const char *key, void *item) 
{
    char* item_printed = item;
    printf("%s:%s\n", key, item_printed);
}

//tests for the set module
int test_set(void) 
{
    // Test set_new()
    set_t* my_set = set_new();
    if (my_set == NULL){
      printf("my_set is NULL\n");
      return 1;
    }

    // Test set_insert()
    printf("Correct key and item insertion: ");
    char* item = "ferrari";
    char* test_key = "24";
    bool answer = set_insert(my_set, test_key, item);
    if (answer == false)
    {
      printf("No\n");
      return 2;
    } else {
      printf("Yes\n");
    }

    printf("Null param:  ");
    if ((set_insert(NULL,test_key,item) != false) || (set_insert(my_set, NULL, item) != false) || (set_insert(my_set, test_key, NULL) != false))
    {
      printf("Yes\n");
      return 3;
    }
    else 
    {
      printf("No\n");
    }


    // Test set_find
    printf("Items found: ");
    if (strcmp(set_find(my_set, test_key),item) == 0)
    {
      printf("Yes\n");
    }else {
      printf("No\n");
      return 4;
    }

    printf("Null set or Null in set: ");
    if ((set_find(my_set,NULL) == NULL) && (set_find(NULL, test_key) == NULL))
    {
      printf("Yes\n");
    }
    else {
      printf("No\n");
      return 5;
    }

    printf("Null return in case of valid sets/key: ");
    char* fake_key = "honda";
    if (set_find(my_set, fake_key) == NULL)
    {
      printf("Yes\n");
    }
    else 
    {
      printf("No\n");
      return 6;
    }

    // Test set_print
    printf("set printing...\n");
    set_print(my_set, stdout, itemprint);

    printf("testing set_print for null set\n");
    set_print(NULL, stdout, itemprint);

    printf("testing that set_print for null prints\n");
    set_print(my_set, stdout, NULL);


    // Test set_iterate
    printf("Iterating over the set...\n");
    set_iterate(my_set, stdout, iterationfunction);

    printf("Iteration with null iterationfunction\n");
    set_iterate(my_set, stdout, NULL);

    printf("Iteration with null set\n");
    set_iterate(NULL, stdout, iterationfunction);
    // Test set_delete

    printf("\n\nEnd of testing\n");
    set_delete(my_set,NULL);
    return 0;
}
int main(void) 
{
    // Running the tests
    return test_set();
}
