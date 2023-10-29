#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "data_types.h"
#include "sorting.h"
#include "utils.h"

int main() {
    srand(time(NULL)); // initializes srand, call only once

    const int AMOUNT = 10;
    const int MIN = -10;
    const int MAX = 10;

    int* numbers = (int*) malloc(AMOUNT * sizeof(int));

    set_random_ints_with_range(numbers, AMOUNT, MIN, MAX);
    print_integers(numbers, AMOUNT);

    IntegerLinkedListNode* head = linked_list_from_array(numbers, AMOUNT);
    free(numbers);
    print_linked_list_values(head);

    int len = linked_list_length(head);
    int* arr = linked_list_to_array(head);
    free_linked_integer_list(head);

    print_integers(arr, len);
    free(arr);

    return 0;
}
