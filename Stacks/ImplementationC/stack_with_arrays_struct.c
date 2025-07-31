#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utils/stack.h"

typedef struct Stack{
    int size;
    int capacity;
    char *array;
}Stack;

void increment_stack(Stack *stack);
void print_box(char element, char y);

Stack *create_stack(){

    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->size = -1;
    stack->capacity = 5;
    stack->array = (char *) malloc(stack->capacity * sizeof(char));

    return stack;
}

Result destroy_stack(Stack **stack){

    if(stack == NULL || *stack == NULL) return ERR_NULL_PTR;

    free((*stack)->array);
    free(*stack);
    *stack = NULL;

    return OK;
}

bool empty(Stack *stack){

    if(stack == NULL) return true;
    return stack->size == -1;
}

Result push(Stack *stack, char element, char *element_pushed){

    if(stack == NULL) return ERR_NULL_PTR;

    if(stack->size + 1 == stack->capacity){
        increment_stack(stack);
    } 
    *element_pushed = element;
    *(stack->array + (++stack->size)) = element;

    return OK;
}

/*
* @brief incrementa el stack en el heap.
*
* Esta funcion recibe un ** que apunta a la direccion de donde esta ubicado el stack en el heap
* y se encarga de incrementar el tamano del stack (array).
*
* @param char **stack: ubicacion del stack en el heap.
*
*/
Result pop(Stack *stack, char *element_poped){

    if(stack == NULL) return ERR_NULL_PTR;

    if(empty(stack)) return ERR_STACK_EMPTY;

    *element_poped = *(stack->array + stack->size--);

    return OK;
}

Result peek(Stack *stack, char *element_peedked){
    
    if(stack == NULL) return ERR_NULL_PTR;

    if(empty(stack)) return ERR_STACK_EMPTY;

    *element_peedked = *(stack->array + stack->size);

    return OK;
}

Result search(Stack *stack, char element, char *position_searched){

    if(stack == NULL) return ERR_NULL_PTR;

    if(empty(stack)) return ERR_STACK_EMPTY;

    for(char i = 0; i <= stack->size; i++){ 
        if(*(stack->array + i) == element) {
            *position_searched = i;
            return OK;
        }
    }
    return ERR_STACK_EMPTY;
}

void increment_stack(Stack *stack){

    stack->capacity +=5; 

    // la funcion realloc recibe el puntero donde inicia o esta ubicado el array para incrementarlo,
    // la funcion verifica si el tamano que se quiere incrementar alcanza en el bloque que sigue.
    // Dado el caso que no alcance entonces mueve todo el array a otra direccion de memoria donde
    // si alcance el tamano especificado.
    // otro argumento que recibe realloc es el tamano que se quiere aumentar.
    // Por ultimo, realloc devuelve un puntero donde apunta a la nueva direccion del stack.
    stack->array = realloc(stack->array, stack->capacity * sizeof(char));
}

Result print_stack(Stack *stack){ 

    if(stack == NULL) return ERR_NULL_PTR;

    if(empty(stack)) return ERR_STACK_EMPTY;

    for(int i = stack->size; i >= 0; i--){
        if(i == stack->size) print_box(*(stack)->array + i, 's');
        else print_box(*(stack)->array + i, 'n');
    }
    printf("\n");
    return OK;
}

void print_box(char element, char y){

    if(y == 's'){
        printf("+-------+\n");
        printf("|   %d   |---> PEEK\n",element);
    }

    else{
        printf("+-------+\n");
        printf("|   %d   |\n",element);
        printf("+-------+");
    }
} 

int main(){
    Stack *stack = create_stack();
    // printf("Se agrego este elemento: %d\n",push(1,stack));
    // printf("Se agrego este elemento: %d\n",push(2,stack));
    // printf("Se agrego este elemento: %d\n",push(3,stack));
    // printf("Se agrego este elemento: %d\n",push(4,stack));
    // printf("Se agrego este elemento: %d\n",push(5,stack));
    // printf("Se agrego este elemento: %d\n",push(6,stack));
    //
    //
    // printf("Se elimino este elemento: %d\n",pop(stack));
    // printf("Se elimino este elemento: %d\n",pop(stack));
    // printf("Se elimino este elemento: %d\n",pop(stack));
    //
    char a;
    char *b = &a;
    push(stack, 1, b);
    push(stack, 2, b);
    push(stack, 3, b);
    push(stack, 4, b);
    pop(stack,b);
    pop(stack, b);
    print_stack(stack);
    return 0;
}
