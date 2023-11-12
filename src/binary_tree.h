#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct BinaryTreeNode {
    void* value;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
};

typedef struct BinaryTreeNode BinaryTreeNode;

BinaryTreeNode* tree_node_create(void* value);

int tree_node_get_node_count(BinaryTreeNode* node);

int tree_node_get_height(BinaryTreeNode* node);

int tree_node_get_leaf_count(BinaryTreeNode* node);

void tree_node_bst_insert(BinaryTreeNode* node, void* value, int (*compfn)(void*, void*));

void tree_node_free(BinaryTreeNode* node);

void tree_node_for_each(BinaryTreeNode* node, void (*fn)(void*));

#endif

