#include "stack.h"
#include <stdlib.h>
#include <string.h>

void init(Stack* stack) 
{
    stack->top = NULL;
}

bool isEmpty(Stack* stack)
{
    return stack->top == NULL;
}

bool push(Stack* stack, void* data, size_t size)
{
    No* new = malloc(sizeof(No));
    if(new == NULL)
        return false;
    new->data = malloc(size);
    memcpy(new->data,data,size);
    new->next = stack->top;
    stack->top = new;
    return true;
}

void* pop(Stack* stack)
{
    if(isEmpty(stack)) return NULL;
    No* temp = stack->top;
    void* recovery = temp->data;
    stack->top = temp->next;
    free(temp);
    return recovery;
}

void* peek(Stack* stack)
{
    if(isEmpty(stack))
        return NULL;
    return stack->top->data;
}
