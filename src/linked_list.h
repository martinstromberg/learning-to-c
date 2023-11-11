#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Represents a generic linked list node
struct LinkedListNode {
    void* value;
    struct LinkedListNode* next;
};

// Type alias for `struct LinkedListNode`
typedef struct LinkedListNode LinkedListNode;

// Creates a new linked list node with the provided value
LinkedListNode* linked_list_node_create(void* value);

// Frees all items in the linked list
void linked_list_free(LinkedListNode* head);

// Frees a single linked list node
void linked_list_node_free(LinkedListNode* node);

// Appends a value to the tail of the list. Returns the created node????
LinkedListNode* linked_list_node_append(LinkedListNode* head, void* value);

// Returns the length of the linked list
int linked_list_length(LinkedListNode* head);

// Calls the function for each node in the linked list
void linked_list_for_each(LinkedListNode* head, void (*func)(void*));

void* linked_list_get_at_index(LinkedListNode* head, int index);

#endif

