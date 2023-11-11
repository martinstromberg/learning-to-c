#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "stack.h"

void printInt(void* data) {
    printf("%d\n", *((int*)data));
}

int main() {
    srand(time(NULL)); // initializes srand, call only once
    
    int values[] = { 1, 2, 3, 4, 5 };

    Stack* stack = stack_create();
    for (int i = 0; i < 5; i++) {
        stack_push(stack, &values[i]);
    }

    printf("Stack size: %d\n", stack_size(stack));

    while (stack_peek(stack)) {
        void* value = stack_pop(stack);
        printf("%d\n", *((int*)value));
        free(value);
    }

    free(stack);

    return 0;
}
