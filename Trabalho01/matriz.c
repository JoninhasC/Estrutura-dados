#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"




Matriz criaMatriz(int linhas, int colunas) {
    Matriz ma = (Matriz) malloc(sizeof (struct matriz));
    if (ma != NULL) {
        ma->x = linhas;
        ma->y = colunas;
        ma->inicio = (Elemento*) malloc(sizeof (Elemento));
        ma->inicio->valor = 0;
        ma->inicio->cima = NULL;
        ma->inicio->baixo = NULL;
        ma->inicio->esquerda = NULL;
        ma->inicio->direita = NULL;
        Elemento *atual = ma->inicio;
        for (int i = 0; i < linhas; i++) {
            Elemento *linha_atual = atual;
            for (int j = 0; j < colunas; j++) {
                Elemento *novo_elemento = (Elemento*) malloc(sizeof (Elemento));
                novo_elemento->valor = 0;
                novo_elemento->cima = NULL;
                novo_elemento->baixo = NULL;
                novo_elemento->esquerda = linha_atual;
                novo_elemento->direita = NULL;
                linha_atual->direita = novo_elemento;
                linha_atual = novo_elemento;
            }
            atual->baixo = linha_atual;
            atual = linha_atual;
        }
    }
    return ma;
}