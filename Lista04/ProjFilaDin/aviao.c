#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaDin.h"

typedef struct {
    int id;
    char companhia[50];
    int combustivel;
} Aviao;

typedef struct no {
    Aviao aviao;
    struct no* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
    int tamanho;
} Fila;

void criarFila(Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

void inserirFila(Fila* fila, Aviao aviao) {
    No* novoNo = (No*) malloc(sizeof(No));
    novoNo->aviao = aviao;
    novoNo->prox = NULL;
    if (fila->tamanho == 0) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        fila->fim->prox = novoNo;
        fila->fim = novoNo;
    }
    fila->tamanho++;
}

void removerFila(Fila* fila) {
    if (fila->tamanho == 0) {
        printf("Fila vazia\n");
        return;
    }
    No* noRemovido = fila->inicio;
    fila->inicio = noRemovido->prox;
    free(noRemovido);
    fila->tamanho--;
}
// Função que consulta o primeiro avião da fila
Aviao consulta_Fila(Fila* fila) {
    if (fila->tamanho == 0) { // se a fila estiver vazia, retorna um avião com número de voo igual a -1
        Aviao aviao_vazio;
        aviao_vazio.numero_voo = -1;
        return aviao_vazio;
    }
    return fila->inicio->aviao;
}

void imprimirFila(Fila* fila) {
    if (fila->tamanho == 0) {
        printf("Fila vazia\n");
        return;
    }
    printf("Avioes na fila de espera:\n");
    No* noAtual = fila->inicio;
    while (noAtual != NULL) {
        printf("Id: %d, Companhia: %s, Combustivel: %d\n", noAtual->aviao.id, noAtual->aviao.companhia, noAtual->aviao.combustivel);
        noAtual = noAtual->prox;
    }
}

void imprimirPrimeiroAviao(Fila* fila) {
    if (fila->tamanho == 0) {
        printf("Fila vazia\n");
        return;
    }
    printf("Informacoes do primeiro aviao:\n");
    printf("Id: %d, Companhia: %s, Combustivel: %d\n", fila->inicio->aviao.id, fila->inicio->aviao.companhia, fila->inicio->aviao.combustivel);
}

int main() {
    Fila filaEspera;
    criarFila(&filaEspera);

    int opcao = 0;

    do {
        printf("\n\n------- Aeroporto -------\n");
        printf("1. Listar numero de avioes aguardando na fila de decolagem\n");
        printf("2. Autorizar decolagem do primeiro aviao da fila\n");
        printf("3. Adicionar aviao a fila de espera\n");
        printf("4. Listar todos os avioes na fila de espera\n");
        printf("5. Listar caracteristicas do primeiro aviao da fila\n");
        printf("0. Sair\n");
        printf("--------------------------\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Numero de avioes aguardando na fila de decolagem: %d\n", tamanho_Fila(fila_decolagem));
                break;
            case 2:
                if (tamanho_Fila(fila_decolagem) == 0) {
                    printf("Nenhum aviao aguardando na fila de decolagem.\n");
                } else {
                    Aluno aluno_decolagem = remove_Fila(fila_decolagem);
                    printf("Aviao com numero de voo %d autorizado para decolagem.\n", aluno_decolagem.numero_voo);
                }
                break;
            case 3:
                printf("Numero de voo: ");
                int numero_voo;
                scanf("%d", &numero_voo);

                printf("Companhia aerea: ");
                char companhia_aerea[50];
                scanf("%s", companhia_aerea);

                printf("Modelo do aviao: ");
                char modelo_aviao[50];
                scanf("%s", modelo_aviao);

                Aviao novo_aviao;
                novo_aviao.numero_voo = numero_voo;
                strcpy(novo_aviao.companhia_aerea, companhia_aerea);
                strcpy(novo_aviao.modelo_aviao, modelo_aviao);

                insere_Fila(fila_decolagem, novo_aviao);
                printf("Aviao adicionado a fila de espera.\n");
                break;
            case 4:
                printf("Avioes na fila de espera:\n");
                imprime_Fila(fila_decolagem);
                break;
            case 5:
                if (tamanho_Fila(fila_decolagem) == 0) {
                    printf("Nenhum aviao aguardando na fila de decolagem.\n");
                } else {
                    Aviao primeiro_aviao = consulta_Fila(fila_decolagem);
                    printf("Numero de voo: %d\n", primeiro_aviao.numero_voo);
                    printf("Companhia aerea: %s\n", primeiro_aviao.companhia_aerea);
                    printf("Modelo do aviao: %s\n", primeiro_aviao.modelo_aviao);
                }
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    libera_Fila(fila_decolagem);
    return 0;
}