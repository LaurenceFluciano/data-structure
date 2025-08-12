#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stddef.h>

typedef struct Node {
    void* data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct DoublyLinkedList {
    Node* head;
    Node* tail;
    int size;
} DoublyLinkedList;

/**
 *         head
 * x11 <- [Nó 1] -> x12
 * 
 */


void init(DoublyLinkedList* dllist)
{
    dllist->head = NULL;
    dllist->tail = NULL;
    dllist-> size = 0;
}

int push(DoublyLinkedList* dllist, void* data, size_t size)
{
    // Evite segfault
    if (!dllist) return 0;
    Node* child = malloc(sizeof(Node));
    if (!child) return 0;
    child->data = malloc(size); 
    memcpy(child->data, data, size);
    child->next = NULL;
    child->prev = dllist->tail;
    if (!dllist->head) dllist->head = child;
    else dllist->tail->next = child; 
    dllist->tail = child;  
    dllist->size++;
    return 1;
}

Node* removedll(DoublyLinkedList* dllist, Node* address)
{
    if (!dllist || !address) return NULL;

    if(address->prev)
        address->prev->next = address->next;
    else
        dllist->head = address->next;

    if(address->next)
        address->next->prev = address->prev;
    else
        dllist->tail = address->prev;

    address->next = NULL;
    address->prev = NULL;
    dllist->size--;
    return address;
}

void cleardll(DoublyLinkedList* dllist)
{
    Node* current = dllist->head;
    for(int i = 0; current != NULL; i++)
    {
        Node* next = current->next;
        removedll(dllist,current);
        current = next;
    }
}

Node* getNode(DoublyLinkedList* dllist, int index)
{
    if (!dllist || !dllist->head) return NULL;
    if (index == -1) return dllist->tail;      
    if (index < 0 || index >= dllist->size) return NULL;

    int opposite = dllist->size - (index + 1);
    Node* current;
    if (opposite > index)
    {
        current = dllist->head;
        for(int i = 0; i < index; i++)
        {
            current = current->next;
        }
    }
    else
    {
        current = dllist->tail;
        for(int i = 0; i < opposite; i++)
        {
            current = current->prev;
        }
    }

    return current;
}

int main()
{
    DoublyLinkedList example;

    int a = 3;

    init(&example);
    
    push(&example,&a,sizeof(a));


    printf("%d\n", *(int*)(example.head->data));



    return 0;
}