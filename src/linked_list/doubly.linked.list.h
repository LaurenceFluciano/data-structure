#include <stddef.h>
#include <stdbool.h>
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

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

void init(DoublyLinkedList* dllist);
bool push(DoublyLinkedList* dllist, void* data, size_t size);
Node* removedll(DoublyLinkedList* dllist, Node* address);
void cleardll(DoublyLinkedList* dllist);
Node* getNode(DoublyLinkedList* dllist, int index);
bool insert(DoublyLinkedList* dllist, int index, void* data, size_t size);

#endif