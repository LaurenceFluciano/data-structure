#include "binary_tree.h" 
#include <stdio.h>

int main()
{
    int data1 = 5;
    int data2 = 4;
    int data3 = 3;
    int data4 = 7;

    NodeTree* firstNode = createNodeTree(&data1,sizeof(data1));
    NodeTree* secondNode = createNodeTree(&data2,sizeof(data2));
    NodeTree* thirdyNode = createNodeTree(&data3,sizeof(data3));

    NodeTree* other = createNodeTree(&data4,sizeof(data4));

    BinaryTree binaryTree;
    binaryTree.root = firstNode;
    binaryTree.depth++;

    binaryTree.root->left_child = secondNode;
    binaryTree.root->right_child = thirdyNode;
    binaryTree.depth++;

    secondNode->left_child = other;
    binaryTree.depth++;

    printf("Root:\n           %d", *(int*)binaryTree.root->data);

    printf("\nChilds:   / \\");
    printf("\n         %d   %d\n", *(int*)secondNode->data, *(int*)thirdyNode->data);
    printf("        /\n");
     printf("       %d\n",*(int*)other->data);

    return 0;
}