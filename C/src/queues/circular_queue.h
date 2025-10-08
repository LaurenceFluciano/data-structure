#include <stdbool.h>
#include <stddef.h>
#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

typedef struct
{
    int first;
    int last;
    int arr[10];
} CircularQueue;

void enqueueqc(int value, CircularQueue* cq);
bool dequeueqc(int value, CircularQueue* cq);
int getLastqc(CircularQueue* cq);
int getFirstqc(CircularQueue* cq);

#endif