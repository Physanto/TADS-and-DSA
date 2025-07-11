#ifndef LINKED_LIST

#define LINKED_LIST

typedef struct LinkedList LinkedList;

// prototipo de funciones

LinkedList *create_linked_list();
void destroyed_linked_list(LinkedList **);
int size_list(LinkedList *);
bool is_empty(LinkedList *);
void add_first(LinkedList *, int element);
int remove_first(LinkedList *);
void add_last(LinkedList *, int element);
int remove_last(LinkedList *); 
void print_list(LinkedList *);

#endif
