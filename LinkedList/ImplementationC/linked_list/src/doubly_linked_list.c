#include <stdlib.h>
#include <stdbool.h>
#include "../internal/linked_list_internal.h"

status add_first_doubly(LinkedList *list, int element){

    if(list == NULL) return ERR_NULL_PTR;

    if(list->type != LIST_DOUBLY) return ERR_UKNOW_TYPE_LIST;

    Node *new_node = create_node(list, element);
    if(new_node == NULL) return ERR_MEM_ALLOC;

    if(is_empty(list)){ 
        create_head_tail(list,new_node);
        return OK;
    }
    list->head->prev = new_node;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
    
    return OK;
}

status remove_first_doubly(LinkedList *list, int *element_eliminated){

    if(list == NULL || element_eliminated == NULL) return ERR_NULL_PTR;

    if(list->type != LIST_DOUBLY) return ERR_UKNOW_TYPE_LIST;

    if(is_empty(list)) return ERR_LIST_EMPTY;

    Node *node_eliminated = list->head;
    *element_eliminated = node_eliminated->element; 

    if(list->size == 1){ 
        free(node_eliminated);
        list->head = NULL;
        list->tail = NULL;
        list->size--;

        return OK;
    }

    Node *node_next = list->head->next;
    node_next->prev = NULL;
    list->head = node_next;

    free(node_eliminated);
    list->size--;

    return OK;
}

status add_last_doubly(LinkedList *list, int element){ 

    if(list == NULL) return ERR_NULL_PTR;

    if(list->type != LIST_DOUBLY) return ERR_UKNOW_TYPE_LIST;

    Node *new_node = create_node(list, element);
    if(new_node == NULL) return ERR_MEM_ALLOC;

    if(is_empty(list)){ 
        create_head_tail(list, new_node);
        return OK;
    }

    list->tail->next = new_node;
    new_node->prev = list->tail;
    list->tail = new_node;
    list->size++;
    
    return OK;
}

status remove_last_doubly(LinkedList *list, int *element_eliminated){

    if(list == NULL || element_eliminated == NULL) return ERR_NULL_PTR;

    if(list->type != LIST_DOUBLY) return ERR_UKNOW_TYPE_LIST;

    if(is_empty(list)) return ERR_LIST_EMPTY;

    Node *node_eliminated = list->tail;
    *element_eliminated = node_eliminated->element;

    if(list->size == 1){
        free(node_eliminated);
        list->head = NULL;
        list->tail = NULL;
        list->size--;
        return OK;
    }

    Node *node_before = list->tail->prev;
    node_before->next = NULL;
    list->tail = node_before;

    free(node_eliminated);
    list->size--;

    return OK;
}

status insert_at_doubly(LinkedList *list, int index, int element){

    if(list == NULL) return ERR_NULL_PTR;

    if(list->type != LIST_DOUBLY) return ERR_UKNOW_TYPE_LIST;

    if(index < 0 || index > list->size) return ERR_INDEX_OUT_RANGE;

    Node *new_node = create_node(list,element);
    if(new_node == NULL) return ERR_MEM_ALLOC;

    if(is_empty(list)){  
        create_head_tail(list,new_node);
        return OK;
    } 

    if(index == 0){ 
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
        list->size++;

        return OK;
    }

    if(index == list->size){
        list->tail->next = new_node;
        new_node->prev = list->tail;
        list->tail = new_node;
        list->size++;

        return OK;
    }
    // node_find es el nodo en la ubicacion donde se va insertar el nuevo
    Node *node_find = get(list,index);
    if(node_find == NULL) return ERR_NULL_PTR;

    //node_before es el nodo anterior al node_find ya que el nodo anterior al encontrado debe apuntar al nuevo nodo.
    Node *node_before = node_find->prev;

    node_before->next = new_node;
    new_node->prev = node_before;
    new_node->next = node_find;
    list->size++;

    return OK;
}

status remove_at_doubly(LinkedList *list, int index, int *element_eliminated){

    if(list == NULL) return ERR_NULL_PTR;

    if(list->type != LIST_DOUBLY) return ERR_UKNOW_TYPE_LIST;

    if(is_empty(list)) return ERR_LIST_EMPTY;

    if(index < 0 || index >= list->size) return ERR_INDEX_OUT_RANGE;

    Node *node_eliminated;

    if(list->size == 1 && index == 0){
        node_eliminated = list->head;
        *element_eliminated = node_eliminated->element;

        free(node_eliminated);
        list->head = NULL;
        list->tail = NULL;
        list->size--;

        return OK;
    }

    if(index == 0){ 
        node_eliminated = list->head;
        *element_eliminated = node_eliminated->element;

        list->head = node_eliminated->next;
        list->head->prev = NULL;

        free(node_eliminated);
        list->size--;

        return OK;
    } 

    Node *node_prev_find = get(list, index-1);
    if(node_prev_find == NULL) return ERR_NULL_PTR; 

    node_eliminated = node_prev_find->next;
    *element_eliminated = node_eliminated->element;

    node_prev_find->next = node_eliminated->next;

    if(index == list->size-1) list->tail = node_prev_find;

    else node_eliminated->next->prev = node_prev_find;

    free(node_eliminated);
    list->size--;

    return OK;
}
