#include <stdio.h>
#include <stdlib.h>

struct Elemento {
    float valor;
    struct Elemento *prox;
};

typedef struct Elemento Elemento;
typedef Elemento* Lista;

int insereFinal(Lista* li, float val) {
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

Lista constroiLista(float v[], int n) {
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
        printf("%.1f ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

int main() {
    float v[] = {5.5, 8, 9.1, 25};
    int n = 4;
    Lista li = constroiLista(v, n);
    exibeLista(li);
    return 0;
}
/*A função "insereFinal" recebe como argumentos um ponteiro para uma lista e um valor float. Ela cria um novo
 * elemento com o valor passado e adiciona esse elemento ao final da lista. A função retorna 1 se a inserção foi bem-sucedida e 0 caso contrário.
A função "constroiLista" recebe como argumentos um vetor de floats e o tamanho do vetor. Ela cria uma nova
 lista e adiciona cada valor do vetor à lista usando a função "insereFinal". A função retorna a lista criada.
A função "exibeLista" recebe como argumento uma lista e imprime na tela os valores contidos nessa lista.
No bloco principal, a função "constroiLista" é usada para criar uma lista com os valores {5.5, 8, 9.1, 25}.
 Em seguida, a função "exibeLista" é usada para imprimir esses valores na tela.
*/