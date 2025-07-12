#include <stdbool.h>
#include <stdio.h>
#include "../utils/linked_list.h"

int main(){

    LinkedList *list = create_linked_list();

    add_first(list, 1);
    add_first(list, 2);
    add_first(list, 3);
    add_last(list, 4);
    add_last(list, 5);
    add_last(list, 6);
    add_last(list, 7);

    insert_at(list, 4, 9);
    insert_at(list, 3, 100);

    remove_last(list);
    remove_last(list);
    print_list(list);

    printf("Este es el nodo encontrado %d\n",get_first(list));
    printf("Este es el nodo encontrado %d\n",get_last(list));
    printf("Este es el nodo encontrado %d\n",get_at(list,7));
    
    return 0;
}

