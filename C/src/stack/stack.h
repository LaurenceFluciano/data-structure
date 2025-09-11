#include <stdbool.h>
#include <stddef.h>
#ifndef STACK
#define STACK

typedef struct NodeStack {
    void* data;
    struct NodeStack* next;
} NodeStack;

typedef struct {
    NodeStack* top;
} Stack;

void initStack(Stack* stack) ;
bool isEmptyStack(Stack* stack);
bool pushStack(Stack* stack, void* data, size_t size);
void* popStack(Stack* stack);
void* peekStack(Stack* stack);

#endif