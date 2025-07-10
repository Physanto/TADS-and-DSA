
#include <stdlib.h>
#include <stdio.h>

//estructura de datos

struct node{
    // elemento que sera guardado al nodo
    int element;

    //nextNode debe ser un puntero ya que necesita apuntar a la dir donde esta alojado el otro nodo en el heap
    //el *nextNode solo almacena la dir de memoria donde esta el nodo no todo el nodo. 
    struct node *nextNode;
};

//prototipo de funciones

int size(int *size);
signed char isEmpty(int size);
void addFirst(int element, int *size, struct node **head); //**head es un puntero a puntero: ya que para poder pasar por referencia un puntero se debe ser puntero a puntero
void addLast(int element, int *size, struct node **head);
int removeFirst(int *size, struct node **head);
int removeLast(int *size, struct node **head);
void showNodes(int size, struct node *head);
struct node *get(int size, struct node *head, int index);
void add(int position, int element, int *size, struct node **head);
int removeIndex(int index, int *size, struct node **head);

int main(){
    
    //cantidad de elementos que estan enlazados
    int size = 0;

    // nodo que se prepara para apuntar a una direccion de memoria (primer elemento de la lista enlazada);
    struct node *head;

    addFirst(1, &size, &head);
    addFirst(2, &size, &head);
    addFirst(3, &size, &head);
    addFirst(4, &size, &head);
    addLast(5, &size, &head);
    addLast(6, &size, &head);
    addLast(8, &size, &head);
    //removeLast(&size, &head);
    //removeLast(&size, &head);
    //removeFirst(&size, &head);
    //removeFirst(&size, &head);

    printf("ELEMENTOS INGRESADOS EN LA LISTA ENLAZADA\n");
    printf("cantidad de nodos %d\n", size);
    showNodes(size, head);

    add(0,10,&size,&head);
    add(1,11,&size,&head);
    add(2,12,&size,&head);
    add(3,13,&size,&head);
    add(4,14,&size,&head);
    add(5,15,&size,&head);

    printf("ELEMENTOS INGRESADOS DESPUES DEL ADD\n");
    printf("cantidad de nodos %d\n", size);
    showNodes(size, head);

    removeIndex(0, &size, &head);
    removeIndex(0, &size, &head);
    removeIndex(0, &size, &head);
    removeIndex(4, &size, &head);

    printf("ELEMENTOS INGRESADOS DESPUES DEL REMOVE INDEX\n");
    printf("cantidad de nodos %d\n", size);
    showNodes(size, head);

    return 0;
}

void showNodes(int size, struct node *head){

    if(isEmpty(size) == -1) return;

    struct node *currentNode = head;

    int i = 0;
 
    for(int i = 0; i < size; i++){ 
        printf("\nEste es el valor del nodo %d: %d", (i+1), get(size, head, i)->element);
    }
    printf("\n");
}

int size(int *size){
    return *size;
}

signed char isEmpty(int size){
    return size == 0 ? -1 : 0;
}

void addFirst(int element, int *size, struct node **head){

    // se crea un puntero y se asigna memoria dinamica para poder "apuntar" a la direccion donde esta el nodo
    // que ya esta en la cabecera.
    struct node *newNode = malloc(sizeof(struct node));
    newNode->element = element;
    newNode->nextNode = *head;
    *head = newNode; 
    (*size)++;
}

void addLast(int element, int *size, struct node **head){
    
    struct node *newNode = malloc(sizeof(struct node));
    newNode->element = element;

    if(isEmpty(*size) == -1){
        *head = newNode;
        (*size)++;
        return;
    }

    //este *currentNode es el que se va encargar de recorrer la lista nodo por nodo
    //por eso se le asigna a lo que esta apuntando el head
    struct node *currentNode = *head;

    //se debe revisar nodo por nodo para identificar el final de la lista.
    while(currentNode->nextNode != NULL){ 
        
        //por cada iteracion que encuentra otro nodo que no sea null entonces actualiza donde esta apuntando.
        //esto con el fin de poder revisar nodo por nodo y ademas porque sino se hace el ciclo es infinito,
        //ya que siempre estariamos apuntando a lo mismo.
        currentNode = currentNode->nextNode;
    }

    //se supone que usted llego al final de la lista y usted contiene lo que apunta el ultimo nodo(se supone que es null ya que es el ultimo nodo)
    //asi que ahora lo vas a modificar (ahora vas apuntar) a lo que te voy a dar que es el nuevo nodo.
    currentNode->nextNode = newNode;
    (*size)++;
}

