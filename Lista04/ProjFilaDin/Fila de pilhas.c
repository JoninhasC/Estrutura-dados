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
/*Este programa cria uma estrutura de dados chamada "fila de pilhas". A ideia é ter uma fila que armazena diversas pilhas, e poder inserir ou remover pilhas dessa fila.

O programa começa incluindo as bibliotecas necessárias e as definições das estruturas de dados "Pilha" e "PilhaP". A estrutura "Pilha" é definida no arquivo "PilhaDin.h", e a estrutura "PilhaP" é definida neste próprio arquivo.

Em seguida, o programa cria a fila de pilhas "fp" e duas pilhas "p1" e "p2". As pilhas são inseridas na fila "fp" usando a função "insere_Pilha()".

Depois, o programa remove as pilhas da fila "fp" usando um laço de repetição "while". A cada iteração, o programa retira a pilha do topo da fila "fp", armazena a pilha em uma variável "p", libera a memória alocada para a pilha usando a função "libera_Pilha()" e remove a pilha da fila "fp" usando a função "remove_Pilha()". O laço se repete até que a fila "fp" esteja vazia.

Por fim, o programa libera a memória alocada para a fila de pilhas "fp" usando a função "free()".

Em resumo, este programa ilustra a criação e manipulação de uma fila de pilhas em linguagem C, usando as funções definidas nos arquivos "PilhaDin.h" e "FilaDin.h".*/