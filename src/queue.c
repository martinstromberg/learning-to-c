#include "queue.h"
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

Queue* queue_create() {
    Queue* queue = malloc(sizeof *queue);
    if (!queue) {
        fprintf(stderr, "queue_create: Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    queue->front = NULL;

    return queue;
}

void queue_enqueue(Queue* queue, void* item) {
    if (!queue) {
        return;
    }

    if (queue->front) {
        linked_list_node_append(queue->front, item);
        return;
    }

    LinkedListNode* node = linked_list_node_create(item);
    if (!node) {
        return;
    }

    queue->front = node;
}

void* queue_dequeue(Queue* queue) {
    if (!queue) {
        return NULL;
    }

    LinkedListNode* node = queue->front;
    queue->front = node->next;

    void* retval = node->value;

    node->value = NULL;
    node->next = NULL;
    free(node);

    return retval;
}

int queue_length(Queue* queue) {
    if (!queue) {
        return 0;
    }

    return linked_list_length(queue->front);
}

void* queue_get_at_index(Queue* queue, int index) {
    if (!queue) {
        return NULL;
    }

    return linked_list_get_at_index(queue->front, index);
}

void queue_clear(Queue* queue) {
    if (!queue) {
        return;
    }
    
    while (queue->front) {
        void* node = queue_dequeue(queue);
        free(node);
    }
}

