#include <stdio.h>
#include <stdlib.h>

struct fila
{
    int info;
    struct fila *prox;
    struct fila *ant;
};

struct nodesc
{
    struct fila *ini;
    struct fila *fim;
};

typedef struct nodesc *noDesc;

int inicializa_noDesc(noDesc *no)
{
    *no = (noDesc)malloc(sizeof(struct nodesc));
    if (!(*no))
    {
        return 0;
    }
    else
    {
        (*no)->ini = NULL;
        (*no)->fim = NULL;
        return 1;
    }
}

int enfileirar(noDesc n, int elem)
{
    struct fila *novo = (struct fila *)malloc(sizeof(struct fila));
    if (!novo)
    {
        return 0;
    }
    novo->info = elem;
    novo->prox = NULL;
    novo->ant = n->fim;

    if (n->fim == NULL)
    {
        n->ini = novo;
    }
    else
    {
        n->fim->prox = novo;
    }

    n->fim = novo;

    return 1;
}

int desenfileirar(noDesc n, int *elem)
{
    if (n->ini == NULL)
    {
        return 0;
    }

    struct fila *aux = n->ini;
    *elem = aux->info;

    n->ini = aux->prox;
    if (n->ini == NULL)
    {
        n->fim = NULL;
    }
    else
    {
        n->ini->ant = NULL;
    }

    free(aux);

    return 1;
}

int main()
{
    noDesc n;
    inicializa_noDesc(&n);

    int i, elem;
    for (i = 0; i < 5; i++)
    {
        enfileirar(n, i + 1);
    }

    while (desenfileirar(n, &elem))
    {
        printf("%d ", elem);
    }
    printf("\n");

    free(n);

    return 0;
}
/*
A estrutura de dados fila é definida como uma lista duplamente encadeada, onde cada elemento possui um campo info para
 armazenar o valor, um campo prox que aponta para o próximo elemento da fila e um campo ant que aponta para o elemento
 anterior da fila. A estrutura de dados nodesc é definida como um ponteiro para os nós de início e fim da fila.
A função inicializa_noDesc aloca a memória para um nó da lista duplamente encadeada e inicializa os campos ini e fim como
 NULL. Retorna 1 em caso de sucesso na alocação de memória e 0 caso contrário.
A função enfileirar recebe um nó da fila n e um elemento a ser inserido na fila elem. Ela aloca memória para um novo
 elemento da fila, inicializa os seus campos e o insere no fim da fila. Retorna 1 em caso de sucesso na alocação de memória
 e 0 caso contrário.
A função desenfileirar recebe um nó da fila n e um ponteiro para uma variável elem que receberá o valor do primeiro elemento
 da fila. Ela remove o primeiro elemento da fila, atualiza o início da fila e libera a memória do elemento removido. Retorna
 se a operação foi bem-sucedida e 0 caso contrário.
No main, a função inicializa_noDesc é chamada para criar um nó da lista duplamente encadeada. Em seguida, a função enfileirar
 é chamada cinco vezes para inserir valores na fila. Depois, a função desenfileirar é chamada em um loop while para retirar e
 imprimir cada elemento da fila. Por fim, a memória alocada para o nó da lista é liberada com a função free*/