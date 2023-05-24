#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h" //inclui os Prot�tipos

//Defini��o do tipo lista
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elemento;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elemento* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento *no;
    no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){//lista vazia: insere in�cio
        *li = no;
    }else{
        Elemento *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento* no;
    no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    if((*li) == NULL){//lista vazia: insere in�cio
        no->prox = NULL;
        *li = no;
        return 1;
    }
    else{
        Elemento *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){//insere in�cio
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}

int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;
    Elemento *ant, *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if(no == NULL)//n�o encontrado
        return 0;

    if(no == *li)//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elemento *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elemento *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    if(no == (*li))//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elemento* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elemento* no = *li;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");

        no = no->prox;
    }
}
void remove_lista_matricula(Lista* li, int mat) {
    if(li == NULL || *li == NULL) {
        return; // verifica se a lista é nula ou vazia
    }

    Elemento* atual = *li;
    Elemento* ant = NULL;

    // busca a célula que contém o aluno a ser removido
    while(atual != NULL && atual->dados.matricula != mat) {
        ant = atual;
        atual = atual->prox;
    }

    // verifica se o aluno não foi encontrado na lista
    if(atual == NULL) {
        return;
    }

    // atualiza os ponteiros para remover a célula
    if(ant == NULL) { // se o aluno está na primeira posição
        *li = atual->prox;
    } else {
        ant->prox = atual->prox;
    }
    if(atual->prox != NULL) { // se o aluno não está na última posição
        atual->prox->ant = ant;
    }

    free(atual); // libera a célula removida da memória
}
void insere_lista_ordenada_chave(Lista* li, struct aluno al) {

    Elemento* novo = (Elemento*) malloc(sizeof(Elemento)); // aloca memória para o novo elemento
    novo->dados = al; // atribui os dados do novo elemento
    novo->prox = NULL;
    novo->ant = NULL;

    if(li == NULL) { // verifica se a lista é nula
        printf("Lista invalida!\n");
        free(novo); // libera a memória alocada para o novo elemento
        return;
    }

    if(*li == NULL) { // verifica se a lista está vazia
        *li = novo; // insere o novo elemento no início da lista
        return;
    }

    Elemento* atual = *li;
    Elemento* ant = NULL;

    while(atual != NULL && atual->dados.matricula < al.matricula) { // busca a posição de inserção
        ant = atual;
        atual = atual->prox;
    }

    if(ant == NULL) { // insere o novo elemento no início da lista
        novo->prox = *li;
        (*li)->ant = novo;
        *li = novo;
    } else if(atual == NULL) { // insere o novo elemento no final da lista
        ant->prox = novo;
        novo->ant = ant;
    } else { // insere o novo elemento no meio da lista
        novo->prox = atual;
        novo->ant = ant;
        ant->prox = novo;
        atual->ant = novo;
    }
}
int conta_lista_nota(Lista* li, int n1) {
    if(li == NULL || *li == NULL) {
        printf("Lista vazia!\n");
        return 0;
    }

    int cont = 0;
    Elemento* atual = *li;

    while(atual->prox != NULL) {
        atual = atual->prox;
        if(atual->dados.n1 == n1) {
            cont++;
        }
    }

    *li = atual;

    return cont;
}
