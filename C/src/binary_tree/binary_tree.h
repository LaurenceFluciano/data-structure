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
    int totalNodes;
} BinaryTree;


void initBTree(BinaryTree* bt); 
NodeTree* createNodeTree(void *data, size_t size);
void insertNodeTree(BinaryTree* binaryTree, NodeTree* node, int (*cmprFunc)(void* x, void* y));
void removeNodeTree(BinaryTree* binaryTree, void *data, int (*cmprFunc)(void* x, void* y));
void transversalPreOrder(NodeTree* node, DoublyLinkedList* dllist);
void transversalInOrder(NodeTree* node, DoublyLinkedList* dllist);
void transversalPostOrder(NodeTree* node, DoublyLinkedList* dllist);

#endif