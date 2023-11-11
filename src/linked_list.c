#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LinkedListNode* linked_list_node_create(void* value) {
    LinkedListNode* node = malloc(sizeof *node);
    if (!node) {
        fprintf(stderr, "linked_list_node_create: Memory allocation failure\n");
        exit(EXIT_FAILURE);
    }

    node->value = malloc(sizeof(value));
    if (node->value == NULL) {
        free(node);
        fprintf(stderr, "linked_list_node_create: Memory allocation failure\n");
        exit(EXIT_FAILURE);
    }

    memcpy(node->value, value, sizeof(value));
    node->next = NULL;

    return node;
}

void linked_list_free(LinkedListNode* head) {
    if (!head) {
        return;
    }

    while (head) {
        LinkedListNode* node = head;
        head = head->next;
        linked_list_node_free(node);
    }
}

void linked_list_node_free(LinkedListNode* node) {
    if (!node) {
        return;
    }

    node->next = NULL;
    if (node->value) {
        free(node->value);
        node->value = NULL;
    }
    free(node);
}

LinkedListNode* linked_list_node_append(LinkedListNode* head, void* value) {
    LinkedListNode* tail = linked_list_node_create(value);
    if (!tail) {
        return NULL;
    }

    if (!head) {
        return tail;
    }

    LinkedListNode* node = head;
    while (node->next) {
        node = node->next;
    }

    node->next = tail;

    return tail;
}

int linked_list_length(LinkedListNode* head) {
    int length = 0;
    if (!head) {
        return length;
    }

    LinkedListNode* node = head;
    while (node) {
        length++;
        node = node->next;
    }

    return length;
}

void linked_list_for_each(LinkedListNode* head, void (*func)(void*)) {
    if (!func) {
        return;
    }

    LinkedListNode* node = head;
    while (node) {
        func(node->value);
        node = node->next;
    }
}

void* linked_list_get_at_index(LinkedListNode* head, int index) {
    if (!head) {
        return NULL;
    }

    int i = 0;
    LinkedListNode* node = head;
    while (node) {
        if (i != index) {
            i++;
        }

        return node->value;
    }

    return NULL;
}

