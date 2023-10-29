#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

void print_integers(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int get_random_int_in_range(int min, int max) {
    if (min > max) {
        fprintf(stderr, "Error: min is greater than max.\n");
        exit(1);
    }

    return min + (rand() % (max - min + 1));
}

void set_random_ints_with_range(int arr[], int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        arr[i] = get_random_int_in_range(min, max);
    }
}
