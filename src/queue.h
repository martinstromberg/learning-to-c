#ifndef QUEUE_H
#define QUEUE_H

#include "linked_list.h"

struct Queue {
    LinkedListNode* front;
};

typedef struct Queue Queue;

Queue* queue_create();

void queue_enqueue(Queue* queue, void* item);

void* queue_dequeue(Queue* queue);

int queue_length(Queue* queue);

void* queue_get_at_index(Queue* queue, int index);

void queue_clear(Queue* queue);

void queue_free(Queue* queue);

#endif

