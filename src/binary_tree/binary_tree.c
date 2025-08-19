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

void transversalPreOrder(NodeTree* node, DoublyLinkedList* dllist) {
    if (node == NULL) return;

    bool result = pushdll(dllist,node->data,node->size);

    if(!result) {
        fprintf(stderr, "Erro: falha ao alocar memória.\n");
        exit(1);
    }

    transversalPreOrder(node->left, dllist);
    transversalPreOrder(node->right, dllist);
}