#include "doubly_linked_list.h"
#include <stdlib.h>
#include <string.h>

void initdll(DoublyLinkedList* dllist)
{
    dllist->head = NULL;
    dllist->tail = NULL;
    dllist-> size = 0;
}

bool pushdll(DoublyLinkedList* dllist, void* data, size_t size)
{
    // Avoid segfault
    if (!dllist) return false;
    NodeDll* child = (NodeDll*)malloc(sizeof(NodeDll));
    if (!child) return false;
    child->data = malloc(size); 
    memcpy(child->data, data, size);
    child->next = NULL;
    child->prev = dllist->tail;
    if (!dllist->head) dllist->head = child;
    else dllist->tail->next = child; 
    dllist->tail = child;  
    dllist->size++;
    return true;
}

NodeDll* removedll(DoublyLinkedList* dllist, NodeDll* address)
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
    NodeDll* current = dllist->head;
    for(int i = 0; current != NULL; i++)
    {
        NodeDll* next = current->next;
        NodeDll* result = removedll(dllist,current);
        free(result->data);
        free(result);
        current = next;
    }
}

NodeDll* getNodedll(DoublyLinkedList* dllist, int index)
{
    if (!dllist || !dllist->head) return NULL;
    if (index == -1) return dllist->tail;      
    if (index < 0 || index >= dllist->size) return NULL;
    int opposite = dllist->size - (index + 1);
    NodeDll* current;
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

bool insertdll(DoublyLinkedList* dllist, int index, void* data, size_t size)
{
    NodeDll* currentNode = getNodedll(dllist, index);
    if (!currentNode) return false;
    NodeDll* child = (NodeDll*)malloc(sizeof(NodeDll));
    if (!child) return false;
    child->data = malloc(size); 
    memcpy(child->data, data, size);
    child->next = currentNode;
    if(currentNode->prev != NULL){
        child->prev = currentNode->prev;
        currentNode->prev->next = child;
    } else child->prev = NULL;
    currentNode->prev = child;
    dllist->size++;
    return true;
} 