
//Implementacion de la estructura de datos "Listas enlazadas" en C

#include <stdio.h>
#include <stdlib.h>

//Definiendo las estructuras.

struct node{
    int element;
    struct node *next;
};

int ssize(int *size);
signed char isEmpty(int size);
void addFirst(int *size, int element, struct node **head);
void addLast(int *size, int element, struct node **head);
void showNodes(struct node *head);

int main(){

    int size = 0;
    struct node *head;

    addFirst(&size, 1, &head);
    //addFirst(&size, 2, head);
    //addFirst(&size, 3, head);
    //addFirst(&size, 4, head);
    addLast(&size, 2, &head);
    addLast(&size, 3, &head);
    addLast(&size, 4, &head);
    addLast(&size, 5, &head);

    showNodes(head);

    return 0;
}

void showNodes(struct node *head){
    
    while(head->next != NULL){
        printf("\nelemento %d", head->element);
        head = head->next;
    }
}

int ssize(int *size){
    return *size;
}

signed char isEmpty(int size){

    if(size == 0){
        return -1;
    }
    return 0;
}

void addFirst(int *size, int element, struct node **head){

    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->element = element;
    newNode->next = *head;
    *head = newNode; 
    (*size)++;
}

void addLast(int *size, int element, struct node **head){

    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->element = element;

    if(isEmpty(*size) == -1){ 
        *head = newNode;
        return;
    }

    struct node *currentNode = *head;
    
    while(currentNode->next != NULL){ 
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
    (*size)++;
}
