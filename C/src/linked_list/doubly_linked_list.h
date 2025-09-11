#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct NodeDll {
    void* data;
    struct NodeDll* next;
    struct NodeDll* prev;
} NodeDll;

typedef struct DoublyLinkedList {
    NodeDll* head;
    NodeDll* tail;
    int size;
} DoublyLinkedList;

void initdll(DoublyLinkedList* dllist);
bool pushdll(DoublyLinkedList* dllist, void* data, size_t size);
NodeDll* removedll(DoublyLinkedList* dllist, NodeDll* address);
void cleardll(DoublyLinkedList* dllist);
NodeDll* getNodedll(DoublyLinkedList* dllist, int index);
bool insertdll(DoublyLinkedList* dllist, int index, void* data, size_t size);

#endif