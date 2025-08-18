#include "node_box.h"

char* nodeBox(char* message, int size)
{
    int finalSize = size + 3;

    char* box = malloc(finalSize + 1);
    box[0] = '+';
    for(int i = 1; i < finalSize-1; i++)
        box[i] = '-';
    box[finalSize-1] = '+';
    box[finalSize] = '\0';

    char* content = malloc(strlen(message) + 3);
    sprintf(content, "| %s |", message);

    char* finalMessage = malloc(strlen(box)*2 + strlen(content) + 3);
    sprintf(finalMessage, "%s\n%s\n%s", box, content, box);

    free(box);
    free(content);

    return finalMessage;
}