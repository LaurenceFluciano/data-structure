#include "stack.h"
#include <stdlib.h>
#include <string.h>

void initStack(Stack* stack) 
{
    stack->top = NULL;
}

bool isEmptyStack(Stack* stack)
{
    return stack->top == NULL;
}

bool pushStack(Stack* stack, void* data, size_t size)
{
    NodeStack* new = (NodeStack*)malloc(sizeof(NodeStack));
    if(new == NULL)
        return false;
    new->data = malloc(size);
    memcpy(new->data,data,size);
    new->next = stack->top;
    stack->top = new;
    return true;
}

void* popStack(Stack* stack)
{
    if(isEmptyStack(stack)) return NULL;
    NodeStack* temp = stack->top;
    void* recovery = temp->data;
    stack->top = temp->next;
    free(temp);
    return recovery;
}

void* peekStack(Stack* stack)
{
    if(isEmptyStack(stack))
        return NULL;
    return stack->top->data;
}
