#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "binary_tree.h"

int compare(void* a, void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return x - y;
}

int main() {
    srand(time(NULL)); // initializes srand, call only once
    
    int values[] = { 4, 2, 6, 1, 3, 5, 7 };
    BinaryTreeNode* root = tree_node_create(&values[0]);
    for (int i = 1; i < 7; i++) {
        tree_node_bts_insert(root, &values[i], compare);
    }

    printf("Size: %d\n", tree_node_get_node_count(root));
    printf("Height: %d\n", tree_node_get_height(root));
    printf("Leaves: %d\n", tree_node_get_leaf_count(root));

    return 0;
}
