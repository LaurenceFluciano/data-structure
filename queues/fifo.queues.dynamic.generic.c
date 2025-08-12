#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No
{
    void* data;
    struct No* reference;
} No;

typedef struct
{
    No* front;
    No* tail;
    int size;
} Queues;

void NotAllocateError()
{
    fprintf(stderr, "Nao foi possivel alocar memoria.");
    exit(1);
}

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

void enqueue(Queues* queues, void* data, size_t size)
{
    No* new  = malloc(sizeof(No));
    if (new == NULL) NotAllocateError();
    new->data = malloc(size);
    memcpy(new->data, data, size);
    new->reference = NULL;
    if(queues->tail != NULL) queues->tail->reference = new;
    if(queues->front == NULL) queues->front = new;
    queues->tail = new;
    queues->size++;
}

void dequeue(Queues* queues)
{
    if(queues->front == NULL) 
    {
        return;
    }
    No* temp = queues->front;
    queues->front = temp->reference;
    if (queues->front == NULL) {
        queues->tail = NULL;
    }
    free(temp);
    queues->size--;;
}

void* getFront(Queues* queues)
{
    if(queues->front == NULL) return -1;
    return queues->front->data;
}

void* getTail(Queues* queues)
{
    if(queues->tail == NULL) return -1;
    return queues->tail->data;
}

int getSize(Queues* queues)
{
    return queues->size;
}

int main()
{
    Queues queues;
    init(&queues);

    int a = 0;
    int b = 8;
    int c = 4;

    enqueue(&queues,a,sizeof(int));
    enqueue(&queues,b,sizeof(int));
    enqueue(&queues,c,sizeof(int));

    printf("Tamanho atual da fila: %d\n\n", getSize(&queues));

    while(getSize(&queues) > 0)
    {
        if(getFront(&queues) == -1) return 1;
        printf("Próximo valor a ser antendido: %d\n", getFront(&queues));
        dequeue(&queues);
    }

    return 0;
}