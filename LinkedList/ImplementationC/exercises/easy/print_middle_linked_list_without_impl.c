#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//EJERCICIO SIN AYUDA DE MI API

//Dada una lista enlazada simple, la tarea consiste en encontrar el punto medio.
//Si el número de nodos es par, habrá dos nodos centrales, por lo que se devuelve el segundo.

struct Node{
    int element;
    struct Node *next;
};


void fill_linked_list(struct Node **, int *);
void add_last(struct Node **, int *, int);
int print_middle(struct Node *);
void print_all_list(struct Node *, int);

int main(){
    
    int size = 0;
    struct Node *head;

    fill_linked_list(&head, &size);

    print_all_list(head, size);
    printf("El nodo del medio encontrado es: %d\n",print_middle(head));

    return 0;
}

void fill_linked_list(struct Node **head, int *size){

    int array[] = {10,50,32,65,81, 69};

    for(int i = 0; i < 6; i++){
        add_last(head, size, array[i]);
    }
}

void add_last(struct Node **head, int *size, int element){ 

    struct Node *new_node = malloc(sizeof(struct Node));

    new_node->element = element;
    new_node->next = NULL;

    if(*size == 0){
        *head = new_node;
        *size = *size + 1;
        return;
    } 

    struct Node *current_node = *head;

    while(current_node->next != NULL){
        current_node = current_node->next;
    }

    current_node->next = new_node;    
    *size = *size + 1;
}

int print_middle(struct Node *head){

    //algoritmo de la liebre y la tortuga 
    // consiste en tener dos punteros: puntero lento (slow_ptr) y puntero rapido(fast_ptr)
    // el slow_ptr avanza de uno en uno con respecto a su posicion
    // y fast_ptr avanza de dos en dos con respecto a su posicion
    //
    // entonces, si el tamano de la lista es impar el slow_ptr llega al valor medio
    // cuando el fast_ptr llega al ultimo nodo de la lista.
    //
    // ahora, si el tamano de la lista es par el slow_ptr llega al valor medio
    // cuando el fast_ptr llega a NULL;
    
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;

    while(fast_ptr->next != NULL){  // caso impar
        
        slow_ptr = slow_ptr->next; //incremento de slow_ptr en uno
        fast_ptr = fast_ptr->next->next; //incremento de fast_ptr en dos
        
        if(fast_ptr == NULL)break; //caso par
    }
    
    return slow_ptr->element;
}

void print_all_list(struct Node *head, int size){

    struct Node *current = head;

    for(int i = 0; i < size; i++){
        printf("[%d]->",current->element);
       current = current->next;     
    }
    printf("NULL\n");
}

