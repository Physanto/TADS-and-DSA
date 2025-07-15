
#include <stdio.h>
#include <stdbool.h>
#include "../utils/linked_list.h"
#include <time.h>  // ⏱️

#define N 1000000  // cantidad de elementos para probar

int main() {
    LinkedList *listt = create_linked_list(LIST_CIRCULAR);
    add_first(listt, 10);   // 10
    add_first(listt, 20);   // 20 -> 10
    add_first(listt, 30);   // 30 -> 20 -> 10

    print_list(listt);    return 0;
}
