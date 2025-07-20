
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

/*
Se le proporcionan dos listas enlazadas no vacías que representan dos enteros no negativos. 
Los dígitos se almacenan en orden inverso y cada uno de sus nodos contiene un solo dígito. 
Sume los dos números y devuelva la suma como una lista enlazada.

Puedes asumir que los dos números no contienen ningún cero inicial, excepto el número 0 mismo.
*/

void add_last(struct ListNode **list_head, struct ListNode **tail, int element, int *size);

void print(struct ListNode *list){ 

    struct ListNode *current = list;

    while(current != NULL){
        printf("%d, ", current->val);
        current = current->next;
    }
    printf("\n");
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) { 

    struct ListNode *list;
    struct ListNode *tail;

    int number_l1 = l1->val;
    int number_l2 = l2->val;
    int size = 0;
    int carry = 0;
    int add = 0; 

    while(l1 != NULL || l2 != NULL){ 
        
        if(l1 == NULL) { number_l1 = 0;}
        if(l2 == NULL) { number_l2 = 0;}

        add = number_l1 + number_l2;

        struct ListNode *new_node = malloc(sizeof(struct ListNode));

        if(add >= 10){   
            add -= 10;
            add_last(&list, &tail,(add+carry),&size);
            carry = 1;
        }
        else {
            if((add+carry) == 10) {
                add_last(&list, &tail, (0), &size);
                carry = 1;
            }
            else {
                add_last(&list, &tail, (add+carry), &size);
                carry = 0;
            }
        }
        
        if(l1 != NULL) {
            l1 = l1->next;
            number_l1 = (l1 != NULL) ? l1->val : 0;
        }
        if(l2 != NULL) {
            l2 = l2->next;
            number_l2 = (l2 != NULL) ? l2->val : 0;
        }
    }

    if(carry == 1) add_last(&list,&tail, 1,&size);

    return list;
}

void add_last(struct ListNode **list_head, struct ListNode **tail, int element, int *size){ 

    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->val = element;
    new_node->next = NULL;
    

    if(*size == 0){
        *list_head = new_node;
        *tail = new_node;
        (*size)++;
        return;
    }

    (*tail)->next = new_node;
    *tail = new_node;
    size++;
}

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

void add_lasttt(struct ListNode **list_head, int element){ 

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

int main(){

    struct ListNode *l1;
    struct ListNode *l2;

    add_lastt(&l1, 9);
    add_lastt(&l1, 9);
    add_lastt(&l1, 9);

    print(l1);

    add_lasttt(&l2, 1);
    add_lasttt(&l2, 0);

    print(l2);

    printf("ESTA ES LA SUMA DE LAS LISTAS ENLAZADAS\n\n");

    print(addTwoNumbers(l1, l2));

    return 0;
}
