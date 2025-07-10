#include <stdio.h>
#include <stdlib.h>

// Estructuras de datos

struct node{
    int element;
    struct node *next;
};

// Prototipos de las funciones necesarias

int size(int size);
signed char isEmpty(int size);
void addFirst(int element, int *size, struct node **head, struct node **tail);
void addLast(int element, int *size, struct node **head, struct node **tail);
int removeFirst(int *size, struct node **head, struct node **tail);
int removeLast(int *size, struct node **head, struct node **tail);
void showNodes(int size, struct node *nodeRecovering);

int main(){

    int size = 0;

    struct node *head = NULL;
    struct node *tail = NULL;

    addLast(3, &size, &head, &tail);
    addLast(4, &size, &head, &tail);
    addFirst(1, &size, &head, &tail);
    addFirst(2, &size, &head, &tail);

    printf("\nELEMENTOS ANNADIDOS\n");
    showNodes(size,head);

    return 0;
}

void showNodes(int size, struct node *nodeRecovering){ 

    int i = 0;
    
    while(nodeRecovering != NULL){
        /*if(i == 2){  
            printf("\nEste es el nodo %d y la direccion de memoria es: %p", (++i),nodeRecovering);
            continue;
        }*/
        printf("\nEste es el nodo %d y tiene un valor de: %d", (++i),nodeRecovering->element);
        nodeRecovering = nodeRecovering->next;
    }
    printf("\n");
}

int size(int size){
    return size;
}

signed char isEmpty(int size){
    return size == 0 ? -1 : 0;
}

void addFirst(int element, int *size, struct node **head, struct node **tail){

    struct node *newNode = malloc(sizeof(struct node));
    newNode->element = element;
    newNode->next = NULL;

    if(isEmpty(*size) == -1){  
        *head = newNode;
        *tail = *head;
        (*size)++;
        return;
    }

    newNode->next = *head;
    *tail = *head;
    *head = newNode;
    (*size)++;
    return;
}

void addLast(int element, int *size, struct node **head, struct node **tail){

    struct node *newNode = malloc(sizeof(struct node));
    newNode->element = element;
    newNode->next = NULL;

    if(isEmpty(*size) == -1){ 
        *head = newNode;
        *tail = *head;
        (*size)++;
        return;
    } 
    
    (*tail)->next = newNode;
    *tail = newNode;
    (*size)++;
    return;
}
