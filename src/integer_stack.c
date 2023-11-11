#include "integer_stack.h"
#include "integer_list.h"
#include <stdlib.h>
#include <stdio.h>

IntStack* int_stack_create() {
    IntStack* stack = malloc(sizeof *stack);
    stack->top = NULL;

    return stack;
}

int* int_stack_peek(IntStack* stack) {
    if (!stack || !stack->top) {
        return NULL;
    }

    return &stack->top->value;
}

int* int_stack_pop(IntStack* stack) {
    if (!stack || !stack->top) {
        return NULL;
    }

    IntegerLinkedListNode* popped = stack->top;
    stack->top = popped->next;

    int* result = malloc(sizeof(int));
    *result = popped->value;
    popped->value = 0;
    popped->next = NULL;
    free(popped);

    return result;
}

void int_stack_push(IntStack* stack, int value) {
    if (!stack) {
        return;
    }

    IntegerLinkedListNode* node = create_linked_list_node(value);
    if (!node) {
        fprintf(stderr, "int_stack_push: Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    node->next = stack->top;
    stack->top = node;
}

int int_stack_size(IntStack* stack) {
    if (!stack) {
        return 0;
    }

    return linked_list_length(stack->top);
}

void int_stack_clear(IntStack* stack) {
    if (!stack) {
        return;
    }

    free_linked_integer_list(stack->top);
    stack->top = NULL;
}
