#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"
#include "PilhaDin.h"

struct pilha {
    Pilha *p;
    struct pilha *prox;
};

typedef struct pilha PilhaP;

int main() {
    // criando a fila de pilhas
    PilhaP *fp = (PilhaP*) malloc(sizeof(PilhaP));
    fp->p = cria_Pilha();
    fp->prox = NULL;

    // criando algumas pilhas
    Pilha *p1 = cria_Pilha();
    Pilha *p2 = cria_Pilha();

    // inserindo as pilhas na fila de pilhas
    insere_Pilha(fp->p, p1);
    insere_Pilha(fp->p, p2);

    // liberando as pilhas da fila de pilhas
    while (!Pilha_vazia(fp->p)) {
        Pilha *p = (Pilha*) fp->p->topo->dados;
        libera_Pilha(p);
        remove_Pilha(fp->p);
    }

    // liberando a fila de pilhas
    free(fp);

    return 0;
}
/*Este programa cria uma estrutura de dados chamada "fila de pilhas". A ideia � ter uma fila que armazena diversas pilhas, e poder inserir ou remover pilhas dessa fila.

O programa come�a incluindo as bibliotecas necess�rias e as defini��es das estruturas de dados "Pilha" e "PilhaP". A estrutura "Pilha" � definida no arquivo "PilhaDin.h", e a estrutura "PilhaP" � definida neste pr�prio arquivo.

Em seguida, o programa cria a fila de pilhas "fp" e duas pilhas "p1" e "p2". As pilhas s�o inseridas na fila "fp" usando a fun��o "insere_Pilha()".

Depois, o programa remove as pilhas da fila "fp" usando um la�o de repeti��o "while". A cada itera��o, o programa retira a pilha do topo da fila "fp", armazena a pilha em uma vari�vel "p", libera a mem�ria alocada para a pilha usando a fun��o "libera_Pilha()" e remove a pilha da fila "fp" usando a fun��o "remove_Pilha()". O la�o se repete at� que a fila "fp" esteja vazia.

Por fim, o programa libera a mem�ria alocada para a fila de pilhas "fp" usando a fun��o "free()".

Em resumo, este programa ilustra a cria��o e manipula��o de uma fila de pilhas em linguagem C, usando as fun��es definidas nos arquivos "PilhaDin.h" e "FilaDin.h".*/