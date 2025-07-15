#include <stdbool.h>
#include <stdio.h>
#include "../utils/linked_list.h"

int main(){
    //int a;
    //int *b = &a;

    //LinkedList *list = create_linked_list(LIST_SINGLY);

   
    // add_first(list, 2);
    // add_first(list, 3);
    //
    // add_last(list, 4);
    // add_last(list, 5);   
    // add_last(list, 6);
    // add_last(list, 7);
    // 
    //
    // insert_at(list, 7, 9);
    // insert_at(list, 0, 100);
    // print_list(list);
    // 
    // print_list(list);

    LinkedList *listt = create_linked_list(LIST_CIRCULAR);
    add_first(listt, 10);   // 10
    add_first(listt, 20);   // 20 -> 10
    add_first(listt, 30);   // 30 -> 20 -> 10

    print_list(listt);
    //     printf("bien\n");
    //     print_list(listt);
    // } 
        // if(get_at(list, 3,b) == OK){
    //      printf("este es el elemento %d\n",*b);
    // }
    // if(get_at(list, 100,b) == OK){
    //      printf("este es el elemento %d\n",*b);
    // }
    return 0;
}

