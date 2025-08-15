#include <stdbool.h>
#include <stddef.h>
#ifndef SIMPLE_QUEUE_H
#define SIMPLE_QUEUE_H


typedef struct No
{
    void* data;
    struct No* reference;
} No;

typedef struct
{
    No* front;
    No* tail;
    int size;
} Queues;

void init(Queues* queues);
void destroy(Queues* queues);
bool enqueue(Queues* queues, void* data, size_t size);
bool dequeue(Queues* queues);
void* getFront(Queues* queues);
void* getTail(Queues* queues);
int getSize(Queues* queues);

#endif