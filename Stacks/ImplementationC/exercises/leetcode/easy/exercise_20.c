#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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

/**
* @brief funcion que pushea el elemento que se pasa por parametro
*
* Esta funcion inserta un elemento siempre al final del array y aumenta
* la cantidad de elementos.
*
* @param char element: elemento que quiere ser agregado
* @param char *parentheses: array donde se va almacenar el elemento
* @param int *position: equivale a la position que tiene cada elemento dentro del array
*/
void push(char element, char *parentheses, int *position){

    /* primero entra al parentesis interno y lo desreferencia (accede al valor donde apunta ese puntero)
    * para incrementarlo en uno despues lo incrementa en uno, suma parentheses + position, es decir
    * hace aritmetica de punteros donde accede al valor de ese array y lo desreferencia para poder
    * almacenar en esa posicion de ese array el elemento en element.
    *
    * *(parentheses + ++(*position)) = element es equivalente a parentheses[++position] = element;
    */
    *(parentheses + ++(*position)) = element;
}

/**
* @brief funcion que poped el ultimo elemento almacenado en el Stack
*
* Esta funcion elimina el ultimo elemento que almacena el Stack y decrementa
* la cantidad de elementos.
*
* @param char *parentheses: array donde se va eliminar el elemento
* @param int *position: equivale a la position que tiene cada elemento dentro del array
*
* @return char elemento que se elimino del stack.
*/
char pop(char *parentheses, int *position){

    /* primero entra al parentesis interno y lo desreferencia (accede al valor donde apunta ese puntero)
    * suma parentheses + position, es decir hace aritmetica de punteros donde accede al valor de ese array
    * y lo desreferencia para poder extraer de esa posicion el elemento que contiene el array.
    * Por ultimo decrementa position en uno.
    *
    * *(parentheses + (*position)--) es equivalente a parentheses[++position];
    */
    return *(parentheses + (*position)--);
}

/**
* @brief funcion que verifica si la cadena tiene valido los parentesis
*
* Esta funcion valida si la cadena pasada por parametro es equivalente en apertura y cierre de parentesis,
* llaves o corchetes, es decir, si un parentesis, llave o corchete se abre debe este debe cerrarse
* pero debe cerrarse en el mismo 'ambito', por ejemplo:
* '()' = verdadero, porque asi como se abre tambien se cierra.
* '([])' = verdadero porque asi como se abre el '(' y el '[' tambien se cierra ')', ']' y esto pasa en el
* orden que se abrieron.
*
* el siguiente ejemplo no es valido es decir no es equivalente
* '([)' = falso ya que se abre '(' y '[' pero no se cierra ']'.
* etc...
*
* NOTA IMPORTANTE: la cadena que se va a pasar por argumento solo debe contener parentesis, llaves y corchetes
* apartir de ahora todo lo que sea parentesis, llaves o corchetes  los vamos a llamar KEY, esto para una mayor legibilidad.
*
* @param char *s: array de caracteres o string que almacena los keys que se van a evaluar, leer NOTA IMPORTANTE.
* 
* @return bool true si la cadena es equivalente, de lo contrario false.
*/

bool isValid(char* s){

    char parentheses[strlen(s) + 1];
    //es la variable que se comporta como indice dentro del stack.
    int position = -1;
    int i = 0;

    /* recorre la cadena hasta el final ('\0'), es decir hasta que encuentre el caracter nulo.
    * la recorre usando aritmetica de punteros, explico:
    * primero suma s+i (lo que indica que accede a la direccion de memoria que apunta s y le suma i, osea que
    * aumenta o suma el puntero s) y despues lo desreferencia (accede al valor apuntado por s).
    *
    * En conclusion, accede al valor apuntado por s en la posicion i. es lo mismo que hacer s[i].
    */
    while(*(s+i) != '\0'){ 
        
        /*extrae el elemento donde apunta actualmente s (*(s+i++) y lo almacena en element_pushed.
        * para esto lo primero que pasa es que accede a la direccion de apunta s, luego incrementa en uno i,
        * despues desreferencia esa direccion para obtener el valor que contiene esa direccion de memoria
        */                                                
        char element_pushed = *(s+i++);
        
        //verifica si el element_pushed (el elemento sacado de s) corresponde a alguna key de apertura
        
        if(element_pushed == '(' || element_pushed == '[' || element_pushed == '{'){

            /*
            * pushea la key de apertura al stack y skipea el resto del ciclo, esto lo hace porque si lo agrega
            * no es necesario seguir con el ciclo mientras que lo que se este obteniendo de element_pushed sea una key de apertura
            */
            push(element_pushed, parentheses, &position);
            continue;
        }
        
        /*
        * Estas lineas de codigo que se ejecutan a continuacion solo lo hacen si el element_pushed actualmente tiene
        * una key de cierre.
        *
        * Verifica si el stack esta vacio, entonces retorna false.
        *
        *  esta verificacion se hace ya que si el stack esta vacio entonces no se puede hacer pop, ya que
        *  no existe un elemento que se pueda extraer y por ende comparar con el key de cierre, en el caso
        *  que no se haga esta validacion generara un comportamiento indefinido ya que se haria un pop en un stack
        *  vacio.
        */
        if(position == -1) return false;
        
        char element_poped = pop(parentheses, &position);

        /*
        * verifica si el key de cierre no corresponde con el key de apertura que se saco del stack, es decir
        * no son equivalentes. ejm: "(}" o "{]" etc...
        *
        * si no son equivalentes entonces retorna false.
        */
        if((element_pushed == ')' && element_poped != '(') || (element_pushed == ']' && element_poped != '[') ||
            (element_pushed == '}' && element_poped != '{')) return false;
    }
    // verifica si el stack esta vacio
    // Esto lo hace porque si el stack esta vacio eso quiere decir que no quedo ninguna key
    // osea que todos son equivalentes.
    return position == -1;
}

int main(){
    
    char *s = "()}";

    if(isValid(s)){
        printf("es correcto\n");
    }
    else printf("es incorrecto\n");

    return 0;
}
