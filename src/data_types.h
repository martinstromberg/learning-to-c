#ifndef DATA_TYPES_H
#define DATA_TYPES_H

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                              Linked List                                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct IntegerLinkedListNode {
    int value;
    struct IntegerLinkedListNode* next;
};

typedef struct IntegerLinkedListNode IntegerLinkedListNode;

IntegerLinkedListNode* add_node_to_tail(IntegerLinkedListNode* head, int value);

int* linked_list_to_array(IntegerLinkedListNode* head);

IntegerLinkedListNode* linked_list_from_array(int arr[], int size);

void print_linked_list_values(IntegerLinkedListNode* head);

int linked_list_length(IntegerLinkedListNode* head);

void free_linked_integer_list_nodes(IntegerLinkedListNode* head, int node_count);
void free_linked_integer_list(IntegerLinkedListNode* head);

IntegerLinkedListNode* replace_linked_list_node_at(IntegerLinkedListNode* head, int index, int value);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                           Some other data type                            *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#endif 

