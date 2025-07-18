#include <stdio.h>
#include <stdbool.h>
#include "./include/linked_list.h"


int main() {
    LinkedList *singly = create_linked_list(LIST_SINGLY);
    LinkedList *circular = create_linked_list(LIST_CIRCULAR);

    add_first(singly, 1);
    add_first(singly, 2);
    add_first(singly, 2);
    add_first(singly, 2);
    add_first(singly, 2);
    add_first(singly, 2);
    add_first(singly, 2);
    add_first(singly, 2);
    add_first(singly, 2);
    add_first(singly, 2);
    add_first(singly, 2);
    add_first(singly, 2);
    add_first(singly, 2);
    add_first(singly, 2);
    add_first(singly, 2);
    add_first(singly, 2);
    add_first(singly, 2);
    add_first(singly, 2);
    print_list(singly);

    add_first(circular, 3);
    add_first(circular, 4);
    print_list(circular);
}
