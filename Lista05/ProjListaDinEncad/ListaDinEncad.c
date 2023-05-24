#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int inserirIndex(Lista* li, int index, struct aluno al) {
    if (li == NULL)
        return 0;
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if (no == NULL)
        return 0;
    no->dados = al;
    if ((*li) == NULL || index == 1) { // lista vazia ou inserção na primeira posição
        no->prox = *li;
        *li = no;
        return 1;
    } else {
        Elemento *aux = *li;
        int num = 0;
        while (num != index - 2) {
            aux = aux->prox;
            num++;
        }
        no->prox = aux->prox;
        aux->prox = no;
        return 1;
    }
}
void concatenar(Lista *li, Lista *li2){
    if(li == NULL || li2 == NULL)
        return;
    if (*li == NULL) {
        *li = *li2;
        return;
    }
    Elemento *no1 = *li;
    while (no1->prox != NULL){
        no1 = no1->prox;
    }
    no1->prox = *li2;
}
void fusaoListasOrdenadas(Lista *lista1, Lista *lista2) {
    if (*lista1 == NULL || *lista2 == NULL) {
        return;
    }
    Elemento *atual1 = *lista1, *atual2 = *lista2, *aux = NULL;
    while (atual1 != NULL && atual2 != NULL) {
        if (atual1->dados.matricula < atual2->dados.matricula) {
            aux = atual1;
            atual1 = atual1->prox;
        } else {
            aux = atual2;
            atual2 = atual2->prox;
        }
        if (*lista1 == aux) {
            *lista1 = aux;
        } else {
            Elemento *anterior = *lista1;
            while (anterior->prox != aux) {
                anterior = anterior->prox;
            }
            anterior->prox = aux;
        }
        aux->prox = (atual1 == NULL) ? atual2 : atual1;
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
int removeRepete(Lista *li){
    if (li == NULL)
        return 0;
    if ((*li) == NULL)
        return 0;
    Elemento *atual = *li, *aux;
    while (atual != NULL) {
        aux = atual->prox;
        while (aux != NULL && aux->dados.matricula != atual->dados.matricula) {
            aux = aux->prox;
        }
        if (aux != NULL) {
            atual->prox = aux->prox;
            free(aux);
        } else {
            atual = atual->prox;
        }
    }
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
int removeNo(Lista* li, int num ){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;
    Elemento *no = *li;
    if(no->dados.matricula == num){
        *li = no->prox;
        free(no);
        return 1;
    }
    return removeNo(&no->prox,num);
}
int verificarIgual(Lista* li1, Lista* li2) {
    if (*li1 == NULL && *li2 == NULL) {
        printf("As listas sao iguais.\n");
        return 1;
    } else if (*li1 == NULL || *li2 == NULL) {
        printf("As listas sao diferentes.\n");
        return 0;
    }
    Elemento* no1 = *li1;
    Elemento* no2 = *li2;
    if (no1->dados.matricula != no2->dados.matricula ||
        strcmp(no1->dados.nome, no2->dados.nome) != 0 ||
        no1->dados.n1 != no2->dados.n1 ||
        no1->dados.n2 != no2->dados.n2 ||
        no1->dados.n3 != no2->dados.n3) {
        printf("As listas sao diferentes.\n");
        return 0;
    }
    return verificarIgual(&no1->prox, &no2->prox);
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
void imprimiMatricula(Lista* li, int num){
    if (li == NULL )
        return;
    Elemento * no = *li;
    while (no != NULL && no->dados.matricula != num){
        no = no->prox;
    }
    if (no == NULL)
        printf("Aluno com matrícula %d não encontrado.\n", num);
    else{
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
               no->dados.n2,
               no->dados.n3);
        printf("-------------------------------\n");

    }
}
void imprimePosicao(Lista* li, int num){
    if (li == NULL || *li == NULL)
        return;
    int posicao = 1;
    Elemento* no = *li;
    while (no != NULL && posicao != num){
        no = no->prox;
        posicao++;
    }
    if (no == NULL)
        printf("Aluno na possicao %d não encontrado.\n", num);
    else {
        printf("Matricula: %d\n", no->dados.matricula);
        printf("Nome: %s\n", no->dados.nome);
        printf("Notas: %.1f %.1f %.1f\n", no->dados.n1,
               no->dados.n2,
               no->dados.n3);
        printf("-------------------------------\n");
    }
}


/*void Troca(Lista *li) {
    Elemento *no=li;

    if(li != NULL && no->prox != NULL) { // verifica se a célula não é nula e se possui uma célula seguinte
        Elemento *aux = no->prox;
        no->prox = aux->prox;
        aux->prox = li;
        if(no->ant != NULL) {
            no->ant->prox = aux;
        }
        aux->ant = no->ant;
        no->ant = aux;
        if(no->prox != NULL) {
            no->prox->ant = no;
        }
    }
}*/