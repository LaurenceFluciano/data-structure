#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct No {
    int data;
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
void push(Stack* stack, int data)
{
    No* new = malloc(sizeof(No));
    if(new == NULL)
    {
        fprintf(stderr, "Ocorreu um erro ao alocar memoria.\n");
        exit(1);
    }

    new->data = data;
    new->next = stack->top;
    stack->top = new;
}

// todo: remove top value of array
int pop(Stack* stack)
{
    if(isEmpty(stack)){
        fprintf(stderr, "Erro: pilha vazia.\n");
        exit(1);
    }

    No* temp = stack->top;
    int recovery = temp->data;
    stack->top = temp->next;
    free(temp);

    return recovery;
}

int peek(Stack* stack)
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

    push(&stack, 2);
    push(&stack, 8);
    push(&stack, 4);

    while(!isEmpty(&stack))
    {
        printf("%d\n", peek(&stack));
        pop(&stack);
    }
    return 0;
}