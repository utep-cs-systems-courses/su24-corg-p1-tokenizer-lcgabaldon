#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/* Initialize the linked list to keep the history. */
List* init_history() {
    List *new = (List*)malloc(sizeof(List));
    new -> root = NULL;
    return new;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str) {
    Item *new_item = (Item*)malloc(sizeof(Item));

    Item *temp = (Item*)malloc(sizeof(Item));
    temp = list->root;
    new -> str = str;
    new -> next = NULL;

    while (temp != NULL) {
        
    }
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id) {

}

/*Print the entire contents of the list. */
void print_history(List *list) {

}

/*Free the history list and the strings it references. */
void free_history(List *list) {

}