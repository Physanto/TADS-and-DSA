#ifndef LINKED_LIST

#define LINKED_LIST

typedef enum{  
    OK,
    ERR_NULL_PTR,
    ERR_INDEX_OUT_RANGE
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
status destroyed_linked_list(LinkedList **linked_list);
status size_list(LinkedList *linked_list);
bool is_empty(LinkedList *linked_list);
void add_first(LinkedList *linked_list, int element);
int remove_first(LinkedList *linked_list);
void add_last(LinkedList *linked_list, int element);
int remove_last(LinkedList *linked_list); 
void print_list(LinkedList *linked_list);
void insert_at(LinkedList *linked_list, int index, int element);
int remove_at(LinkedList *linked_list, int index);
int get_first(LinkedList *linked_list);
int get_last(LinkedList *linked_list);
int get_at(LinkedList *linked_list, int index);

#endif
