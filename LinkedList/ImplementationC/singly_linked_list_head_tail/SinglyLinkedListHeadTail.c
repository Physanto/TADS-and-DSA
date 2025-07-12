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
int removeFirst(int *size, struct node **head, struct node **tail);
void addLast(int element, int *size, struct node **head, struct node **tail);
int removeLast(int *size, struct node **tail, struct node **head);
void showNodes(int size, struct node *nodeRecovering);
void createHeadTail(int *size, struct node **head, struct node **tail, struct node *newNode);


int main(){

    int size = 0;

    struct node *head = NULL;
    struct node *tail = NULL;

    //addLast(3, &size, &head, &tail);
    addFirst(1, &size, &head, &tail);
    addFirst(2, &size, &head, &tail);
    addFirst(3, &size, &head, &tail);
    addLast(4, &size, &head, &tail);
    addLast(5, &size, &head, &tail);
    removeLast(&size, &tail, &head);
    removeLast(&size, &tail, &head);
    removeLast(&size, &tail, &head);
    removeFirst(&size,&head,&tail);
    removeFirst(&size,&head,&tail);
    removeFirst(&size,&head,&tail);
    removeLast(&size, &tail, &head);
    addFirst(10, &size, &head, &tail);
    addLast(6, &size, &head, &tail);
    addLast(100, &size, &head, &tail);
    addLast(51, &size, &head, &tail);

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
        createHeadTail(size, head, tail, newNode); 
        return;
    }

    newNode->next = *head;
    *head = newNode;
    (*size)++;
}

int removeFirst(int *size, struct node **head, struct node **tail){

    if(isEmpty(*size)) return -1; 

    struct node *nodeEliminated = *head;
    int elementEliminated = nodeEliminated->element;

    *head = nodeEliminated->next;

    if(*head == NULL) *tail = NULL;
    
    free(nodeEliminated);
    nodeEliminated = NULL;
    (*size)--;
    return elementEliminated;
}

void addLast(int element, int *size, struct node **head, struct node **tail){

    struct node *newNode = malloc(sizeof(struct node));
    newNode->element = element;
    newNode->next = NULL;

    if(isEmpty(*size) == -1){ 
        createHeadTail(size, head, tail, newNode);
        return;
    } 
    
    (*tail)->next = newNode;
    *tail = newNode;
    (*size)++;
}

int removeLast(int *size, struct node **tail, struct node **head){

    if(isEmpty(*size)) return -1;

    struct node *nodeEliminated = *tail;
    int elementEliminated = nodeEliminated->element;

    if(*head == *tail){
        free(nodeEliminated);
        *head = NULL;
        *tail = NULL;
        (*size)--;
        return elementEliminated;
    }

    struct node *currentNode = *head;

    while(currentNode->next != *tail){
        currentNode = currentNode->next;    
    }

    currentNode->next = NULL;
    *tail = currentNode;
    free(nodeEliminated);
    nodeEliminated = NULL;
    (*size)--;
    return elementEliminated;
}

void createHeadTail(int *size, struct node **head, struct node **tail, struct node *newNode){
    *head = newNode;
    *tail = newNode;
    (*size)++;
}
