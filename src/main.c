#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "queue.h"

int main() {
    srand(time(NULL)); // initializes srand, call only once
    
    int values[] = { 1, 2, 3, 4, 5 };

    Queue* queue = queue_create();
    for (int i = 0; i < 5; i++) {
        queue_enqueue(queue, &values[i]);
    }

    printf("Stack size: %d\n", queue_length(queue));

    while (queue_length(queue) > 0) {
        void* value = queue_dequeue(queue);
        printf("%d\n", *((int*)value));
        free(value);
    }

    free(queue);

    return 0;
}
