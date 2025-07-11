
#include <stdio.h>
#include <stdbool.h>
#include "linked_list.h"


int main(){
    LinkedList *new_linked_list = create_linked_list(); 
    remove_last(new_linked_list);
    add_first(new_linked_list, 1);
    add_first(new_linked_list, 2);
    add_first(new_linked_list, 3);
    add_first(new_linked_list, 4);
    add_last(new_linked_list, 5);
    add_last(new_linked_list, 6);
    add_last(new_linked_list, 7);
    add_last(new_linked_list, 8);
    remove_last(new_linked_list);
    remove_last(new_linked_list);

    remove_first(new_linked_list);
    remove_first(new_linked_list);

    print_list(new_linked_list);
    return 0;
}
