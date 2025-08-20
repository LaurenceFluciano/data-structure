#include "binary_tree.h"

void initBTree(BinaryTree* bt)
{
    bt->root = NULL;
    bt->height = 0;
    bt->total_nodes = 0;
}

NodeTree* createNodeTree(void *data, size_t size)
{
    NodeTree* temp = (NodeTree*)malloc(sizeof(NodeTree));
    if (!temp) return NULL;
    temp->data = malloc(size);
    temp->size = size;
    memcpy(temp->data, data, size);
    temp->left = temp->right = NULL;
    return temp;
}


// Depth-First Search (DFS) algorithms
// Visit root, left subtree and right subtree
void transversalPreOrder(NodeTree* node, DoublyLinkedList* dllist) 
{
    if (node == NULL) return;
    bool result = pushdll(dllist,node->data,node->size);
    transversalPreOrder(node->left, dllist);
    transversalPreOrder(node->right, dllist);
}

// Visit left subtree, root and right subtree
void transversalInOrder(NodeTree* node, DoublyLinkedList* dllist) 
{
    if (node == NULL) return;
    transversalInOrder(node->left, dllist);
    bool result = pushdll(dllist,node->data,node->size);
    transversalInOrder(node->right, dllist);
}

// Visit left subtree, right subtree and root
void transversalPostOrder(NodeTree* node, DoublyLinkedList* dllist)
{
    if(node == NULL) return;
    transversalPostOrder(node->left, dllist);
    transversalPostOrder(node->right, dllist);
    bool result = pushdll(dllist,node->data,node->size);
}

