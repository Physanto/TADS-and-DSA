#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// LIFO: Last in First out

bool empty();
char push(char element, char **);
char pop(char **);
char peek(char **);
char search(char element, char **);
void increment_stack(char **);

int size = -1;
int length = 5;

bool empty(){
    return size == -1;
}

char push(char element, char **stack){

    if(size + 1 == length){
        increment_stack(stack);
    } 
    //(*stack)[position++] = element;
    *(*stack + (++size)) = element; 
    return element;
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
char pop(char **stack){

    if(empty()) return -1;

    char element = *(*stack + size--);
    return element;
}

char peek(char **stack){
    
    if(empty()) return -1;

    return *(*stack + size);
}

char search(char element, char **stack){

    if(empty()) return -1;

    for(char i = 0; i <= size; i++){ 
        if(*(*stack + i) == element) return element;
    }
    return -1;
}

void increment_stack(char **stack){

    length +=5; 

    // la funcion realloc recibe el puntero donde inicia o esta ubicado el array para incrementarlo,
    // la funcion verifica si el tamano que se quiere incrementar alcanza en el bloque que sigue.
    // Dado el caso que no alcance entonces mueve todo el array a otra direccion de memoria donde
    // si alcance el tamano especificado.
    // otro argumento que recibe realloc es el tamano que se quiere aumentar.
    // Por ultimo, realloc devuelve un puntero donde apunta a la nueva direccion del stack.
    *stack = realloc(*stack, length * sizeof(char));
}

void print_stack(char *stack){ 

    if(empty()) return;

    for(char i = 0; i <= size; i++){
        printf("Elemento %d es: %d \n",(i+1), *(stack + i));
    }
}

int main(){
    
    //definicion de un array que puede almacenar 5 elementos de tipo entero.
    char *stack = (char *) malloc( length * sizeof(char));

    printf("Se agrego este elemento: %d\n",push(1,&stack));
    printf("Se agrego este elemento: %d\n",push(2,&stack));
    printf("Se agrego este elemento: %d\n",push(3,&stack));
    printf("Se agrego este elemento: %d\n",push(4,&stack));
    printf("Se agrego este elemento: %d\n",push(5,&stack));
    printf("Se agrego este elemento: %d\n",push(6,&stack));


    printf("Se elimino este elemento: %d\n",pop(&stack));
    printf("Se elimino este elemento: %d\n",pop(&stack));
    printf("Se elimino este elemento: %d\n",pop(&stack));

    print_stack(stack);
    return 0;
}
