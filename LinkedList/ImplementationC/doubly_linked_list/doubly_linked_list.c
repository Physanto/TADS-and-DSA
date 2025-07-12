
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../circular_linked_list/linked_list.h"


typedef struct Node{
    int element;
    struct Node *nextNode;
    struct Node *prevNode;
}Node;

typedef struct LinkedList{
    struct Node *head;
    struct Node *tail;
    int size;
}LinkedList;

//Node *get(LinkedList *, int index);


LinkedList *create_linked_list(){
    
    LinkedList *list = malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

int size_list(LinkedList *list){
    return list->size;
}

bool is_empty(LinkedList *list){
    return list->size == 0 ? true : false;
}

void add_first(LinkedList *list, int element){

    Node *newNode = malloc(sizeof(struct Node));
    newNode->element = element;
    newNode->nextNode = NULL;
    newNode->prevNode = NULL;

    if(is_empty(list)){ 
        list->head = newNode;
        list->tail = newNode;
        list->size++;
        return;
    }
    list->head->prevNode = newNode;
    newNode->nextNode = list->head;
    list->head = newNode;
    list->size++;
}

int remove_first(LinkedList *list){

    if(is_empty(list)) return -1;

    Node *nodeEliminated = list->head;
    int elementEliminated = nodeEliminated->element; 

    if(list->size == 1){ 
        free(nodeEliminated);
        nodeEliminated->nextNode = NULL;
        nodeEliminated->prevNode = NULL;
        list->size--;
        return elementEliminated;
    }

    Node *nodeNext= list->head->nextNode;
    nodeNext->prevNode = NULL;
    list->head = nodeNext;
    free(nodeEliminated);
    nodeEliminated->nextNode = NULL;
    nodeEliminated->prevNode = NULL;
    list->size--;
    return elementEliminated;
}

void add_last(LinkedList *list, int element){ 

    Node *newNode = malloc(sizeof(struct Node));
    newNode->element = element;
    newNode->nextNode = NULL;
    newNode->prevNode = NULL;

    if(is_empty(list)){ 
        list->head = newNode;
        list->tail = newNode;
        list->size++;
        return;
    }

    list->tail->nextNode = newNode;
    newNode->prevNode = list->tail;
    list->tail = newNode;
    list->size++;
}

int remove_last(LinkedList *list){

    if(is_empty(list)) return -1;

    Node *nodeEliminated = list->tail;
    int elementEliminated = nodeEliminated->element;

    if(list->size == 1){
        free(nodeEliminated);
        nodeEliminated->nextNode = NULL;
        nodeEliminated->prevNode = NULL;
        list->size--;
        return elementEliminated;
    }

    Node *nodeBefore = list->tail->prevNode;
    nodeBefore->nextNode = NULL;
    list->tail = nodeBefore;
    free(nodeEliminated);
    nodeEliminated->nextNode = NULL;
    nodeEliminated->prevNode = NULL;
    list->size--;
    return elementEliminated;
}

Node *get(LinkedList *list, int index){

    if(index < 0 || index >= list->size) return NULL;

    Node *nodeFind = list->head;

    for(int i = 0; i < list->size; i++){ 

        if(i == index){        
            return nodeFind;
        }
        nodeFind = nodeFind->nextNode;
    }
    return NULL;
}

int gett(LinkedList *list, int index){
    return get(list,index)->element;
}

void print_list(LinkedList *list){

    if(is_empty(list)){
        printf("\nLa lista esta vacia, no hay nada que mostrar\n");
        return;
    }

    int i = 0;
    struct Node *currentNode = list->head; 

    while(currentNode != NULL){
        printf("Nodo %d tiene el elemento: %d\n",(++i), currentNode->element);
        currentNode = currentNode->nextNode;
    }
    printf("\n");
}
