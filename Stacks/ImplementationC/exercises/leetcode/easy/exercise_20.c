#include <stdio.h>
#include <stdbool.h>
//#include "../../../utils/stack.h"

// Exercise 20 leetcode
// Dada una cadena sque contiene sólo los caracteres '(', ')', '{', '}'.
// determine si la cadena de entrada es válida '['.']'
//
// Una cadena de entrada es válida si:
//
// Los corchetes abiertos deben cerrarse con el mismo tipo de corchetes.
// Los corchetes abiertos deben cerrarse en el orden correcto.
// Cada corchete cerrado tiene un corchete abierto correspondiente del mismo tipo.
//
// Ejemplo 1:
//
// Entrada: s = "()[]{}"
//
// Salida: verdadero

void push(char element, char *parentheses, int *position){
    *(parentheses + ++(*position)) = element;
}

char pop(char *parentheses, int *position){
    return *(parentheses + (*position)--);
}

bool isValid(char* s){

    char parentheses[10];
    int position = -1;
    int i = 0;
    char element_poped;
    char element_pushed;

    while(*(s+i) != '\0'){

        element_pushed = *(s+i++);
        printf("%c\n",element_pushed);

        if(element_pushed == '(' || element_pushed == '[' || element_pushed == '{'){
            push(element_pushed, parentheses, &position);
            continue;
        }
        element_poped = pop(parentheses, &position);
        printf("pushed: %c , poped: %c\n",element_pushed, element_poped);

        switch(element_pushed){ 

            case ')':
                if(element_poped == '(') {
                    printf("pushed: %c , poped: %c\n",element_pushed, element_poped);
                    continue;
                }
                break;

            case ']':
                if(element_poped == '[') {
                    printf("pushed: %c , poped: %c\n",element_pushed, element_poped);
                    continue;
                }
                break;

            case '}':
                if(element_poped == '{') {
                    printf("pushed: %c , poped: %c\n",element_pushed, element_poped);
                    continue;
                }
                break;

            default:
                return false;
        }
    }
    if(position != -1) return false;
    return true;
}

int main(){
    
    char *s = "([)]";

    if(isValid(s)){
        printf("es correcto\n");
    }
    else printf("es incorrecto\n");

    return 0;
}
