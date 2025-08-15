#include "simple.queue.h"
#include <stdlib.h>
#include <string.h>

void init(Queues* queues)
{
    queues->front = NULL;
    queues->tail = NULL;
    queues->size = 0;
}

void destroy(Queues* queues)
{
    No* current = queues->front;
    No* temp;
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

bool enqueue(Queues* queues, void* data, size_t size)
{
    No* new  = malloc(sizeof(No));
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

bool dequeue(Queues* queues)
{
    if(queues->front == NULL) 
        return false;
    No* temp = queues->front;
    queues->front = temp->reference;
    if (queues->front == NULL) 
        queues->tail = NULL;
    free(temp);
    queues->size--;
    return true;
}

void* getFront(Queues* queues)
{
    if(queues->front == NULL) return NULL;
    return queues->front->data;
}

void* getTail(Queues* queues)
{
    if(queues->tail == NULL) return NULL;
    return queues->tail->data;
}

int getSize(Queues* queues)
{
    return queues->size;
}
