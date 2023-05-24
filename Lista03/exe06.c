#include <stdio.h>
#include <stdlib.h>

typedef struct elemento* Pilha;

struct elemento{
    char letra;
    struct elemento *prox;
};
typedef struct elemento Elem;

Pilha* cria_Pilha(){
    // aloca dinamicamente o primeiro nó da pilha (cabeça)
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    //valida se foi criado
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

void libera_Pilha(Pilha* pi){
    if(pi != NULL){
        Elem* no;
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}

// push
int insere_Pilha(Pilha* pi, char n){
    //se == a NULL, não foi criada
    if(pi == NULL)
        return 0;
    //novo nó a ser criado
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    //valida se foi posssível criar
    if(no == NULL)
        return 0;

    no->letra = n;
    //prox na verdade é o "debaixo" dele na pilha
    no->prox = (*pi);
    *pi = no;

    //pi é o topo da pilha https://youtu.be/o4QKK7S_Ios?t=2312
    return 1;
}

// pop
int remove_Pilha(Pilha* pi){
    //se == a NULL, não foi criada
    if(pi == NULL)
        return 0;

    if((*pi) == NULL)
        return 0;

    Elem *no = *pi;
    // faz a cabeça apontar para o próx do nó e apaga ele
    *pi = no->prox;
    free(no);

    return 1;
}

void imprime_Pilha(Pilha* pi){
    if(pi == NULL)
        return;
    Elem* no = *pi;

    while(no != NULL){
        printf("%c", no->letra);
        no = no->prox;
    }
    printf("\n");

}

void pilha_inverso(Pilha* pi, Pilha* pi_invertido){
    Elem* no = *pi;

    while(no != NULL){
        Elem* no2;
        no2 = (Elem*) malloc(sizeof(Elem));

        no2->letra = no->letra;
        no2->prox = (*pi_invertido);
        *pi_invertido = no2;
        no = no->prox;
    }
}

int tamanho_Pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    int cont = 0;
    Elem* no = *pi;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int compara_pilha(Pilha* pi, Pilha* pi_invertido) {
    Elem* no = *pi;
    Elem* no2 = *pi_invertido;

    while(no != NULL){
        if(no->letra != no2->letra)
            return 1;

        no = no->prox;
        no2 = no2->prox;
    }

    return 0;
}

int main(){
    Pilha* pi = cria_Pilha();

    printf("Tamanho inicial: %d\n",tamanho_Pilha(pi));

    char aux;

    do {
        scanf("%c", &aux);
        if(aux == '\n')
            break;
        insere_Pilha(pi, aux);
    } while (1);

    Pilha* pi_invertido = cria_Pilha();

    pilha_inverso(pi, pi_invertido);

    imprime_Pilha(pi);

    if (compara_pilha(pi, pi_invertido) == 0)
        printf("\nString eh palindromo\n");
    else
        printf("\nString nao eh palindromo\n");

    libera_Pilha(pi);
    libera_Pilha(pi_invertido);

    system("pause");
    return 0;
}