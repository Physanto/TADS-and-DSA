#ifndef LINKED_LIST

#define LINKED_LIST

/**
 *@ brief enum para los estados de retorno de las funciones.
 *
 * Este enum define los posibles codigos de error o exito de las funciones
 * que manipulan las listas enlazadas.
 */
typedef enum{  
    OK,                     /**< Operacion completada con exito*/
    ERR_NULL_PTR,           /**< puntero nulo pasado por argumento*/
    ERR_INDEX_OUT_RANGE,    /**< indice fuera del rango valido de la lista*/
    ERR_LIST_EMPTY,         /**< La lista se encuentra vacia*/
    ERR_MEM_ALLOC,          /**< malloc falla al asignar memoria*/
    ERR_UKNOW_TYPE_LIST     /**< puntero nulo pasado por argumento*/
}status;

/**
 * @brief enum para los tipos de listas que se manejan
 *
 * Este enum define los tipos de listas enlazadas que se manejan
 */
typedef enum{
    LIST_SINGLY,            /**< lista enlazada simple*/
    LIST_CIRCULAR,          /**< lista circular enlazada*/
    LIST_DOUBLY             /**< lista doblemente enlazada*/
}TypeList;

/**
 * @brief estructura de datos para las listas enlazadas
 *
 * Este struct define la estructura de datos que se usa para implementar
 * las diferentes listas enlazadas.
 */
typedef struct LinkedList LinkedList;

// prototipo de funciones

/**
 *@brief crea la estructura de una lista enlazada
 *
 * Crea una estructura de una lista enlazada en el heap lista para ser manipulada
 *
 * @param typeList: tipo de lista enlazada que quiere crear
 * @return: un puntero a la estructura de lista enlazada creada
 */
LinkedList *create_linked_list(TypeList typeList);

/**
 * @brief libera toda la memoria asociada a la lista enlazada
 *
 * Este funcion destruye toda la lista enlazada, liberando todos sus nodos
 * y por ultimo la estructura de la lista enlazada.
 *
 * @param **linkedList (doble puntero) a la lista enlazada que se desea destruir
 * El puntero se pondra en NULL tras la destruccion.
 *
 * @return OK si la lista fue destruida correctamente.
 * @return ERR_NULL_PTR si el puntero a la lista o la misma lista en NULL
 */
status destroy_linked_list(LinkedList **linked_list);
int size_list(LinkedList *linked_list);
bool is_empty(LinkedList *linked_list);
status add_first(LinkedList *linked_list, int element);
status remove_first(LinkedList *linked_list, int *element_eliminated);
status add_last(LinkedList *linked_list, int element);
status remove_last(LinkedList *linked_list, int *element_eliminated); 
status print_list(LinkedList *linked_list);
status insert_at(LinkedList *linked_list, int index, int element);
status remove_at(LinkedList *linked_list, int index, int *element_eliminated);
status get_first(LinkedList *linked_list, int *first_element);
status get_last(LinkedList *linked_list, int *last_element);
status get_at(LinkedList *linked_list, int index, int *element_at);

#endif
