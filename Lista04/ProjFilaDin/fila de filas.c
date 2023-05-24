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
/*Esse c�digo em C cria uma estrutura de dados que � uma fila de filas. � criada uma struct chamada "fila" que cont�m um ponteiro para uma fila e um ponteiro para a pr�xima "fila" da fila de filas. Em seguida, � criada uma typedef dessa struct chamada "FilaF".

No main(), a fila de filas � criada e � atribu�da uma fila vazia a ela. Em seguida, s�o criadas duas filas diferentes e elas s�o inseridas na fila de filas atrav�s da fun��o insere_Fila().

Depois, � realizada a libera��o das filas inseridas na fila de filas atrav�s de um loop while que verifica se a fila de filas ainda n�o est� vazia. � atribu�da a uma vari�vel "f" a fila que est� no in�cio da fila de filas e � liberada atrav�s da fun��o libera_Fila(). Em seguida, essa fila � removida da fila de filas atrav�s da fun��o remove_Fila().

Por fim, � liberada a mem�ria alocada para a fila de filas atrav�s da fun��o free().*/