# Data Structure

> ⚠️ Aviso: 
> 
> Este projeto educacional ainda está em desenvolvimento e não está completo!
> O objetivo é explicar cada estrutura de dado em linguagens diferentes de forma didática.
> No momento atual ela esta muito técnica e não está ideial para aprendizagem.

## Estruturas implementadas até agora


| Estrutura de dados | localização       | Descrição breve |
|--------------------|-------------------|-----------------|
| Stack LIFO         | `src/stack/stack.c` | Implementação genérica de pilhas | 
| Filas FIFO         | `src/queues/simple.queue,c` | Implementação genérica e simples de filas | 
| Doubly Linked List | `src/linked_list/doubly.linked.list.c` | Implementação genérica e simples de lista duplamente encadeada |

## Stack

### Conceito:

Pilhas são estruturas de dados LIFO (Last in First Out) isso significa que o ultimo valor colocado será o primeiro a sair. 

### Métodos disponíveis:

Os métodos de pilhas geralmente são `push`, `peek` e `pop` como você pode imaginar são exatamente os mesmo métodos implementados, no entanto no C adicionei alguns módulos extras, veja abaixo todas as funções disponíveis:


- init — Inicializa a pilha.
- isEmpty — Retorna true se a pilha estiver vazia.
- push — Adiciona um elemento no topo da pilha.
- pop — Remove e retorna o elemento do topo da pilha.
- peek — Retorna o elemento do topo da pilha sem removê-lo.

### Exemplo prático — Pilha como sistema de Undo

Imagine que você está usando um editor de texto.
Cada vez que você digita ou altera algo, o programa guarda o estado atual do documento.
Esses estados são armazenados **em uma pilha**.

- Quando você aperta Ctrl + Z → o último estado é removido da pilha (pop) e restaurado.
- Quando você digita algo novo → o novo estado é colocado no topo da pilha (push).

Esse comportamento segue exatamente a regra do LIFO (Last In, First Out):

> O último estado salvo é o primeiro a ser recuperado.

