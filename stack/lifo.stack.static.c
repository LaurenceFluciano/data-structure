#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 100

typedef struct Stack 
{
    char value[SIZE];
    struct Stack *next;
} Stack;


bool isEmpty(Stack *head)
{
    return head == NULL;
}

bool isFull()
{
    Stack *new = malloc(sizeof(Stack));
    if(new == NULL) {
        fprintf(stderr, "[ERRO] memoria insuficiente!");
        return true;    
    }
    free(new);
    return false;
}

void push(Stack **head, char value[])
{
    if(isFull())
        return;
    

    Stack *new = malloc(sizeof(Stack));
    if(new == NULL)
        return;
    

    strcpy(new->value,value);
    new->next = *head;
    *head = new;
}

int pop(Stack **head, char *buffer)
{
    if (isEmpty(*head)) 
        return 0;

    Stack *temp = *head;
    if (buffer != NULL)
        strcpy(buffer,temp->value);

    *head = temp->next;
    free(temp);

    return 1;
}

char* peek(Stack *head)
{
    if(isEmpty(head))
        return NULL;
    
    return head->value;
}



int main(int argc, char *argv[])
{   
    Stack *head = NULL;

    push(&head,"Hello");
    push(&head,"Current");
    

    printf("%s\n", peek(head));

    pop(&head, NULL);

    printf("%s\n", peek(head));




    return 0;
}