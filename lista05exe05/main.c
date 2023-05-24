#include <stdio.h>
#include <stdlib.h>
/*5) Receba um número inteiro não negativo e faça uma função que percorra
a lista e remova todos os nós que contiverem esse número inteiro
armazenado neles. Faça todas as condições de controle necessárias
para as remoções sejam corretas.*/
struct Elemento {
    int valor;
    struct Elemento *prox;
};

typedef struct Elemento Elemento;
typedef Elemento* Lista;

int insereFinal(Lista* li, int val) {
    if (li == NULL) return 0;
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if (no == NULL) return 0;
    no->valor = val;
    no->prox = NULL;
    if ((*li) == NULL) {
        *li = no;
    } else {
        Elemento *aux = *li;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

Lista constroiLista(int v[], int n) {
    Lista li = NULL;
    for (int i = 0; i < n; i++) {
        insereFinal(&li, v[i]);
    }
    return li;
}

void exibeLista(Lista li) {
    printf("Valores da lista: ");
    Elemento *aux = li;
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}
void removeElementos(Lista *li, int valor) {
    if (li == NULL || *li == NULL)
        return;

    Elemento *atual = *li;
    Elemento *anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == valor) {
            if (anterior == NULL) {
                *li = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            atual = (anterior == NULL) ? *li : anterior->prox;
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
}
int main() {
    int v[] = {5, 8, 9, 25};
    int n = 4;
    Lista li = constroiLista(v, n);
    removeElementos(&li,9);
    exibeLista(li);
    return 0;
}
/*A função removeElementos recebe uma lista encadeada como parâmetro e um valor inteiro que deve ser removido de todos os
 * elementos da lista que o contêm.
A função começa verificando se a lista passada é válida, ou seja, se é diferente de NULL e se o ponteiro para o início da
 lista é diferente de NULL. Caso contrário, a função simplesmente retorna sem fazer nada.
A seguir, a função percorre a lista com dois ponteiros: atual e anterior. O ponteiro atual aponta para o primeiro elemento
 da lista, enquanto o ponteiro anterior é inicializado como NULL.
O loop while é executado até o fim da lista, e a cada iteração, o ponteiro atual é atualizado para apontar para o próximo
 elemento da lista e o ponteiro anterior é atualizado para apontar para o elemento anterior.
Se o valor do elemento atual é igual ao valor passado como parâmetro, o elemento é removido da lista. O ponteiro prox do
 elemento anterior é atualizado para apontar para o próximo elemento, e o elemento atual é removido da memória com a função free.
Em seguida, o ponteiro atual é atualizado para apontar para o próximo elemento, que pode ser o primeiro elemento da lista
 (se o elemento removido era o primeiro da lista) ou o próximo elemento após o elemento removido. O ponteiro anterior p
 ermanece apontando para o elemento anterior.
Se o valor do elemento atual não é igual ao valor passado como parâmetro, os ponteiros atual e anterior são atualizados
 para o próximo elemento da lista, e o loop continua até que o último elemento seja alcançado.
Ao final do loop, a lista é modificada para conter apenas os elementos que não contêm o valor passado como parâmetro.*/