#ifndef STACK_H
#define STACK_H

#include "linked_list.h"

struct Stack {
    LinkedListNode* top;
};

typedef struct Stack Stack;

// Creates an empty stack
Stack* stack_create();

// Peeks at the item on top of the stack. Returns NULL if the stack is empty.
void* stack_peek(Stack* stack);

// Removes and returns the item on top of the stack.
// Returns NULL if the stack is empty.
void* stack_pop(Stack* stack);

// Pushes a new item onto the stack
void stack_push(Stack* stack, void* value);

// Returns the size of the stack
int stack_size(Stack* stack);

// Clears all the items from the stack
void stack_clear(Stack* stack);

#endif

