#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"
#include "PilhaDin.h"

struct fila {
    Fila *f;
    struct fila *prox;
};

typedef struct fila FilaF;

int main() {
    // criando a pilha de filas
    Pilha *pf = cria_Pilha();

    // criando algumas filas
    Fila *f1 = cria_Fila();
    Fila *f2 = cria_Fila();

    // inserindo as filas na pilha de filas
    insere_Pilha(pf, f1);
    insere_Pilha(pf, f2);

    // liberando as filas da pilha de filas
    while (!Pilha_vazia(pf)) {
        Fila *f = (Fila*) pf->topo->dados;
        libera_Fila(f);
        remove_Pilha(pf);
    }

    // liberando a pilha de filas
    libera_Pilha(pf);

    return 0;
}
/*Esse é um programa em C que cria uma pilha de filas dinâmicas, insere duas filas nessa pilha e depois libera as filas e a pilha.

Na linha 7, é definida a estrutura fila que contém um ponteiro para outra fila e um ponteiro para a próxima fila. Na linha 9, é definido um novo tipo FilaF que representa essa estrutura.

Na função principal, na linha 14, é criada uma pilha de filas dinâmicas com a função cria_Pilha() da biblioteca PilhaDin.h. Nas linhas 17 e 18, são criadas duas filas dinâmicas com a função cria_Fila() da biblioteca FilaDin.h.

Na linha 21 e 22, as duas filas são inseridas na pilha de filas com a função insere_Pilha() da biblioteca PilhaDin.h.

Nas linhas 25 a 28, as filas são liberadas da pilha de filas com a função remove_Pilha() da biblioteca PilhaDin.h e a função libera_Fila() da biblioteca FilaDin.h.

Finalmente, na linha 31, a pilha de filas é liberada com a função libera_Pilha() da biblioteca PilhaDin.h.

Esse programa usa as bibliotecas FilaDin.h e PilhaDin.h que não foram fornecidas na questão. Presume-se que elas contenham as definições e funções necessárias para criar, inserir, remover e liberar filas e pilhas dinâmicas.*/