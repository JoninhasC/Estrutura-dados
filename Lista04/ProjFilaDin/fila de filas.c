#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"

struct fila {
    Fila *f;
    struct fila *prox;
};

typedef struct fila FilaF;

int main() {
    // criando a fila de filas
    FilaF *ff = (FilaF*) malloc(sizeof(FilaF));
    ff->f = cria_Fila();
    ff->prox = NULL;

    // criando algumas filas
    Fila *f1 = cria_Fila();
    Fila *f2 = cria_Fila();

    // inserindo as filas na fila de filas
    insere_Fila(ff->f, f1);
    insere_Fila(ff->f, f2);

    // liberando as filas da fila de filas
    while (!Fila_vazia(ff->f)) {
        Fila *f = (Fila*) ff->f->inicio->dados;
        libera_Fila(f);
        remove_Fila(ff->f);
    }

    // liberando a fila de filas
    free(ff);

    return 0;
}
/*Esse código em C cria uma estrutura de dados que é uma fila de filas. É criada uma struct chamada "fila" que contém um ponteiro para uma fila e um ponteiro para a próxima "fila" da fila de filas. Em seguida, é criada uma typedef dessa struct chamada "FilaF".

No main(), a fila de filas é criada e é atribuída uma fila vazia a ela. Em seguida, são criadas duas filas diferentes e elas são inseridas na fila de filas através da função insere_Fila().

Depois, é realizada a liberação das filas inseridas na fila de filas através de um loop while que verifica se a fila de filas ainda não está vazia. É atribuída a uma variável "f" a fila que está no início da fila de filas e é liberada através da função libera_Fila(). Em seguida, essa fila é removida da fila de filas através da função remove_Fila().

Por fim, é liberada a memória alocada para a fila de filas através da função free().*/