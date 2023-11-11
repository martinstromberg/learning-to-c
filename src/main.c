#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "integer_stack.h"
#include "sorting.h"
#include "utils.h"

int main() {
    srand(time(NULL)); // initializes srand, call only once

    IntStack* stack = int_stack_create();
    if (!stack) {
        fprintf(stderr, "The program failed to allocate an Int Stack!\n");
        exit(EXIT_FAILURE);
    }

    int_stack_push(stack, 5);
    int_stack_push(stack, 4);
    int_stack_push(stack, 3);
    int_stack_push(stack, 2);
    int_stack_push(stack, 1);

    printf("Stack size: %d\n", int_stack_size(stack));
    while (int_stack_peek(stack)) {
        int* value = int_stack_pop(stack);

        printf("Value: %d\n", *value);
        free(value);
    }

    free(stack);

    return 0;
}
