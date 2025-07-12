#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../circular_linked_list/linked_list.h"

int main(){

    LinkedList *list = create_linked_list();

    add_first(list, 1);
    add_first(list, 2);
    add_first(list, 3);
    add_last(list, 4);
    add_last(list, 5);
    add_last(list, 6);
    add_last(list, 7);


    remove_last(list);
    remove_last(list);
    print_list(list);

    printf("Este es el nodo encontrado %d",gett(list, 2));
    return 0;
}
