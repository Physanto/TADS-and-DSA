#ifndef LINKED_LIST

#define LINKED_LIST

typedef enum{  
    OK,
    ERR_NULL_PTR,
    ERR_INDEX_OUT_RANGE,
    ERR_LIST_EMPTY,
    ERR_MEM_ALLOC
}status;

typedef struct LinkedList LinkedList;

// prototipo de funciones

/**
 *@brief asigna memoria en el heap para preparar una lista enlazada.
 *
 * @return el puntero que apunta a la lista para la insercion de datos.
 */
LinkedList *create_linked_list();
//destruye la lista del heap
status destroy_linked_list(LinkedList **linked_list);
int size_list(LinkedList *linked_list);
bool is_empty(LinkedList *linked_list);
status add_first(LinkedList *linked_list, int element);
status remove_first(LinkedList *linked_list, int *element_eliminated);
status add_last(LinkedList *linked_list, int element);
status remove_last(LinkedList *linked_list, int *element_eliminated); 
status print_list(LinkedList *linked_list);
status print_list_circular(LinkedList *linked_list);
status insert_at(LinkedList *linked_list, int index, int element);
status remove_at(LinkedList *linked_list, int index, int *element_eliminated);
status get_first(LinkedList *linked_list, int *first_element);
status get_last(LinkedList *linked_list, int *last_element);
status get_at(LinkedList *linked_list, int index, int *element_at);

#endif
