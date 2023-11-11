#include "binary_tree.h"
#include <stdlib.h>

BinaryTreeNode* tree_node_create(void* value) {
    BinaryTreeNode* node = malloc(sizeof *node);
    if (!node) {
        return NULL;
    }

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int tree_node_get_node_count(BinaryTreeNode* node) {
    if (!node) {
        return 0;
    }

    int left = tree_node_get_node_count(node->left);
    int right = tree_node_get_node_count(node->right);

    return 1 + left + right;
}

int tree_node_get_height(BinaryTreeNode* node) {
    if (!node) {
        return 0;
    }

    if (!node->left && !node->right) {
        return 0;
    }

    int left = tree_node_get_height(node->left);
    int right = tree_node_get_height(node->right);

    return 1 + ((left > right) ? left : right);
}

int tree_node_get_leaf_count(BinaryTreeNode* node) {
    if (!node) {
        return 0;
    }

    if (!node->left && !node->right) {
        return 1;
    }

    int left = tree_node_get_leaf_count(node->left);
    int right = tree_node_get_leaf_count(node->right);

    return left + right;
}

void tree_node_bts_insert(BinaryTreeNode* node, void* value, int (*compfn)(void*, void*)) {
    if (!node) {
        return;
    }

    int comp = compfn(node->value, value);
    if (comp < 0) {
        if (!node->right) {
            node->right = tree_node_create(value);
        } else {
            tree_node_bts_insert(node->right, value, compfn);
        }

        return;
    }

    if (!node->left) {
        node->left = tree_node_create(value);
    } else {
        tree_node_bts_insert(node->left, value, compfn);
    }

}

