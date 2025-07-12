
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "linked_list.h"

struct LinkedList *linked_list;
struct Node *node;

int main(){

    linked_list->head = NULL;
    linked_list->tail = NULL;
    linked_list->size = 0;

    add_first(1);
    add_first(2);
    add_first(3);
    add_first(4);

    print_list();

    return 0;
}

int size_list(){
    return linked_list->size;
}

bool is_empty(){
    return linked_list->size == 0 ? true : false;
}

void add_first(int element){ 

    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->element = element;
    new_node->nextNode = NULL;

    if(is_empty()){
        linked_list->head = new_node;
        linked_list->tail = new_node;
        linked_list->size++;
        return;
    }

    new_node->nextNode = linked_list->head;
    linked_list->head = new_node;
    linked_list->size++;
}

void print_list(){ 

    int i = 0;
    struct Node *currentNode = linked_list->head; 

    while(currentNode->nextNode != NULL){
        printf("\n Nodo %d tiene el elemento: %d\n",(++i), currentNode->element);
        currentNode = currentNode->nextNode;
    }
    printf("\n");

}
