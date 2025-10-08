#include <stdio.h>
/**
 * Cada chave é passada pela função hash,
 * que gera um índice na tabela.
 * Esse índice aponta para a posição onde
 * o valor correspondente à chave está armazenado.
 */
int table[200];

int hashFunction(int i) {
    return i-1;
}

int getValue(int key) {
    return table[hashFunction(key)];
}

void setValue(int key, int value)
{
    table[hashFunction(key)] = value;
}

int main()
{
    for (int i = 0; i < 200; i++)
    {
        table[i] = 0;
    }

    setValue(4,20);
    setValue(3,21);

    printf("Testando hashmap: %d\n", getValue(3));

    return 0;
}