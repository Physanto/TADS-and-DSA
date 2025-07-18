#include <stdbool.h>
#include "./lib/lib_linked_list/include/linked_list.h"


int main() {
    LinkedList *singly = create_linked_list(LIST_SINGLY);
    LinkedList *circular = create_linked_list(LIST_CIRCULAR);
    LinkedList *doble = create_linked_list(LIST_DOUBLY);

    int a = 0;
    int *b = &a;

    add_first(singly, 1);
    add_first(singly, 2);
    add_first(singly, 3);
    add_last(singly, 10);
    add_last(singly, 20);
    add_first(singly, 4);
    add_first(singly, 5);
    remove_first(singly, b);
    print_list(singly);

    add_first(circular, 1);
    add_first(circular, 1);
    add_first(circular, 2);
    add_first(circular, 3);
    add_last(circular, 10);
    add_last(circular, 20);
    add_first(circular, 4);
    add_first(circular, 5);
    remove_first(circular, b);
    print_list(circular);
    
    add_first(doble, 1);
    add_first(doble, 1);
    add_first(doble, 2);
    add_first(doble, 3);
    add_last(doble, 10);
    add_last(doble, 20);
    add_first(doble, 4);
    add_first(doble, 5);
    remove_first(doble, b);
    print_list(doble);
}
