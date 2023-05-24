#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int valor;
    struct nodo *esq;
    struct nodo *dir;

};
typedef struct nodo Nodo;

Nodo *create( int valor){
    Nodo *no = malloc(sizeof (Nodo)) ;
    no->valor = valor;
    no->dir= NULL;
    no->esq= NULL;
    return no;
}
void add(Nodo *no, int valor ){
    if(valor< no->valor){
        if(no->esq == NULL)
            no->esq = create(valor);
        else
            add(no->esq, valor);
    }else{
        if(no->dir == NULL)
            no->dir = create(valor);
        else
            add(no->dir, valor);
    }
}
void imprimir(Nodo *no){
    if(no==NULL)
        return;
    printf("\n%d", no->valor);

    imprimir(no->esq);
    imprimir(no->dir);
}
void remover(Nodo *no , int valor){
    Nodo *filho = no;
    Nodo *pai;
    do {
        pai = filho;
        if(valor < filho->valor)
            filho = filho->esq;
        else if (valor > filho->valor)
            filho = filho->dir;


    } while ();




}

int main() {
    int n [4] ={2,1,8,4};
    Nodo *raiz = create(5);

    for (int i = 0; i < 4; ++i) {
        add(raiz, n[i]);
    }


    imprimir(raiz);


    return 0;
}
