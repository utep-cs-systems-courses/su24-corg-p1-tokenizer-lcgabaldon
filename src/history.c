#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/* Initialize the linked list to keep the history. */
List* init_history() {
    List *new = (List*)malloc(sizeof(List));
    new->root = NULL;
    return new;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str) {
    Item *new_item = (Item*)malloc(sizeof(Item));
    new_item->str = strdup(str); // Make a copy of the string
    new_item->next = NULL;

    if (list->root == NULL) {
        new_item->id = 1;
        list->root = new_item;
    } else {
        Item *temp = list->root;
        int count = 1;
        while (temp->next != NULL) {
            temp = temp->next;
            count++;
        }
        new_item->id = count + 1;
        temp->next = new_item;
    }
}

char *get_history(List *list, int id) {
    Item *temp = list->root;
    while (temp != NULL) {
        if (temp->id == id)
            return temp->str;
        temp = temp->next;
    }
    return "Not found";
}

void print_history(List *list) {
    Item *temp = list->root;
    while (temp != NULL) {
        printf("%d: %s\n", temp->id, temp->str);
        temp = temp->next;
    }
}

/* Free the history list and the strings it references. */
void free_history(List *list) {
    Item *temp = list->root;
    while (temp != NULL) {
        Item *next = temp->next;
        free(temp->str); // Free the string
        free(temp);      // Free the item
        temp = next;
    }
    free(list); // Free the list
}
