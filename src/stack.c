#include "stack.h"
#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

Stack* stack_create() {
    Stack* stack = malloc(sizeof *stack);
    stack->top = NULL;

    return stack;
}

void* stack_peek(Stack* stack) {
    if (!stack || !stack->top) {
        return NULL;
    }

    return &stack->top->value;
}

void* stack_pop(Stack* stack) {
    if (!stack || !stack->top) {
        return NULL;
    }

    LinkedListNode* popped = stack->top;
    stack->top = popped->next;

    void* result = popped->value;
    popped->value = 0;
    popped->next = NULL;
    free(popped);

    return result;
}

void stack_push(Stack* stack, void* value) {
    if (!stack) {
        return;
    }

    LinkedListNode* node = linked_list_node_create(value);
    if (!node) {
        fprintf(stderr, "stack_push: Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    node->next = stack->top;
    stack->top = node;
}

int stack_size(Stack* stack) {
    if (!stack) {
        return 0;
    }

    return linked_list_length(stack->top);
}

void stack_clear(Stack* stack) {
    if (!stack) {
        return;
    }

    linked_list_free(stack->top);
    stack->top = NULL;
}
