
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils/linked_list.h"


typedef struct Node{
    int element;
    struct Node *next_node;
    struct Node *prev_node;
}Node;

typedef struct LinkedList{
    struct Node *head;
    struct Node *tail;
    int size;
}LinkedList;

Node *get(LinkedList *, int);

LinkedList *create_linked_list(){
    
    LinkedList *list = malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

void destroyed_linked_list(LinkedList **list){

    if (list == NULL || *list == NULL) return;

    Node *current_node = (*list)->head; 

    while(current_node != NULL){ 

        Node *node_eliminated = current_node;
        current_node = current_node->next_node;

        free(node_eliminated);
    }
    free(*list);
    *list = NULL;
}

int size_list(LinkedList *list){
    return list->size;
}

bool is_empty(LinkedList *list){
    return list->size == 0 ? true : false;
}

void add_first(LinkedList *list, int element){

    Node *new_node = malloc(sizeof(struct Node));
    new_node->element = element;
    new_node->next_node = NULL;
    new_node->prev_node = NULL;

    if(is_empty(list)){ 
        list->head = new_node;
        list->tail = new_node;
        list->size++;
        return;
    }
    list->head->prev_node = new_node;
    new_node->next_node = list->head;
    list->head = new_node;
    list->size++;
}

int remove_first(LinkedList *list){

    if(is_empty(list)) return -1;

    Node *node_eliminated = list->head;
    int element_eliminated = node_eliminated->element; 

    if(list->size == 1){ 
        free(node_eliminated);
        list->head = NULL;
        list->tail = NULL;
        list->size--;
        return element_eliminated;
    }

    Node *node_next = list->head->next_node;
    node_next->prev_node = NULL;
    list->head = node_next;

    free(node_eliminated);
    list->size--;
    return element_eliminated;
}

void add_last(LinkedList *list, int element){ 

    Node *new_node = malloc(sizeof(struct Node));
    new_node->element = element;
    new_node->next_node = NULL;
    new_node->prev_node = NULL;

    if(is_empty(list)){ 
        list->head = new_node;
        list->tail = new_node;
        list->size++;
        return;
    }

    list->tail->next_node = new_node;
    new_node->prev_node = list->tail;
    list->tail = new_node;
    list->size++;
}

int remove_last(LinkedList *list){

    if(is_empty(list)) return -1;

    Node *node_eliminated = list->tail;
    int element_eliminated = node_eliminated->element;

    if(list->size == 1){
        free(node_eliminated);
        list->head = NULL;
        list->tail = NULL;
        list->size--;
        return element_eliminated;
    }

    Node *node_before = list->tail->prev_node;
    node_before->next_node = NULL;
    list->tail = node_before;

    free(node_eliminated);
    list->size--;
    return element_eliminated;
}

Node *get(LinkedList *list, int index){

    if(index < 0 || index >= list->size) return NULL;

    Node *node_find = list->head;

    for(int i = 0; i < list->size; i++){ 

        if(i == index){        
            return node_find;
        }
        node_find = node_find->next_node;
    }
    return NULL;
}

int get_at(LinkedList *list, int index){
    return get(list,index)->element;
}

int get_first(LinkedList *list){
    return list->head->element;
}

int get_last(LinkedList *list){
    return list->tail->element;
}

void insert_at(LinkedList *list, int index, int element){

    if(index < 0 || index > list->size){
        return;
    }

    Node *new_node = malloc(sizeof(struct Node));
    new_node->element = element;
    new_node->next_node = NULL;
    new_node->prev_node = NULL;

    // node_find es el nodo en la ubicacion donde se va insertar el nuevo
    Node *node_find = get(list,index);

    //node_before es el nodo anterior al node_find ya que el nodo anterior al encontrado debe apuntar al nuevo nodo.
    Node *node_before = node_find->prev_node;

    node_before->next_node = new_node;
    new_node->prev_node = node_find->prev_node;
    node_find->prev_node = new_node;
    new_node->next_node = node_find;
    list->size++;
}

void print_list(LinkedList *list){

    if(list == NULL){
        printf("\n La lista posiblemente ha sido liberada, no puedes ingresar datos\n");
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
        current_node = current_node->next_node;
    }
    printf("\n");
}
