#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct No {
    void* data;
    struct No* next;
} No;

typedef struct {
    No* top;
} Stack;

void init(Stack* stack) 
{
    stack->top = NULL;
}

//todo: verify if the tops is null
bool isEmpty(Stack* stack)
{
    return stack->top == NULL;
}

// todo: when you push a data, the top will be the new addres
void push(Stack* stack, void* data, size_t size)
{
    No* new = malloc(sizeof(No));
    if(new == NULL)
    {
        fprintf(stderr, "Ocorreu um erro ao alocar memoria.\n");
        exit(1);
    }
    new->data = malloc(size);
    memcpy(new->data,data,size);
    new->next = stack->top;
    stack->top = new;
}

// todo: remove top value of array
void* pop(Stack* stack)
{
    if(isEmpty(stack)){
        fprintf(stderr, "Erro: pilha vazia.\n");
        exit(1);
    }

    No* temp = stack->top;
    void* recovery = temp->data;
    stack->top = temp->next;
    free(temp);

    return recovery;
}

void* peek(Stack* stack)
{
    if(isEmpty(stack)){
        fprintf(stderr, "Erro: pilha vazia.\n");
        exit(1);
    }

    return stack->top->data;
}

int main()
{
    Stack stack;
    init(&stack);

    int a = 1;
    int b = 2;
    int c = 3;

    push(&stack, &a,sizeof(int));
    push(&stack, &b,sizeof(int));
    push(&stack, &c,sizeof(int));

    while(!isEmpty(&stack))
    {
        printf("%d\n", *(int*)peek(&stack));
        pop(&stack);
    }
    return 0;
}