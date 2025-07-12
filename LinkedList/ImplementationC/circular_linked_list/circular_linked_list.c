#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils/linked_list.h"

typedef struct Node{
    int element;
    struct Node *nextNode;
}Node;

typedef struct LinkedList{
    struct Node *head;
    struct Node *tail;
    int size;
}LinkedList;

LinkedList *create_linked_list(){ 

    LinkedList *new_linked_list = malloc(sizeof(struct LinkedList));
    new_linked_list->head = NULL;
    new_linked_list->tail = NULL;
    new_linked_list->size = 0;

    return new_linked_list;
}

void destroyed_linked_list(LinkedList **list){

    struct Node *current = (*list)->head;

    while(current != NULL){ 
        Node *nextNode = current->nextNode;
        free(current);
        current = nextNode;
    }
    free(list);
    *list = NULL;
}

int size_list(LinkedList *list){
    if(list == NULL) return 0;
    return list->size;
}

bool is_empty(LinkedList *list){
    return list->size == 0 ? true : false;
}

void add_first(LinkedList *list, int element){ 

    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->element = element;
    new_node->nextNode = NULL;

    if(is_empty(list)){
        list->head = new_node;
        list->tail = new_node;
        list->tail->nextNode = list->head;
        list->size++;
        return;
    }

    new_node->nextNode = list->head;
    list->head = new_node;
    list->size++;
}

int remove_first(LinkedList *list){

    if(is_empty(list)) return -1; 

    Node *nodeEliminated = list->head;
    int elementEliminated = list->head->element;


    if(list->size == 1){
        free(list->head); //head y tail apuntan a lo mismo asi que solo se libera alguno.
        list->head = NULL;
        list->tail = NULL;
        list->size--;
        return elementEliminated;
    }

    list->head = nodeEliminated->nextNode; 
    list->tail->nextNode = list->head;
    free(nodeEliminated);
    nodeEliminated = NULL;
    list->size--;
    return elementEliminated;
}

void add_last(LinkedList *list, int element){ 

    Node *newNode = malloc(sizeof(struct Node));
    newNode->element = element;
    newNode->nextNode = NULL;

    if(is_empty(list)){  
        list->head = newNode;
        list->tail = newNode;
        list->size++;
        return;
    }

    list->tail->nextNode = newNode;
    list->tail = newNode;
    list->tail->nextNode = list->head;
    list->size++;
}

int remove_last(LinkedList *list){

    if(is_empty(list)) return -1; 
    
    struct Node *nodeEliminated = list->tail;
    int elementEliminated = list->tail->element;


    if(list->size == 1){ 
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->size--;
        return elementEliminated;
    }

    struct Node *currentNode = list->head;

    while(currentNode->nextNode != list->tail){ 
        currentNode = currentNode->nextNode;
    }

    list->tail = currentNode;
    list->tail->nextNode = list->head;
    free(nodeEliminated);
    list->size--;
    return elementEliminated;
}

void print_list(LinkedList *list){ 

    if(is_empty(list)){
        printf("\nLa lista esta vacia, no hay nada que mostrar\n");
        return;
    }

    int i = 0;
    struct Node *currentNode = list->head; 

    while(currentNode->nextNode != list->head){
        printf("Nodo %d tiene el elemento: %d\n",(++i), currentNode->element);
        currentNode = currentNode->nextNode;
    }
    printf("Nodo %d tiene el elemento: %d\n",(++i), currentNode->element);

}
