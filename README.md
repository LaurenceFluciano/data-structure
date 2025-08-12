# Data Struct in C

> ⚠️ Aviso: 
> 
> Este projeto educacional ainda está em desenvolvimento e não está completo!

## Como compilar e testar

Se quiser testar o código manualmente, use:

```bash
gcc main.c -o main
./main
```

Certifique-se de que o compilador `gcc` esteja instalado na sua máquina.

## Estruturas implementadas até agora


| Estrutura de Dados                     | Localização                            | Linguagem/Tipo                 | Descrição Breve                                                                 |
| -------------------------------------- | -------------------------------------- | ------------------------------ | ------------------------------------------------------------------------------- |
| **Linked List (Lista Ligada)**         | `linked list/main.c`                   | C                              | Lista duplamente ligada genérica, com funções de inserção, remoção e navegação. |
| **Fila FIFO Dinâmica**                 | `queues/fifo.queues.dynamic.c`         | C                              | Implementação clássica de fila FIFO usando alocação dinâmica.                   |
| **Fila FIFO Dinâmica Genérica**        | `queues/fifo.queues.dynamic.generic.c` | C                              | Versão genérica da fila FIFO dinâmica, suporta qualquer tipo de dado.           |
| **Fila Clássica (FIFO)**               | `queues/queue.classic.py`              | Python                         | Implementação básica de fila em Python.                                         |
| **Fila Simples**                       | `queues/simple.queue.py`               | Python                         | Implementação simples de fila em Python.                                        |
| **Pilha LIFO Dinâmica**                | `stack/lifo.stack.dynamic.c`           | C                              | Pilha dinâmica, implementação tradicional.                                      |
| **Pilha LIFO Dinâmica Genérica**       | `stack/lifo.stack.dynamic.generic.c`   | C                              | Pilha dinâmica genérica, suporta múltiplos tipos de dados.                      |
| **Pilha LIFO Estática**                | `stack/lifo.stack.static.c`            | C                              | Pilha implementada com array estático.                                          |
| **Pilha LIFO Dinâmica (sem extensão)** | `stack/lifo.stack.dynamic`             | Provavelmente C (sem extensão) | Versão da pilha dinâmica (sem extensão no nome do arquivo).                     |
| **Programa Principal da Pilha**        | `stack/main`                           | Provavelmente C (sem extensão) | Programa para testar as implementações de pilha.                                |
