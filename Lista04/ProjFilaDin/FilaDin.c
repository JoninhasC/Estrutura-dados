#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h" //inclui os Protótipos
#include "PilhaDin.h"
//Definição do tipo Fila
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;
//Definição do Nó Descritor da Fila
struct fila{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

Fila* cria_Fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    if(fi != NULL){
        Elem* no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int consulta_Fila(Fila* fi, struct aluno *al){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    *al = fi->inicio->dados;
    return 1;
}
//push
int insere_Fila(Fila* fi, struct aluno al){
    if(fi == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if(fi->final == NULL)//fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}
//pop
int remove_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)//fila ficou vazia
        fi->final = NULL;
    free(no);
    fi->qtd--;
    return 1;
}

int tamanho_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    return fi->qtd;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL)
        return 1;
    if(fi->inicio == NULL)
        return 1;
    return 0;
}

int Fila_cheia(Fila* fi){
    return 0;
}

void imprime_Fila(Fila* fi){
    if(fi == NULL)
        return;
    Elem* no = fi->inicio;
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
int separa(Fila* f1, Fila* f2, int n){
    if(f1 == NULL || f2 == NULL)
        return 0;
    if(f1->inicio == NULL)//fila vazia
        return 0;

    // Encontra o nó com a matrícula n
    Elem* no = f1->inicio;
    Elem* ant = NULL;
    while(no != NULL && no->dados.matricula != n){
        ant = no;
        no = no->prox;
    }
    if(no == NULL)//não encontrou o elemento n
        return 0;

    // Separa a fila em duas
    if(ant == NULL){//n é o primeiro elemento da fila
        f1->inicio = no->prox;
    }
    else{
        ant->prox = no->prox;
    }
    f1->qtd--;

    f2->inicio = no;
    f2->final = f1->final;
    f2->qtd = 1;

    no->prox = NULL;
    f1->final = ant;

    // Move os elementos após o nó com matrícula n para a segunda fila
    Elem* aux = no->prox;
    while(aux != NULL){
        insere_Fila(f2, aux->dados);
        remove_Fila(f1);
        aux = aux->prox;
    }

    return 1;
}
void imprime_Primeiro(Fila* fi){
    if(fi == NULL)
        return;
    Elem* no = fi->inicio;
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
               no->dados.n2,
               no->dados.n3);
        printf("-------------------------------\n");
}
void testar_tamanho_filas(Fila* f1, Fila* f2) {
    if (f1 == NULL || f2 == NULL) {
        printf("Filas invalidas.\n");
        return;
    }

    if (f1->qtd > f2->qtd) {
        printf("A fila 1 possui mais elementos.\n");
    } else if (f2->qtd > f1->qtd) {
        printf("A fila 2 possui mais elementos.\n");
    } else {
        printf("As filas possuem a mesma quantidade de elementos.\n");
    }
}
void inverte_Fila(Fila* fi){
    if(fi == NULL)
        return;

    Pilha* p = cria_Pilha();
    struct aluno al;

    while(!Fila_vazia(fi)){
        consulta_Fila(fi, &al);
        insere_Pilha(p, al);
        remove_Fila(fi);
    }

    while(!Pilha_vazia(p)){
        consulta_Pilha(p, &al);
        insere_Fila(fi, al);
        remove_Pilha(p);
    }

    libera_Pilha(p);
}
void FuraFila(Fila* f, float x){
    if(f == NULL) return;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return;
    no->dados = x;
    if(f->inicio == NULL){//fila vazia
        no->prox = no;
        f->inicio = no;
        f->final = no;
    }
    else{
        no->prox = f->inicio;
        f->inicio = no;
        f->final->prox = no;
    }
    f->qtd++;
}
void preenche_fila_crescente(Fila* f1, Fila* f2, Fila* f3) {
    struct aluno al1, al2;
    int flag1 = 1, flag2 = 1;

    // Enquanto houver elementos nas duas filas
    while (!Fila_vazia(f1) && !Fila_vazia(f2)) {
        // Consulta o primeiro elemento de cada fila
        consulta_Fila(f1, &al1);
        consulta_Fila(f2, &al2);

        // Insere o elemento de menor valor na fila 3
        if (al1.matricula < al2.matricula) {
            insere_Fila(f3, al1);
            remove_Fila(f1);
        } else {
            insere_Fila(f3, al2);
            remove_Fila(f2);
        }
    }

    // Se ainda houver elementos na fila 1, adiciona-os na fila 3
    while (!Fila_vazia(f1)) {
        consulta_Fila(f1, &al1);
        insere_Fila(f3, al1);
        remove_Fila(f1);
    }

    // Se ainda houver elementos na fila 2, adiciona-os na fila 3
    while (!Fila_vazia(f2)) {
        consulta_Fila(f2, &al2);
        insere_Fila(f3, al2);
        remove_Fila(f2);
    }
}
void reverso(Fila *fi) {
    if (fi == NULL || fi->inicio == NULL) { // verifica se a fila existe e não está vazia
        return;
    }

    Fila *nova_fila = cria_Fila(); // cria uma nova fila

    while (fi->inicio != NULL) { // percorre a fila original
        struct aluno al;
        consulta_Fila(fi, &al); // obtém o elemento no início da fila
        insere_Fila(nova_fila, al); // insere o elemento no início da nova fila
        remove_Fila(fi); // remove o elemento da fila original
    }

    fi->inicio = nova_fila->inicio; // atualiza a fila original com a nova fila
    fi->final = nova_fila->final;
    fi->qtd = nova_fila->qtd;
    free(nova_fila); // libera a memória alocada para a nova fila
}

/*void furar_fila(Fila* f, int matricula, float divida) {
    if (f == NULL) {
        printf("Fila invalida.\n");
        return;
    }

    Aluno aluno;
    aluno.matricula = matricula;
    aluno.divida = divida;

    insere_Fila(f, aluno);
    printf("Aluno %d adicionado no inicio da fila.\n", matricula);
}*/
