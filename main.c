#include "linked_list/doubly.linked.list.h"
#include <stdio.h>

int main()
{
    DoublyLinkedList example;

    int a = 1;
    int b = 3;
    int c = 4;


    init(&example);
    
    push(&example,&a,sizeof(a));
    push(&example,&b,sizeof(b));
    push(&example,&c,sizeof(c));

    Node* temp = example.head;
    for(int i = 0; i < example.size && temp != NULL; i++)
    {
        printf("%d\n", *(int*)(temp->data));
        temp = temp->next;
    }

    int m = 2;

    insert(&example,1,&m,sizeof(m));
    printf("\n");
    temp = example.head;
    for(int i = 0; i < example.size && temp != NULL; i++)
    {
        printf("%d\n", *(int*)(temp->data));
        temp = temp->next;
    }


    return 0;
}