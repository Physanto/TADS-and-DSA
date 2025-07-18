#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../internal/linked_list_internal.h"

// TODO: realizar el refactoring de tener estructuras para las diferentes tipos de listas esto con el fin de una mayor eficiencia y para el ingreso de datos en masa.

LinkedList *create_linked_list(TypeList listType){ 

    LinkedList *new_linked_list = malloc(sizeof(LinkedList));
    if(new_linked_list == NULL) return NULL;

    new_linked_list->head = NULL;
    new_linked_list->tail = NULL;
    new_linked_list->size = 0;
    new_linked_list->type = listType;

    return new_linked_list; 
}

status add_first(LinkedList *list, int element){ 

    if(list == NULL) return ERR_NULL_PTR;

    switch(list->type){
        
        case LIST_SINGLY:
            return add_first_singly(list, element);

        case LIST_CIRCULAR:
            return add_first_circular(list, element);

        case LIST_DOUBLY:
            return add_first_doubly(list, element);

        default:
            return ERR_UKNOW_TYPE_LIST;
    }
}

status remove_first(LinkedList *list, int *element_eliminated){

    if(list == NULL) return ERR_NULL_PTR;

    switch(list->type){
        
        case LIST_SINGLY:
            return remove_first_singly(list, element_eliminated);

        case LIST_CIRCULAR:
            return remove_first_circular(list, element_eliminated);

        case LIST_DOUBLY:
            return remove_first_doubly(list, element_eliminated);

        default:
            return ERR_UKNOW_TYPE_LIST;
    }
}

status add_last(LinkedList *list, int element){ 

    if(list == NULL) return ERR_NULL_PTR;

    switch(list->type){
        
        case LIST_SINGLY:
            return add_last_singly(list, element);

        case LIST_CIRCULAR:
            return add_last_circular(list, element);

        case LIST_DOUBLY:
            return add_last_doubly(list, element);

        default:
            return ERR_UKNOW_TYPE_LIST;
    }
}

status remove_last(LinkedList *list, int *element_eliminated){ 

    if(list == NULL) return ERR_NULL_PTR;

    switch(list->type){
        
        case LIST_SINGLY:
            return remove_last_singly(list, element_eliminated);

        case LIST_CIRCULAR:
            return remove_last_circular(list, element_eliminated);

        case LIST_DOUBLY:
            return remove_last_doubly(list, element_eliminated);

        default:
            return ERR_UKNOW_TYPE_LIST;
    }
}

status remove_at(LinkedList *list, int index, int *element_eliminated){ 

    if(list == NULL) return ERR_NULL_PTR;

    switch(list->type){
        
        case LIST_SINGLY:
            return remove_at_singly(list, index, element_eliminated);

        case LIST_CIRCULAR:
            return remove_at_circular(list, index, element_eliminated);

        case LIST_DOUBLY:
            //return remove_at_doubly(list, index, element_eliminated);

        default:
            return ERR_UKNOW_TYPE_LIST;
    }
}

status insert_at(LinkedList *list, int index, int element){ 

    if(list == NULL) return ERR_NULL_PTR;

    switch(list->type){
        
        case LIST_SINGLY:
            return insert_at_singly(list, index, element);

        case LIST_CIRCULAR:
            return insert_at_circular(list, index, element);

        case LIST_DOUBLY:
            return insert_at_doubly(list, index, element);

        default:
            return ERR_UKNOW_TYPE_LIST;
    }
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

    switch((*list)->type){

        case LIST_CIRCULAR: 
            return destroy_circular_list(list);

        case LIST_SINGLY:
        case LIST_DOUBLY:{

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
        default:
            return ERR_UKNOW_TYPE_LIST;
    }
}

status destroy_circular_list(LinkedList **list){ 

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

status print_list(LinkedList *list){

    if(list == NULL) return ERR_NULL_PTR;

    if(is_empty(list)) return ERR_LIST_EMPTY;

    switch (list->type) {
        
        case LIST_SINGLY:
            return print_linked_list(list);

        case LIST_CIRCULAR:
            return print_circular_list(list);

        case LIST_DOUBLY:
            return print_linked_list(list);

        default:
            return ERR_UKNOW_TYPE_LIST;
    }
}

status print_linked_list(LinkedList *list){

    if(list == NULL) return ERR_NULL_PTR;

    if(is_empty(list)) return ERR_LIST_EMPTY;

    Node *current_node = list->head; 

    while(current_node != NULL){
        printf("[%d]->",current_node->element);
        current_node = current_node->next;
    }
    printf("NULL\n");

    return OK;
}

status print_circular_list(LinkedList *list){ 

    Node *current_node = list->head;

    do {

        printf("[%d]->",current_node->element);
        current_node = current_node->next;

    } while(current_node != list->head);

    printf("NULL\n");

    return OK;
}

Node *create_node(LinkedList *list, int element){

    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL) return NULL;

    if(list->type == LIST_DOUBLY){
        new_node->element = element;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    else{
        new_node->element = element;
        new_node->next = NULL;
    }
    return new_node;
}

void create_head_tail(LinkedList *list, Node *new_node){
    list->head = new_node;
    list->tail = new_node;
    list->size++;
}
