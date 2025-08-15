#include <stdbool.h>
#include <stddef.h>
#ifndef STACK
#define STACK

typedef struct No {
    void* data;
    struct No* next;
} No;

typedef struct {
    No* top;
} Stack;

void init(Stack* stack) ;
bool isEmpty(Stack* stack);
bool push(Stack* stack, void* data, size_t size);
void* pop(Stack* stack);
void* peek(Stack* stack);

#endif