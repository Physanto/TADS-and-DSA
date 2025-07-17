#ifndef LINKED_LIST_INTERNAL_H

#define LINKED_LIST_INTERNAL_H

#include "../include/linked_list.h"

typedef struct Node{
    int element;
    struct Node *next;
    struct Node *prev;
}Node;

// por simplicidad se va manejar una estructura general de nodo, esta
// comparte los campos entre lista simple, circular y doblemente enlazada.
// el puntero que apunta un tipo Node llamado prev, solo se va usar en lista doblemente enlazada, de lo contrario permanecera en NULL.
//

typedef struct LinkedList{
    Node *head;
    Node *tail;
    int size;
    TypeList type;
}LinkedList;

Node *get(LinkedList *list, int index);
int get_wherever(LinkedList *list, int index, int *element);
Node *create_node(LinkedList *list, int element);
status destroy_circular_list(LinkedList **list);
status print_circular_list(LinkedList *list);
status print_linked_list(LinkedList *list);
void create_head_tail(LinkedList *list, Node *new_node);

#endif
