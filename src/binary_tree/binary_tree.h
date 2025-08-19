#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "doubly_linked_list.h"
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct NodeTree
{
    void* data;
    struct NodeTree* left;
    size_t size;
    struct NodeTree* right;
} NodeTree;

typedef struct BinaryTree
{
    NodeTree* root;
    int height;
    int total_nodes;
} BinaryTree;


void initBTree(BinaryTree* bt); 
NodeTree* createNodeTree(void *data, size_t size);
void transversalPreOrder(NodeTree* node, DoublyLinkedList* dllist);


#endif