
#include <stdio.h>
#include <stdbool.h>
#include "../utils/linked_list.h"
#include <time.h>  // ⏱️

#define N 1000000  // cantidad de elementos para probar

int main() {
    LinkedList *list = create_linked_list();

    clock_t start = clock();

    for (int i = 0; i < N; i++) {
        add_last(list, i);
    }

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Insertar %d elementos tomó %.4f segundos.\n", N, seconds);

    destroyed_linked_list(&list);
    return 0;
}
