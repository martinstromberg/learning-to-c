#ifndef INTEGER_LIST_H
#define INTEGER_LIST_H

struct IntegerLinkedListNode {
    int value;
    struct IntegerLinkedListNode* next;
};

typedef struct IntegerLinkedListNode IntegerLinkedListNode;

IntegerLinkedListNode* create_integer_list_node(int value);

IntegerLinkedListNode* add_node_to_tail(IntegerLinkedListNode* head, int value);

int* integer_list_to_array(IntegerLinkedListNode* head);

IntegerLinkedListNode* integer_list_from_array(int arr[], int size);

void print_integer_list_values(IntegerLinkedListNode* head);

int integer_list_length(IntegerLinkedListNode* head);

void free_linked_integer_list_nodes(IntegerLinkedListNode* head, int node_count);
void free_linked_integer_list(IntegerLinkedListNode* head);

IntegerLinkedListNode* replace_integer_list_node_at(IntegerLinkedListNode* head, int index, int value);

#endif
