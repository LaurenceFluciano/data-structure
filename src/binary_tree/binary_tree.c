#include "binary_tree.h"

void initBTree(BinaryTree* bt)
{
    bt->root = NULL;
    bt->depth = 0;
    bt->total_nodes = 0;
}

NodeTree* createNodeTree(void *data, size_t size)
{
    NodeTree* temp = (NodeTree*)malloc(sizeof(NodeTree));
    if (!temp) return NULL;
    temp->data = malloc(size);
    memcpy(temp->data, data, size);
    temp->left_child = temp->right_child = NULL;
    return temp;
}
