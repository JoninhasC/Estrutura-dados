#include <stdio.h>
#include <stdlib.h>

struct no{
    int info;
    struct no* prox;
};

typedef struct no No;

No* inicializa(){
    return NULL;
}

No* insere_inicio(No* lista, int valor){
    No* novo = (No*)malloc(sizeof(No));
    novo->info = valor;
    if(lista == NULL){
        novo->prox = novo; // o nó novo aponta para ele mesmo
        return novo;
    }
    novo->prox = lista->prox;
    lista->prox = novo;
    return lista;
}

No* insere_fim(No* lista, int valor){
    No* novo = (No*)malloc(sizeof(No));
    novo->info = valor;
    if(lista == NULL){
        novo->prox = novo; // o nó novo aponta para ele mesmo
        return novo;
    }
    novo->prox = lista->prox;
    lista->prox = novo;
    return novo;
}

No* remove_inicio(No* lista){
    if(lista == NULL){
        printf("Lista vazia!\n");
        return lista;
    }
    No* removido = lista->prox;
    if(removido == lista){ // há apenas um nó na lista
        free(removido);
        return NULL;
    }
    lista->prox = removido->prox;
    free(removido);
    return lista;
}

No* remove_fim(No* lista){
    if(lista == NULL){
        printf("Lista vazia!\n");
        return lista;
    }
    No* atual = lista;
    while(atual->prox != lista){
        atual = atual->prox;
    }
    No* removido = atual->prox;
    atual->prox = lista;
    if(removido == lista){ // há apenas um nó na lista
        free(removido);
        return NULL;
    }
    free(removido);
    return lista;
}

void percorre(No* lista){
    if(lista == NULL){
        printf("Lista vazia!\n");
        return;
    }
    No* atual = lista;
    do{
        printf("%d ", atual->info);
        atual = atual->prox;
    }while(atual != lista);
    printf("\n");
}

int main(){
    No* lista = inicializa();
    lista = insere_inicio(lista, 5);
    lista = insere_inicio(lista, 10);
    lista = insere_fim(lista, 15);
    lista = insere_fim(lista, 20);
    lista = remove_inicio(lista);
    lista = remove_fim(lista);
    lista = remove_inicio(lista);
    lista = remove_fim(lista);
    percorre(lista); // lista vazia
    return 0;
}
/*A estrutura no contém um campo para armazenar a informação e um ponteiro para o próximo nó. A função inicializa inicializa
 * a lista como vazia, retornando NULL.
As funções insere_inicio e insere_fim inserem um novo nó no início e no fim da lista, respectivamente. Se a lista estiver vazia
 , o novo nó aponta para ele mesmo. Caso contrário, o novo nó aponta para o próximo nó da lista e o último nó da lista aponta
 para o novo nó. A função insere_inicio retorna o ponteiro para o novo início da lista, enquanto a função insere_fim retorna
 o ponteiro para o novo fim da lista.
As funções remove_inicio e remove_fim removem o primeiro e o último nó da lista, respectivamente. Se a lista estiver vazia,
 é exibida uma mensagem de erro e a função retorna a lista inalterada. Se houver apenas um nó na lista, o nó é removido e a
 lista é definida como vazia, retornando NULL. Caso contrário, o primeiro ou o último nó é removido e a função retorna o
 ponteiro para o novo início ou fim da lista.
A função percorre exibe todos os valores armazenados na lista. Se a lista estiver vazia, é exibida uma mensagem de erro.
No main, a lista é inicializada, quatro nós são inseridos, dois nós são removidos e a lista é percorrida. No final, a lista está vazia.*/
