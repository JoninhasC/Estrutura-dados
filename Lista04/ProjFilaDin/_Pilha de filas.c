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
/*Esse � um programa em C que cria uma pilha de filas din�micas, insere duas filas nessa pilha e depois libera as filas e a pilha.

Na linha 7, � definida a estrutura fila que cont�m um ponteiro para outra fila e um ponteiro para a pr�xima fila. Na linha 9, � definido um novo tipo FilaF que representa essa estrutura.

Na fun��o principal, na linha 14, � criada uma pilha de filas din�micas com a fun��o cria_Pilha() da biblioteca PilhaDin.h. Nas linhas 17 e 18, s�o criadas duas filas din�micas com a fun��o cria_Fila() da biblioteca FilaDin.h.

Na linha 21 e 22, as duas filas s�o inseridas na pilha de filas com a fun��o insere_Pilha() da biblioteca PilhaDin.h.

Nas linhas 25 a 28, as filas s�o liberadas da pilha de filas com a fun��o remove_Pilha() da biblioteca PilhaDin.h e a fun��o libera_Fila() da biblioteca FilaDin.h.

Finalmente, na linha 31, a pilha de filas � liberada com a fun��o libera_Pilha() da biblioteca PilhaDin.h.

Esse programa usa as bibliotecas FilaDin.h e PilhaDin.h que n�o foram fornecidas na quest�o. Presume-se que elas contenham as defini��es e fun��es necess�rias para criar, inserir, remover e liberar filas e pilhas din�micas.*/