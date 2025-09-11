#include "simple_queue.h"
#include <stdlib.h>
#include <string.h>

void initq(Queues* queues)
{
    queues->front = NULL;
    queues->tail = NULL;
    queues->size = 0;
}

void destroyq(Queues* queues)
{
    Nodeq* current = queues->front;
    Nodeq* temp;
    while (current != NULL)
    {
        temp = current;
        current = current->reference;
        free(temp);
    }
    queues->front = NULL;
    queues->tail = NULL;
    queues->size = 0;
}

bool enqueueq(Queues* queues, void* data, size_t size)
{
    Nodeq* new  = (Nodeq*)malloc(sizeof(Nodeq));
    if (new == NULL) return false;
    new->data = malloc(size);
    memcpy(new->data, data, size);
    new->reference = NULL;
    if(queues->tail != NULL) queues->tail->reference = new;
    if(queues->front == NULL) queues->front = new;
    queues->tail = new;
    queues->size++;
    return true;
}

bool dequeueq(Queues* queues)
{
    if(queues->front == NULL) 
        return false;
    Nodeq* temp = queues->front;
    queues->front = temp->reference;
    if (queues->front == NULL) 
        queues->tail = NULL;
    free(temp);
    queues->size--;
    return true;
}

void* getFrontq(Queues* queues)
{
    if(queues->front == NULL) return NULL;
    return queues->front->data;
}

void* getTailq(Queues* queues)
{
    if(queues->tail == NULL) return NULL;
    return queues->tail->data;
}

int getSizeq(Queues* queues)
{
    return queues->size;
}
