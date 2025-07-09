
#include <stdlib.h>
#include <stdio.h>

struct node{
    int element;
    struct node *next;
};

int main(){
    int a = 2;
    //n apunta a A
    int *n = &a;
    printf("valor de a %p\n",&a);
    printf("valor de n %p\n",n);
    //size apunta a n
    int *size = n;
    printf("valor de size %p",size);
    // todos los punteros apuntan a la misma direccion de memoria
    return 0;
}
