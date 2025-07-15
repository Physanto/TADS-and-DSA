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
 * Este funcion destruye cualquier tipo de lista enlazada 'LIST_SINGLY',
 * 'LIST_CIRCULAR', 'LIST_DOUBLY'. liberando todos sus nodos y por ultimo 
 * la estructura general de la lista enlazada.
 *
 * @param **linkedList (doble puntero) a la lista enlazada que se desea destruir
 * El puntero se pondra en NULL tras la destruccion.
 *
 * @note se espera un tipo de lista valida para destruir la lista completamente
 * de lo contrario no se hara este proceso y es responsabilidad del usuario de validar
 * que el tipo de lista coincida con alguno del enum mencionado anteriormente.
 *
 * @return OK si la lista fue destruida correctamente.
 * @return ERR_NULL_PTR si el puntero a la lista o la misma lista en NULL
 * @return ERR_UKNOW_TYPE_LIST si la lista no coincide con algun tipo definido.
 */
status destroy_linked_list(LinkedList **list);

/**
 * @brief devuelve el tamano de la lista especificada.
 *
 * Esta funcion retorna el numero de telefonos (tamanno) de la lista pasada por argumento
 *
 * @note si la lista que se le pasa por argumento es NULL entonces retorna -1
 *
 * @param list puntero a una estructura LinkedList que representa la lista.
 * @return int el tamano de la lista, o -1 si el puntero de la lista en NULL
 */
int size_list(LinkedList *list);

/**
 * @brief verifica si la lista esta vacia
 *
 * Esta funcion retorna un true si la lista esta vacia, es decir
 * si la lista tiene 0 elementos.
 *
 * @note la lista (el puntero que apunta a un LinkedList) se verifica si es NULL
 * entonces se tomara como vacia y retorna true, en el caso que no sea NULL verifica
 * si la lista que se le pasa por argumento esta vacia.
 *
 * @param list puntero a una estructura LinkedList que representa la lista. 
 * @return true si la lista esta vacia (no tiene elementos) o si la lista es NULL de lo contrario false
 */
bool is_empty(LinkedList *list);

/**
 * @brief
 *
 */
status add_first(LinkedList *list, int element);
status remove_first(LinkedList *list, int *element_eliminated);
status add_last(LinkedList *list, int element);
status remove_last(LinkedList *list, int *element_eliminated); 
status print_list(LinkedList *list);
status insert_at(LinkedList *list, int index, int element);
status remove_at(LinkedList *list, int index, int *element_eliminated);
status get_first(LinkedList *list, int *first_element);
status get_last(LinkedList *list, int *last_element);
status get_at(LinkedList *list, int index, int *element_at);

// cita para el 22 de julio del 2025 a las 7:30 am, Hospital Susana lopez barrio la ladera
//
// se debe facturar, imagenes diagnosticas frente el edificio de pediatria.
//
// todo el dia anterior se debe consumir una dieta blanda (fruta, caldo), a las 6pm disolver un sobre de cleanprev o nuliteli.
//
#endif
