#include "binary_tree.h" 

int main()
{
    int values[] = {1,2,3,4,5,6,7,8};

    NodeTree* root = createNodeTree(&values[0],sizeof(int));
    root->left = createNodeTree(&values[1],sizeof(int));
    root->right= createNodeTree(&values[2],sizeof(int));
    root->left->left = createNodeTree(&values[3],sizeof(int));
    root->left->right = createNodeTree(&values[4],sizeof(int));
    root->right->right = createNodeTree(&values[5],sizeof(int));


    DoublyLinkedList dll;
    // TEM QUE INICIALIAR ANTES
    initdll(&dll);

    transversalPreOrder(root,&dll);

    NodeDll* temp = dll.head;
    for(int i = 0; i < dll.size; i++)
    {
        printf("%d\n",*(int*)temp->data);
        temp = temp->next;
    }

    return 0;
}