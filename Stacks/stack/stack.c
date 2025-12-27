#include <stdio.h>
#include <stdbool.h>

// IMPLEMENTACION DE UN STACK
// es una estructura lineal que sigue el principio LIFO = Last in First out.
//
// Funciones que hacen parte de un stack:
//  - push(char) = dato que quiere apilar.
//  - pop() = desapilar el ultimo dato ingresado.
//  - isEmpty() = devuelve true si esta vacia la pila.
//  - peek() = devuelve el elemento que esta en la parte superior de la pila es decir, el ultimo.
//  - size() = devuelve la cantidad de elementos que tiene la pila.

//struct que representa el stack a lo largo del programa.
typedef struct{
    int size;
    int capacity;
    char *data;
} stack;

bool stack_default(stack stack){ 
    stack =
}

int main(){

}
