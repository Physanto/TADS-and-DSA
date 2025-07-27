#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
/*Se le proporcionan los encabezados de dos listas enlazadas ordenadas list1 y list2.
Fusionar las dos listas en una sola lista ordenada. Esta lista debe formarse
uniendo los nodos de las dos primeras listas.
devuelve el encabezado de la lista vinculada fusionada.
*/

void add_last(struct ListNode **list_head, int element, int *size){ 

    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->val = element;
    new_node->next = NULL;
    

    if((*size) == 0){
        *list_head = new_node;
        (*size)++;
        return;
    }

    struct ListNode *current = *list_head;

    while(current->next != NULL){
        current = current->next;
    }

    current->next = new_node;
    (*size)++;
}

void print(struct ListNode *head){
    
    while(head != NULL){
        printf("[%d]->",head->val);
        head = head->next;
    }
    printf("NULL\n");
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){

    struct ListNode *list = NULL;
    int size = 0;

    while(list1 != NULL || list2 != NULL){

        if(list1->val == list2->val){
            add_last(&list, list1->val, &size);
            add_last(&list, list2->val, &size);
        }
        else if(list1->val < list2->val) add_last(&list, list1->val, &size);
        else add_last(&list, list2->val, &size);

        list1 = list1->next;
        list2 = list2->next;
    }

    return list;
}

int main(){

    struct ListNode *list1 = NULL;
    struct ListNode *list2 = NULL;
    int size = 0;
    int sizes = 0;

    // add_last(&list1,2,&size);
    // add_last(&list1,4,&size);
    add_last(&list2,0,&sizes);
    // add_last(&list2,3,&sizes);
    // add_last(&list2,4,&sizes);
    //
    // print(list1);
    // print(list2);
    print(mergeTwoLists(list1,list2));
    return 0;
}
