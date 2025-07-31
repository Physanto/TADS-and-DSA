#ifndef STACK_H

#define STACK_H

typedef enum Result{
    OK,
    ERR_NULL_PTR,
    ERR_STACK_EMPTY,
    ERR_ELEMT_NOT_EXIST
}Result;

typedef struct Stack Stack;

Stack *create_stack();
Result destroy_stack(Stack **stack);
bool empty(Stack *stack);
Result peek(Stack *stack, char *element_peedked);
Result pop(Stack *stack, char *element_poped);
Result push(Stack *stack, char element, char *element_pushed);
Result search(Stack *stack, char element, char *element_searched);
Result print_stack(Stack *stack);

#endif
