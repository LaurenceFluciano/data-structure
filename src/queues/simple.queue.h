#include <stdbool.h>
#include <stddef.h>
#ifndef SIMPLE_QUEUE_H
#define SIMPLE_QUEUE_H


typedef struct Nodeq
{
    void* data;
    struct Nodeq* reference;
} Nodeq;

typedef struct
{
    Nodeq* front;
    Nodeq* tail;
    int size;
} Queues;

void initq(Queues* queues);
void destroyq(Queues* queues);
bool enqueueq(Queues* queues, void* data, size_t size);
bool dequeueq(Queues* queues);
void* getFrontq(Queues* queues);
void* getTailq(Queues* queues);
int getSizeq(Queues* queues);

#endif