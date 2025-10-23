#include "binary_tree.h"

void initBTree(BinaryTree* bt)
{
    bt->root = NULL;
    bt->totalNodes = 0;
}

NodeTree* createNodeTree(void *data, size_t size)
{
    NodeTree* temp = (NodeTree*)malloc(sizeof(NodeTree));
    if (!temp) return NULL;
    temp->data = malloc(size);
    if (!temp->data) {
        free(temp);
        return NULL;
    }
    temp->size = size;
    memcpy(temp->data, data, size);
    temp->left = temp->right = NULL;
    return temp;
}

void insertNodeTree(BinaryTree* binaryTree, NodeTree* node, int (*cmprFunc)(void* x, void* y))
{
    if (binaryTree->root == NULL) {
        binaryTree->root = node;
        return;
    }

    node->left = NULL;
    node->right = NULL;

    NodeTree* current = binaryTree->root;

    while(current != NULL) {
        if (cmprFunc(node->data, current->data) > 0) {
            if (current->right == NULL) {
                current->right = node;
                break;
            }
            current = current->right;
        } else {
            if (current->left == NULL) {
                current->left = node;
                break;
            }
            current = current->left;
        }
    }
} 


// 1) Nó folha (sem filhos)
// 2) Nó com um filho
// 3) Nó com dois filhos

void removeNodeTree(BinaryTree* binaryTree, void *data, int (*cmprFunc)(void* x, void* y))
{
    NodeTree* current = binaryTree->root;
    NodeTree* parent = NULL;

    while(current != NULL && cmprFunc(current->data,data) != 0) {
        parent = current;
        if (cmprFunc(data, current->data) > 0) {
            current = current->right;
        } else {
            current = current->left;
        }
    }

    if (current == NULL) return;

    if (parent == NULL) {
        if (!binaryTree->root->left && !binaryTree->root->right) 
            binaryTree->root = NULL;
        else if (!binaryTree->root->left || !binaryTree->root->right)
        {
            if (binaryTree->root->left) binaryTree->root = binaryTree->root->left;
            else binaryTree->root = binaryTree->root->right;
        } else {
            NodeTree* successorParent = binaryTree->root;
            NodeTree* successor = binaryTree->root->right;
            while (successor->left) {
                successorParent = successor;
                successor = successor->left;
            }
            binaryTree->root->data = successor->data;
            if (successorParent->left == successor) successorParent->left = successor->right;
            else successorParent->right = successor->right;
            free(successor);
        }
        return;
    }

    // Node without children
    if (!current->left && !current->right)
    {
        if (cmprFunc(data, current->data) > 0) {
            parent->right = NULL;
        }
        else {
            parent->left = NULL;
        }
    }

    // Node with one child
    if (!current->left || !current->right) {
        NodeTree* child = NULL;
        if (current->left) child = current->left;
        else child = current->right;

        if (parent->left == current) parent->left = child;
        else parent->right = child;
    } else {
        // Node with two childrens
        NodeTree* successorParent = current;
        NodeTree* successor = current->right;
        while (successor->left) {
            successorParent = successor;
            successor = successor->left;
        }
        current->data = successor->data;
        if (successorParent->left == successor) successorParent->left = successor->right;
        else successorParent->right = successor->right;
        free(successor);
        return;
    }
    free(current);
    return;
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

