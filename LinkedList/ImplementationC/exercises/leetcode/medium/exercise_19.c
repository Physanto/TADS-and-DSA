#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

//Dado el valor head una lista enlazada, elimine el n nodo del final de la lista
//y devuelva su cabecera.


// opcion 1: Es recorrer toda la lista y contar la cantidad de elementos
// este recorrido va ser costoso (O(n)) pero podemos usar el algoritmo de la liebre y la tortuga
// para que no sea tan "costoso" (O(n/2)), o bueno una forma similar a este algoritmo.
//
// opcion 2:
//
void add_lastt(struct ListNode **list_head, int element){ 

    static int size = 0;

    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->val = element;
    new_node->next = NULL;
    

    if(size == 0){
        *list_head = new_node;
        size++;
        return;
    }

    struct ListNode *current = *list_head;

    while(current->next != NULL){
        current = current->next;
    }

    current->next = new_node;
    size++;

}

int size_list(struct ListNode *head){ 

    int size = 1;

    while(head->next != NULL){
        head = head->next->next;
        size +=2;

        if(head == NULL){
            size -=1;
            break; 
        }
    }
    return size;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) { 

    
    int m = size_list(head);
    int nn = m;
    if(n == 1 && m == 1) return NULL;

    struct ListNode *main = head;
    struct ListNode *ref = head; 

    for (int i = 0; i < n; i++) {  
        ref = ref->next;
    }

    while(ref->next != NULL){ 
        ref = ref->next;
        main = main->next;
    }
    ref = main->next;
    main->next = ref->next;
    free(ref);
    
    // if(n == m){
    //     head = head->next;
    //     return head;
    // }
    // 
    // m = m - n;
    //
    // if(m == 1 && nn > 3){
    //     head->next = NULL;
    //     return head;
    // } 
    //
    // struct ListNode *aux = head;
    // struct ListNode *aux2 = head;
    //
    // for(int i = 0; i < m-1; i++){     
    //     aux = aux->next;
    // }
    //
    // aux2 = aux->next;
    // aux->next = aux2->next;
    // free(aux2);

    //
    // m/=2;
    // 
    // struct ListNode *fast_ptr;
    // struct ListNode *slow_ptr = head;
    //
    // if(m % 2==0){
    //     if(m == 2) m = 0;
    //     struct ListNode *fast_ptr = head->next;
    //     m = (m != 1) ? 1 : m;
    // }
    // else{
    //     if(m == 1) m = 0;
    //     fast_ptr = head;
    // }
    //
    // for(int i = 0; i < m; i++){ 
    //     fast_ptr = fast_ptr->next->next;
    //     i++;
    // }
    //
    // slow_ptr = fast_ptr->next;
    // fast_ptr->next = slow_ptr->next;
    // free(slow_ptr);

    // for(int i = 0; i < m; i++){ 
    //     slow_ptr = slow_ptr->next;
    //     fast_ptr = fast_ptr->next->next;
    //     i++;
    // }   
    //
    // if(m % 2==0){
    //     fast_ptr = slow_ptr->next->next;    
    // }
    //
    // if(n == 1){ 
    //     fast_ptr->next = NULL;
    // }
    // if(n == 1 && m % 2==0){
    //     slow_ptr->next->next = NULL;
    // }
    //
    // slow_ptr = fast_ptr->next;
    // fast_ptr->next = slow_ptr->next;
    // free(slow_ptr);

    return head;
}

void print(struct ListNode *head){
    
    while(head != NULL){
        printf("[%d]->",head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main(){

    struct ListNode *head;

    add_lastt(&head, 1);
    add_lastt(&head, 2);
    add_lastt(&head, 3);
    add_lastt(&head, 4);
    add_lastt(&head, 5);
    //add_lastt(&head, 6);

    print(head);

    removeNthFromEnd(head, 2);

    print(head);

}