int removeFirst(int *size, struct node **head){ 

    if(isEmpty(*size)){
        return -1;
    }

    //como head es un puntero a puntero nodo (**head) entonces para poder acceder a los atributos del nodo real debo
    //de desreferenciar (*head) y acceder al atributo que se quiera, esto pasa porque **tiene la direccion de la memoria del nodo
    //pero para yo poder al nodo real debo de desreferenciar.

    struct node *nodeEliminated = *head;
    int elementEliminated = nodeEliminated->element;


    //actualiza el nodo de la cabecera, es decir ahora la cabecera no es el primer nodo sino el siguiente.
    *head = nodeEliminated->nextNode;


    //libero la memoria del primer nodo ya que fue eliminado, esto lo hago teniendo una referencia al primer nodo.
    free(nodeEliminated);
    (*size)--;

    return elementEliminated;
}

int removeLast(int *size, struct node **head){

    if(isEmpty(*size) == -1){ 
        return -1;
    }
    else if(*size == 1){  
        int elementEliminated = (*head)->element;
        free(*head);
        *head = NULL;
        (*size)--;
        return elementEliminated;
    }

    // este nodo se va actualizando hasta el penultimo nodo.
    struct node *beforeLast = *head;

    //este nodo es el que se encarga de ir recorriendo toda la lista hasta el ultimo nodo
    struct node *currentNode = beforeLast;

    while(currentNode->nextNode != NULL){ 

        //se actualiza este nodo que es el encargado de al final almacenar el penultimo nodo.
        beforeLast = currentNode;
        //se actualiza el nodo que esta recorriendo toda la lista
        currentNode = currentNode->nextNode;
    }

    int elementEliminated = currentNode->element;
    beforeLast->nextNode = NULL;

    // se libera la memoria del ultimo nodo ya que fue eliminado.
    free(currentNode);
    (*size)--;

    return elementEliminated;
}

struct node *get(int size, struct node *head, int index){ 

    struct node *getNode = head;

    if(isEmpty(size) == -1 || (index < 0 || index > size)){
        return NULL;
    }

    int i = 0;
    while(getNode != NULL){ 

        if(i == index) return getNode;

        getNode = getNode->nextNode;
        i++;
    }
    return NULL;
}

void add(int position, int element, int *size, struct node **head){

    if(position < 0 || position > *size){
        printf("Indice fuera de rango");
        return;
    }

    struct node *newNode = malloc(sizeof(struct node));
    newNode->element = element;
    newNode->nextNode = NULL;

    if(position == 0){ 
        newNode->nextNode = *head;
        *head = newNode;
        (*size)++;
        return;
    }
     
    struct node *node = get(*size, *head, position);

    struct node *currentNode = *head;

    while(currentNode->nextNode != node){ 
        currentNode = currentNode->nextNode; 
    }

    currentNode->nextNode = newNode;
    newNode->nextNode = node;
    (*size)++;
}

int removeIndex(int index, int *size, struct node **head){

    if(index < 0 || index >= *size) return -1;
    
    int elementEliminated;
    struct node *nodeEliminated;

    if(index == 0){ 
        nodeEliminated = *head;
        elementEliminated = nodeEliminated->element;
        *head = nodeEliminated->nextNode;
        free(nodeEliminated);
        nodeEliminated = NULL;
        (*size)--;
        return elementEliminated;
    }

    nodeEliminated = get(*size,*head, index);
    struct node *currentNode = *head;

    while(currentNode->nextNode != nodeEliminated){
        currentNode = currentNode->nextNode;
    }

    elementEliminated = nodeEliminated->element;
    currentNode->nextNode = nodeEliminated->nextNode;
    free(nodeEliminated);
    nodeEliminated = NULL;
    (*size)--;
    return elementEliminated;
}

