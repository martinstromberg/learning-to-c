#ifndef INTEGER_STACK_H
#define INTEGER_STACK_H

#include "integer_list.h"

struct IntStack {
    IntegerLinkedListNode* top;
};

typedef struct IntStack IntStack;

// Creates an empty stack
IntStack* int_stack_create();

// Peeks at the item on top of the stack. Returns NULL if the stack is empty.
int* int_stack_peek(IntStack* stack);

// Removes and returns the item on top of the stack.
// Returns NULL if the stack is empty.
int* int_stack_pop(IntStack* stack);

// Pushes a new item onto the stack
void int_stack_push(IntStack* stack, int value);

// Returns the size of the stack
int int_stack_size(IntStack* stack);

// Clears all the items from the stack
void int_stack_clear(IntStack* stack);

#endif

