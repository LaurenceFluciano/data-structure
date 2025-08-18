#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct NodeTree
{
    void* data;
    struct NodeTree* left_child;
    struct NodeTree* right_child;
} NodeTree;

typedef struct BinaryTree
{
    NodeTree* root;
    int depth;
    int total_nodes;
    void (*insert)(struct BinaryTree*, NodeTree*);
} BinaryTree;


void initBTree(BinaryTree* bt); 
NodeTree* createNodeTree(void *data, size_t size);


#endif