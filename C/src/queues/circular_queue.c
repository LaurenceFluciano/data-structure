#include "circular_queue.h"
#include <stdlib.h>
#include <string.h>

// first = 0
// last = -1

void enqueueqc(int value, CircularQueue* cq)
{
    int next = (cq->last + 1) % 10;
    if (next == cq->first) return;
    cq->arr[cq->last] = value;
    cq->last += next;
}

bool dequeueqc(int value, CircularQueue* cq)
{

}

int getLastqc(CircularQueue* cq)
{

}

int getFirstqc(CircularQueue* cq)
{

}