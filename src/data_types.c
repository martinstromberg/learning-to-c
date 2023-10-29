#include "data_types.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                              Linked List                                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

IntegerLinkedListNode* create_linked_list_node(int value) {
    IntegerLinkedListNode* node = malloc(sizeof *node);

    if (node) {
        node->value = value;
        node->next = NULL;
    }

    return node;
}

IntegerLinkedListNode* add_node_to_tail(IntegerLinkedListNode* head, int value) {
    IntegerLinkedListNode* tail = create_linked_list_node(value);

    if (head == NULL) {
        return tail;
    }

    IntegerLinkedListNode* node = head;
    while (node->next != NULL) {
        node = node->next;
    }

    node->next = tail;

    return tail;
}

IntegerLinkedListNode* linked_list_from_array(int arr[], int size) {
    if (size == 0) {
        return NULL;
    }

    IntegerLinkedListNode* head = malloc(sizeof *head);
    head->value = arr[0];
    head->next = NULL;
    
    for (int i = 1; i < size; i++) {
        add_node_to_tail(head, arr[i]);
    }

    return head;
}

int* linked_list_to_array(IntegerLinkedListNode* head) {
    int size = linked_list_length(head);

    int* arr = (int*) malloc(size * sizeof(int));
    int i = 0;
    while (head) {
        arr[i++] = head->value;
        head = head->next;
    }

    return arr;
}

void print_linked_list_values(IntegerLinkedListNode* head) {
    if (head == NULL) {
        return;
    }

    IntegerLinkedListNode* node = head;
    while (node) {
        printf("%d ", node->value);
        node = node->next;
    }

    printf("\n");
}

int linked_list_length(IntegerLinkedListNode* head) {
    int retval = 0;

    if (head == NULL) {
        return retval;
    }

    IntegerLinkedListNode* node = head;
    while (node) {
        retval++;
        node = node->next;
    }

    return retval;
}

void free_linked_integer_list_nodes(IntegerLinkedListNode* head, int node_count) {
    int i = 1;
    while (head) {
        IntegerLinkedListNode* node = head;
        head = head->next;
        node->next = NULL;
        free(node);

        if (i == node_count) {
            return;
        }

        i++;
    }
}

void free_linked_integer_list(IntegerLinkedListNode* head) {
    if (head == NULL) {
        return;
    }

    while (head) {
        IntegerLinkedListNode* node = head;
        head = head->next;
        node->next = NULL;
        free(node);
    }
}

IntegerLinkedListNode* replace_linked_list_node_at(IntegerLinkedListNode* head, int index, int value) {
    if (head == NULL) {
        return NULL;
    }

    IntegerLinkedListNode* new_head = malloc(sizeof *new_head);
    new_head->next = NULL;

    if (index == 0) {
        new_head->value = value;

        return new_head;
    }

    new_head->value = head->value;

    IntegerLinkedListNode* node = head->next;
    for (int i = 1; node != NULL; i++) {
        if (i == index) {
            IntegerLinkedListNode* tail = add_node_to_tail(new_head, value);
            tail->next = node->next;

            break;
        }

        add_node_to_tail(new_head, node->value);
        node = node->next;
    }

    return new_head;
}

