#include <stdlib.h>
#include <stdbool.h>
#include "../include/linked_list.h"
#include "./linked_list_internal.h"

//Prototipo de Funciones
void insert_head_tail(LinkedList *list, Node *new_node);

status add_first(LinkedList *list, int element){ 

    if(list == NULL) return ERR_NULL_PTR;

    if(list->type != LIST_CIRCULAR) return ERR_UKNOW_TYPE_LIST;

    Node *new_node = create_node(list,element);
    if(new_node == NULL) return ERR_MEM_ALLOC;

    if(is_empty(list)){
        insert_head_tail(list,new_node); 
        return OK;
    }

    new_node->next = list->head;
    list->head = new_node;
    list->tail->next = list->head;
    list->size++;

    return OK;
}

status remove_first(LinkedList *list, int *element_eliminated){

    if(list == NULL || element_eliminated == NULL) return ERR_NULL_PTR;

    if(list->type != LIST_CIRCULAR) return ERR_UKNOW_TYPE_LIST;

    if(is_empty(list)) return ERR_LIST_EMPTY; 

    Node *node_eliminated = list->head;
    *element_eliminated = node_eliminated->element;

    if(list->size == 1){
        free(list->head); //head y tail apuntan a lo mismo asi que solo se libera alguno.
        list->head = NULL;
        list->tail = NULL;
        list->size--; 
        return OK;
    }

    list->head = node_eliminated->next; 
    list->tail->next = list->head;
    free(node_eliminated);

    list->size--;

    return OK;
}

status add_last(LinkedList *list, int element){ 
    
    if(list == NULL) return ERR_NULL_PTR;

    if(list->type != LIST_CIRCULAR) return ERR_UKNOW_TYPE_LIST;

    Node *new_node = create_node(list,element);
    if(new_node == NULL) return ERR_MEM_ALLOC;

    new_node->element = element;
    new_node->next = NULL;

    if(is_empty(list)){  
        insert_head_tail(list,new_node);
        return OK;
    }

    list->tail->next = new_node;
    list->tail = new_node;
    list->tail->next = list->head;
    list->size++;

    return OK;
}

status remove_last(LinkedList *list, int *element_eliminated){

    if(list == NULL || element_eliminated == NULL) return ERR_NULL_PTR;

    if(list->type != LIST_CIRCULAR) return ERR_UKNOW_TYPE_LIST;

    if(is_empty(list)) return ERR_LIST_EMPTY; 
    
    struct Node *node_eliminated = list->tail;
    *element_eliminated = node_eliminated->element;


    if(list->size == 1){ 
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->size--;

        return OK;
    }

    Node *node_prev_find = get(list, list->size-2);

    if(node_prev_find == NULL) return ERR_INDEX_OUT_RANGE;

    list->tail = node_prev_find;
    list->tail->next = list->head;
    free(node_eliminated);

    list->size--;

    return OK;
}

status insert_at(LinkedList *list, int index, int element){

    if(list == NULL) return ERR_NULL_PTR;

    if(list->type != LIST_CIRCULAR) return ERR_UKNOW_TYPE_LIST;

    if(index < 0 || index > list->size) return ERR_INDEX_OUT_RANGE;

    Node *new_node = create_node(list,element);
    if(new_node == NULL) return ERR_MEM_ALLOC;

    if(is_empty(list)){  
        insert_head_tail(list,new_node);
        return OK;
    } 

    if(index == 0){
        new_node->next = list->head;
        list->head = new_node;
        list->tail->next = list->head;
        list->size++;
        return OK;
    }

    Node *node_find = get(list, index-1);
    if(node_find == NULL) return ERR_INDEX_OUT_RANGE;

    new_node->next = node_find->next;
    node_find->next = new_node;

    if(index == list->size) {
        list->tail = new_node;
        list->tail->next = list->head;
    }

    list->size++;
    return OK;
}

status remove_at(LinkedList *list, int index, int *element_eliminated){

    if(list == NULL || element_eliminated == NULL) return ERR_NULL_PTR;

    if(list->type != LIST_CIRCULAR) return ERR_UKNOW_TYPE_LIST;

    if(is_empty(list)) return ERR_LIST_EMPTY;
    
    if(index < 0 || index >= list->size) return ERR_INDEX_OUT_RANGE;

    Node *node_eliminated;

    if (list->size == 1) {
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
        list->tail->next = list->head;

        free(node_eliminated);
        list->size--;

        return OK;
    }

    Node *node_prev_find = get(list, index-1);

    if(node_prev_find == NULL) return ERR_INDEX_OUT_RANGE;

    node_eliminated = node_prev_find->next;
    *element_eliminated = node_eliminated->element;
    node_prev_find->next = node_eliminated->next;

    if(index == list->size-1) list->tail = node_prev_find;

    free(node_eliminated);
    list->size--;

    return OK;
}

void insert_head_tail(LinkedList *list, Node *new_node){
    list->head = new_node;
    list->tail = new_node;
    list->tail->next = list->head;
    list->size++;
}

