#include <stdbool.h>
#include "./include/linked_list.h"


int main() {
    LinkedList *singly = create_linked_list(LIST_SINGLY);
    LinkedList *circular = create_linked_list(LIST_CIRCULAR);
    LinkedList *doble = create_linked_list(LIST_DOUBLY);

    add_first(singly, 1);
    add_first(singly, 3);
    add_first(singly, 4);
    add_first(singly, 5);
    print_list(singly);

    add_first(circular, 3);
    add_first(circular, 4);
    print_list(circular);

    add_first(doble, 3);
    add_first(doble, 4);
    add_first(doble, 5);
    print_list(doble);
}
