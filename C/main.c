#include "unordered_vectors.h"
#include <time.h>
#include <stdio.h>

#define N 1000000

int main()
{
    clock_t start, end;

    start = clock();
    int* pureArray = malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++) {
        pureArray[i] = i;
    }
    end = clock();
    printf("Array puro: %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(pureArray);

    start = clock();
    UnorderedVectorStruct vec;
    UnorderedVectorStruct_Setup(&vec, N, sizeof(int));
    
    for(int i = 0; i < N; i++) {
        vec.insert(&vec, &(int){i});
    }
    end = clock();
    printf("UnorderedVector: %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(vec.values);

    return 0;
}