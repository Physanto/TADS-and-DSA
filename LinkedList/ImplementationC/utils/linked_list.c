#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../utils/linked_list.h"

typedef enum{
    LIST_SINGLY,
    LIST_CIRCULAR,
    LIST_DOUBLY
}TypeList;

typedef struct Node{
    int element;
    struct Node *next;
}Node;

typedef struct LinkedList{
    Node *head;
    Node *tail;
    int size;
    TypeList types;
}LinkedList;


Node *get(LinkedList *list, int index);
int get_wherever(LinkedList *list, int index, int *element);
Node *creat_node(LinkedList *list, int element);
static status destroy_singly_list(LinkedList **list);
static status destroy_circular_list(LinkedList **list);
static status destroy_doubly_list(LinkedList **list);

LinkedList *create_linked_list(){ 

    LinkedList *new_linked_list = malloc(sizeof(struct LinkedList));
    new_linked_list->head = NULL;
    new_linked_list->tail = NULL;
    new_linked_list->size = 0;

    return new_linked_list;
}

status destroy_linked_list(LinkedList **list){
    
    if(list == NULL || *list == NULL) return ERR_NULL_PTR;

    if(is_empty(*list)){
        (*list)->head = NULL;
        (*list)->tail= NULL;
        (*list)->size = 0;
        free(*list);
        *list = NULL;
        return OK;
    }

    switch((*list)->types){

        case LIST_SINGLY:
            return destroy_singly_list(list);

        case LIST_CIRCULAR:
            return destroy_circular_list(list);

        case LIST_DOUBLY:
            return destroy_doubly_list(list);
    }
}

static status destroy_singly_list(LinkedList **list){

    Node *current_node = (*list)->head;

    while(current_node != NULL){
        Node *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }

    (*list)->head = NULL;
    (*list)->tail = NULL;
    (*list)->size = 0;
    free(*list);
    *list = NULL;

    return OK;
}

static status destroy_circular_list(LinkedList **list){ 

    Node *current_node = (*list)->head;
    Node *next_node;

    do{ 
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    while(current_node != (*list)->head);

    (*list)->head = NULL;
    (*list)->tail = NULL;
    free(*list); 
    *list = NULL; 

    return OK;
}

int size_list(LinkedList *list){
    if(list == NULL) return -1;
    return list->size;
}

bool is_empty(LinkedList *list){
    if(list == NULL) return true;
    return list->size == 0 ? true : false;
}

Node *get(LinkedList *list, int index){

    if(list == NULL || (index < 0 || index >= list->size)) return NULL;

    Node *node_find = list->head;

    for(int i = 0; i < index; i++){
        node_find = node_find->next;
    }
    return node_find;
}

int get_wherever(LinkedList *list, int index, int *element){

    if(list == NULL || element == NULL) return ERR_NULL_PTR;

    if(is_empty(list)) return ERR_LIST_EMPTY;

    if(index < 0 || index >= list->size) return ERR_INDEX_OUT_RANGE;

    Node *node = get(list,index);

    if(node == NULL) return ERR_NULL_PTR;

    *element = node->element;

    return OK;
}

status get_first(LinkedList *list, int *first_element){ 
    return get_wherever(list, 0, first_element);
}

status get_last(LinkedList *list, int *last_element){
    return get_wherever(list, list->size-1, last_element); 
}

status get_at(LinkedList *list, int index, int *element_at){
    return get_wherever(list, index, element_at); 
}

void create_head_tail(LinkedList *list, Node *new_node){
    list->head = new_node;
    list->tail = new_node;
    list->size++;
}
status print_list(LinkedList *list){

    if(list == NULL) return ERR_NULL_PTR;

    if(is_empty(list)) return ERR_LIST_EMPTY;

    int i = 0;
    Node *current_node = list->head; 

    while(current_node != NULL){
        printf("Nodo %d tiene el elemento: %d\n",(++i), current_node->element);
        current_node = current_node->next;
    }
    printf("\n");

    return OK;
}

Node *create_node(LinkedList *list, int element){

    Node *new_node = malloc(sizeof(struct Node));
    new_node->element = element;
    new_node->next = NULL;

    return new_node;
}

