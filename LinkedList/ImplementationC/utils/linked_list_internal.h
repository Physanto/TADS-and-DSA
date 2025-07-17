#ifndef LINKED_LIST_INTERNAL_H

#define LINKED_LIST_INTERNAL_H

#include "linked_list.h"

typedef struct Node{
    int element;
    struct Node *next;
    struct Node *prev;
}Node;

// por simplicidad se va manejar una estructura general de nodo, esta
// comparte los campos entre lista simple, circular y doblemente enlazada.
// el puntero que apunta un tipo Node llamado prev, solo se va usar en lista doblemente enlazada, de lo contrario permanecera en NULL.

typedef struct LinkedList{
    Node *head;
    Node *tail;
    int size;
    TypeList type;
}LinkedList;

status add_first_singly(LinkedList *list, int element);
status add_first_circular(LinkedList *list, int element);
status add_first_doubly(LinkedList *list, int element);

status add_last_singly(LinkedList *list, int element);
status add_last_circular(LinkedList *list, int element);
status add_last_doubly(LinkedList *list, int element);

status remove_first_singly(LinkedList *list, int *element_eliminated);
status remove_first_circular(LinkedList *list, int *element_eliminated);
status remove_first_doubly(LinkedList *list, int *element_eliminated);

status remove_last_singly(LinkedList *list, int *element_eliminated);
status remove_last_circular(LinkedList *list, int *element_eliminated);
status remove_last_doubly(LinkedList *list, int *element_eliminated);

status remove_at_singly(LinkedList *list, int index, int *element_eliminated);
status remove_at_circular(LinkedList *list, int index, int *element_eliminated);
status remove_at_doubly(LinkedList *list, int index, int *element_eliminated);

status insert_at_singly(LinkedList *list, int index, int element);
status insert_at_circular(LinkedList *list, int index, int element);
status insert_at_doubly(LinkedList *list, int index, int element);

Node *get(LinkedList *list, int index);
int get_wherever(LinkedList *list, int index, int *element);
Node *create_node(LinkedList *list, int element);
status destroy_circular_list(LinkedList **list);
status print_circular_list(LinkedList *list);
status print_linked_list(LinkedList *list);
void create_head_tail(LinkedList *list, Node *new_node);

#endif
