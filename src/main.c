#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "linked_list.h"

void printInt(void* data) {
    printf("%d\n", *((int*)data));
}

int main() {
    srand(time(NULL)); // initializes srand, call only once
    
    int values[] = { 1, 2, 3, 4, 5 };

    LinkedListNode* head = linked_list_node_create(&values[0]);
    for (int i = 1; i < 5; i++) {
        linked_list_node_append(head, &values[i]);
    }

    linked_list_for_each(head, printInt);

    linked_list_free(head);

    return 0;
}
