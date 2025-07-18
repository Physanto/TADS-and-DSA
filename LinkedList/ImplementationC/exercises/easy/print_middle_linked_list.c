#include <stdio.h>
#include <stdbool.h>
#include "../lib/lib_linked_list/include/linked_list.h"

LinkedList *linked_list();

void print_middle_linked_list(LinkedList *list);

int main(){

    print_middle_linked_list(linked_list());
    return 0;
}

LinkedList *linked_list(){

    LinkedList *list = create_linked_list(LIST_SINGLY);

    for(int i = 0; i < 10; i++){
        add_last(list, i);
    }

    return list;
}

void print_middle_linked_list(LinkedList *list){

    int a = 0;
    int *b = &a;

    get_at(list,(size_list(list)/2),b);
    printf("%d\n",*b);
}
