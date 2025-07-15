#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils/linked_list.h"

// Estructuras de datos

typedef struct Node{
    int element;
    struct Node *next;
}Node;

typedef struct LinkedList{
    struct Node *head;
    struct Node *tail;
    int size;
}LinkedList;

void create_head_tail(LinkedList *list, Node *new_node);
Node *get(LinkedList *list, int index);


LinkedList *create_linked_list(){

    LinkedList *linked_list =malloc(sizeof(struct LinkedList));
    linked_list->head = NULL;
    linked_list->tail = NULL;
    linked_list->size = 0;

    return linked_list;
}

status destroyed_linked_list(LinkedList **list){

    if(list == NULL || *list == NULL) return ERR_NULL_PTR;

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

int size_list(LinkedList *list){

    if(list == NULL) return -1;
    return list->size;
}

bool is_empty(LinkedList *list){
    if(list == NULL) return true;
    return list->size == 0 ? true : false;
}

status add_first(LinkedList *list, int element){
    
    if(list == NULL) return ERR_NULL_PTR;

    struct Node *new_node = malloc(sizeof(struct Node));
    if(new_node == NULL) return ERR_MEM_ALLOC;

    new_node->element = element;
    new_node->next = NULL;

    if(is_empty(list)){  
        create_head_tail(list, new_node);
        return OK;
    }

    new_node->next = list->head;
    list->head = new_node;
    list->size++;

    return OK;
}

status remove_first(LinkedList *list, int *element_eliminated){
    
    if(list == NULL || element_eliminated == NULL) return ERR_NULL_PTR;

    if(is_empty(list)) return ERR_LIST_EMPTY; 

    Node *node_eliminated = list->head;
    *element_eliminated = node_eliminated->element;

    list->head = node_eliminated->next;

    if(list->head == NULL) list->tail = NULL;
    
    free(node_eliminated);
    list->size--;

    return OK;
}

status add_last(LinkedList *list, int element){

    if(list == NULL) return ERR_NULL_PTR;

    Node *new_node = malloc(sizeof(struct Node));
    if(new_node == NULL) return ERR_MEM_ALLOC;

    new_node->element = element;
    new_node->next = NULL;

    if(is_empty(list)){ 
        create_head_tail(list, new_node);
        return OK;
    } 
    
    list->tail->next = new_node;
    list->tail = new_node;
    list->size++;

    return OK;
}

status remove_last(LinkedList *list, int *element_eliminated){

    if(list == NULL || element_eliminated == NULL) return ERR_NULL_PTR;

    if(is_empty(list)) return ERR_LIST_EMPTY; 
    
    struct Node *node_eliminated = list->tail;
    *element_eliminated = node_eliminated->element;

    if(list->head == list->tail){
        free(node_eliminated);
        list->head = NULL;
        list->tail = NULL;
        list->size--;
        return OK;
    }

    Node *current_node = get(list, list->size-2);

    if(current_node == NULL) return ERR_INDEX_OUT_RANGE;

    current_node->next = NULL;
    list->tail = current_node;
    free(node_eliminated);
    node_eliminated = NULL;

    list->size--;

    return OK;
}

status print_list(LinkedList *list){

    if(list == NULL) return ERR_NULL_PTR;

    if(is_empty(list)) return ERR_LIST_EMPTY;

    int i = 0;
    struct Node *current_node = list->head; 

    while(current_node != NULL){
        printf("Nodo %d tiene el elemento: %d\n",(++i), current_node->element);
        current_node = current_node->next;
    }
    printf("\n");

    return OK;
}

status insert_at(LinkedList *list, int index, int element){

    if(list == NULL) return ERR_NULL_PTR;

    if(index < 0 || index > list->size) return ERR_INDEX_OUT_RANGE;

    Node *new_node = malloc(sizeof(struct Node));
    if(new_node == NULL) return ERR_MEM_ALLOC;

    new_node->element = element;
    new_node->next = NULL;

    if(is_empty(list)){
        create_head_tail(list,new_node);
        return OK;
    }

    if(index == 0){ 
        new_node->next = list->head;
        list->head = new_node;
        list->size++;
        return OK;
    }

    Node *node_find = get(list, index-1);
    if(node_find == NULL) return ERR_INDEX_OUT_RANGE;

    new_node->next = node_find->next;
    node_find->next = new_node; 

    if(index == list->size) list->tail = new_node;

    list->size++;

    return OK;
}

status remove_at(LinkedList *list, int index, int *element_eliminated){

    if(list == NULL || element_eliminated == NULL) return ERR_NULL_PTR;

    if(is_empty(list)) return ERR_LIST_EMPTY;
    
    if(index < 0 || index >= list->size) return ERR_INDEX_OUT_RANGE;

    Node *node_eliminated;
 
    if(list->size == 1){ 
        node_eliminated = list->head;
        *element_eliminated = node_eliminated->element;
        free(node_eliminated); 
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
        return OK;
    }

    if(index == 0){ 
        node_eliminated = list->head;
        *element_eliminated = node_eliminated->element;

        list->head = node_eliminated->next;

        free(node_eliminated);
        node_eliminated = NULL;

        list->size--;
        return OK;
    } 

    Node *node_prev_find = get(list, index-1);

    if(node_prev_find == NULL) return ERR_INDEX_OUT_RANGE;

    node_eliminated = node_prev_find->next;
    *element_eliminated = node_eliminated->element;
    node_prev_find->next = node_eliminated->next;

    if(index == list->size-1) list->tail = node_prev_find;

    free(node_eliminated);

    list->size--;

    return OK;
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

Node *get(LinkedList *list, int index){

    if(list == NULL || (index < 0 || index >= list->size)) return NULL;

    Node *node_find = list->head;

    for(int i = 0; i < index; i++){
        node_find = node_find->next;
    }
    return node_find;
}

void create_head_tail(LinkedList *list, Node *new_node){
    list->head = new_node;
    list->tail = new_node; //
    list->size++;
}

