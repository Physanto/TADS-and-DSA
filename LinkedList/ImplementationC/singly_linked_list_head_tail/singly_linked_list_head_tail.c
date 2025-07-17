#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils/linked_list_internal.h"

status add_first_singly(LinkedList *list, int element){
    
    if(list == NULL) return ERR_NULL_PTR;

    if(list->type != LIST_SINGLY) return ERR_UKNOW_TYPE_LIST;

    Node *new_node = create_node(list, element);
    if(new_node == NULL) return ERR_MEM_ALLOC;

    if(is_empty(list)){  
        create_head_tail(list, new_node);
        return OK;
    }

    new_node->next = list->head;
    list->head = new_node;
    list->size++;

    return OK;
}

status remove_first_singly(LinkedList *list, int *element_eliminated){
    
    if(list == NULL || element_eliminated == NULL) return ERR_NULL_PTR;

    if(list->type != LIST_SINGLY) return ERR_UKNOW_TYPE_LIST;

    if(is_empty(list)) return ERR_LIST_EMPTY; 

    Node *node_eliminated = list->head;
    *element_eliminated = node_eliminated->element;

    list->head = node_eliminated->next;

    if(list->head == NULL) list->tail = NULL;
    
    free(node_eliminated);
    list->size--;

    return OK;
}

status add_last_singly(LinkedList *list, int element){

    if(list == NULL) return ERR_NULL_PTR;

    if(list->type != LIST_SINGLY) return ERR_UKNOW_TYPE_LIST;

    Node *new_node = create_node(list, element);
    if(new_node == NULL) return ERR_MEM_ALLOC;

    new_node->element = element;
    new_node->next = NULL;

    if(is_empty(list)){ 
        create_head_tail(list, new_node);
        return OK;
    } 
    
    list->tail->next = new_node;
    list->tail = new_node;
    list->size++;

    return OK;
}

status remove_last_singly(LinkedList *list, int *element_eliminated){

    if(list == NULL || element_eliminated == NULL) return ERR_NULL_PTR;

    if(list->type != LIST_SINGLY) return ERR_UKNOW_TYPE_LIST;

    if(is_empty(list)) return ERR_LIST_EMPTY; 
    
    struct Node *node_eliminated = list->tail;
    *element_eliminated = node_eliminated->element;

    if(list->head == list->tail){
        free(node_eliminated);
        list->head = NULL;
        list->tail = NULL;
        list->size--;
        return OK;
    }

    Node *current_node = get(list, list->size-2);

    if(current_node == NULL) return ERR_INDEX_OUT_RANGE;

    current_node->next = NULL;
    list->tail = current_node;
    free(node_eliminated);
    node_eliminated = NULL;

    list->size--;

    return OK;
}

status insert_at_singly(LinkedList *list, int index, int element){

    if(list == NULL) return ERR_NULL_PTR;

    if(list->type != LIST_SINGLY) return ERR_UKNOW_TYPE_LIST;

    if(index < 0 || index > list->size) return ERR_INDEX_OUT_RANGE;

    Node *new_node = create_node(list, element);
    if(new_node == NULL) return ERR_MEM_ALLOC;


    new_node->element = element;
    new_node->next = NULL;

    if(is_empty(list)){
        create_head_tail(list,new_node);
        return OK;
    }

    if(index == 0){ 
        new_node->next = list->head;
        list->head = new_node;
        list->size++;
        return OK;
    }

    Node *node_find = get(list, index-1);
    if(node_find == NULL) return ERR_INDEX_OUT_RANGE;

    new_node->next = node_find->next;
    node_find->next = new_node; 

    if(index == list->size) list->tail = new_node;

    list->size++;

    return OK;
}

status remove_at_singly(LinkedList *list, int index, int *element_eliminated){

    if(list == NULL || element_eliminated == NULL) return ERR_NULL_PTR;

    if(list->type != LIST_SINGLY) return ERR_UKNOW_TYPE_LIST;

    if(is_empty(list)) return ERR_LIST_EMPTY;
    
    if(index < 0 || index >= list->size) return ERR_INDEX_OUT_RANGE;

    Node *node_eliminated;
 
    if(list->size == 1){ 
        node_eliminated = list->head;
        *element_eliminated = node_eliminated->element;
        free(node_eliminated); 
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
        return OK;
    }

    if(index == 0){ 
        node_eliminated = list->head;
        *element_eliminated = node_eliminated->element;

        list->head = node_eliminated->next;

        free(node_eliminated);
        node_eliminated = NULL;

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
