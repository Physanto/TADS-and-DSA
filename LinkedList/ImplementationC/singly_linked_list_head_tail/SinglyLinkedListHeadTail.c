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

    if(list == NULL) return ERR_NULL_PTR;

    Node *current_node = (*list)->head;

    while(current_node != NULL){
        Node *node_eliminated = current_node->next;
        free(current_node);
        current_node = node_eliminated->next;
    }
    (*list)->head = NULL;
    (*list)->tail = NULL;
    (*list)->size = 0;
    free(*list);
    *list = NULL;

    return OK;
}

status size_list(LinkedList *list){

    if(list == NULL) return ERR_NULL_PTR;
    return list->size;
}

bool is_empty(LinkedList *list){
    return list->size == 0 ? true : false;
}

void add_first(LinkedList *list, int element){

    Node *new_node = malloc(sizeof(struct Node));
    new_node->element = element;
    new_node->next = NULL;

    if(is_empty(list)){  
        create_head_tail(list, new_node); 
        return;
    }

    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

int remove_first(LinkedList *list){

    if(is_empty(list)) return -1; 

    Node *node_eliminated = list->head;
    int element_eliminated = node_eliminated->element;

    list->head = node_eliminated->next;

    if(list->head == NULL) list->tail = NULL;
    
    free(node_eliminated);
    node_eliminated = NULL;
    list->size--;
    return element_eliminated;
}

void add_last(LinkedList *list, int element){

    Node *new_node = malloc(sizeof(struct Node));
    new_node->element = element;
    new_node->next = NULL;

    if(is_empty(list)){ 
        create_head_tail(list, new_node);
        return;
    } 
    
    list->tail->next = new_node;
    list->tail = new_node;
    list->size++;
}

int remove_last(LinkedList *list){

    if(is_empty(list)) return -1;

    Node *node_eliminated = list->tail;
    int element_eliminated = node_eliminated->element;

    if(list->head == list->tail){
        free(node_eliminated);
        node_eliminated = NULL;
        list->size--;
        return element_eliminated;
    }

    Node *current_node = list->head;

    while(current_node->next != list->tail){
        current_node = current_node->next;    
    }

    current_node->next = NULL;
    list->tail = current_node;
    free(node_eliminated);
    node_eliminated = NULL;
    list->size--;
    return element_eliminated;
}

void print_list(LinkedList *list){

    if(list == NULL){
        printf("\nLa lista posiblemente ha sido liberada, no puedes ingresar datos\n");
        return;
    }

    if(is_empty(list)){
        printf("\nLa lista esta vacia, no hay nada que mostrar\n");
        return;
    }

    int i = 0;
    struct Node *current_node = list->head; 

    while(current_node != NULL){
        printf("Nodo %d tiene el elemento: %d\n",(++i), current_node->element);
        current_node = current_node->next;
    }
    printf("\n");
}

void insert_at(LinkedList *list, int index, int element){

    if(index < 0 || index > list->size) return;

    Node *new_node = malloc(sizeof(struct Node));
    new_node->element = element;
    new_node->next = NULL;

    if(is_empty(list)){
        create_head_tail(list,new_node);
        return;
    }

    if(index == 0){ 
        new_node->next = list->head;
        list->head = new_node;
        list->size++;
        return;
    }

    if(index == list->size){
        list->tail->next = new_node;
        list->tail = new_node;
        list->size++;
        return;
    }

    Node *node_find = get(list, index-1);
    Node *node_aux = node_find->next;
    node_find->next = new_node; 
    new_node->next = node_aux;
    list->size++;
}

int remove_at(LinkedList *list, int index){

    if(index < 0 || index > list->size) return -1;

    if(is_empty(list)) return -1;

    Node *node_eliminated = list->head;
    int element_eliminated;
    
    if(list->size == 1){ 
        element_eliminated = node_eliminated->element;
        free(node_eliminated); 
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
        return element_eliminated;
    }

    if(index == 0){ 
        element_eliminated = node_eliminated->element;

        list->head = node_eliminated->next;

        free(node_eliminated);
        node_eliminated = NULL;

        list->size--;
        return element_eliminated;
    } 

    Node *node_prev_find = get(list, index-1);

    node_eliminated = node_prev_find->next;
    element_eliminated = node_eliminated->element;

    node_prev_find->next = node_eliminated->next;

    if(index == list->size-1) list->tail = node_prev_find;

    free(node_eliminated);
    node_eliminated = NULL;
    list->size--;

    return element_eliminated;
}

int get_first(LinkedList *list){
    return list->head->element;
}

int get_last(LinkedList *list){
    return list->tail->element;
}

int get_at(LinkedList *list, int index){
    return get(list, index)->element;
}


Node *get(LinkedList *list, int index){

    if(index < 0 || index >= list->size) return NULL;

    Node *node_find = list->head;

    for(int i = 0; i < list->size; i++){

        if(i == index){
            return node_find;
        }
        node_find = node_find->next;
    }
    return NULL;
}

void create_head_tail(LinkedList *list, Node *new_node){
    list->head = new_node;
    list->tail = new_node; //
    list->size++;
}

