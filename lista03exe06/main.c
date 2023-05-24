#include <stdio.h>
#include <stdlib.h>

typedef struct elemento* Pilha;

struct elemento{
    char letras;
    struct elemento *prox;
};
typedef struct elemento Elem;

Pilha* cria_Pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
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

int insere_Pilha(Pilha* pi, char n){
    if(pi == NULL || *pi == NULL) // verifica se a pilha ou o primeiro elemento são nulos
        return 1;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->letras = n;
    no->prox = (*pi);
    *pi = no;

    return 1;
}


int remove_Pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    Elem *no = *pi;
    *pi = no->prox;
    free(no);

    return 1;
}

int imprime_Pilha(Pilha* pi){
    if(pi == NULL || *pi == NULL)
        return 0;

    Elem* no = *pi;
    while(no != NULL){
        printf("%c", no->letras);
        no = no->prox;
    }
    printf("\n");

}
void pilha_inverso(Pilha* pi, Pilha* pi_invertido){
    Elem* no = *pi;
    while(no != NULL){
        Elem* no2 = (Elem*) malloc(sizeof(Elem));
        if(no2 == NULL) {
            // caso a alocação de memória falhe, encerra a função
            return;
        }

        no2->letras = no->letras;
        no2->prox = (*pi_invertido);
        *pi_invertido = no2;
        no = no->prox;
    }
}
int tamanho_Pilha(Pilha* pi){
    if(pi == NULL || *pi == NULL) // verifica se a pilha ou o primeiro elemento são nulos
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
    int diferente = 0;
    while(no != NULL && no2 != NULL && !diferente){
        if(no->letras != no2->letras)
            diferente = 1;
        no = no->prox;
        no2 = no2->prox;
    }
    if (diferente)
        return 1;
    else if (no != no2)
        return 1;
    else
        return 0;
}


int main(){
    Pilha* pi = cria_Pilha();

    printf("Tamanho inicial: %d\n",tamanho_Pilha(pi));

    char auxilar;

    do {
        scanf("%c", &auxilar);
        if(auxilar == '\n')
            break;
        insere_Pilha(pi, auxilar);
    } while (2);

    Pilha* pi_invertido = cria_Pilha();

    pilha_inverso(pi, pi_invertido);

    imprime_Pilha(pi);

    if (compara_pilha(pi, pi_invertido) == 0)
        printf("\nString é palindromo\n");
    else
        printf("\nString nao é palindromo\n");

    libera_Pilha(pi);
    libera_Pilha(pi_invertido);

    system("pause");
    return 0;
}
/*O programa em questão implementa uma pilha em C e verifica se uma string é um palíndromo. Para isso, o programa lê a
string digitada pelo usuário e insere cada caractere na pilha. Em seguida, a função pilha_inverso é chamada para criar
uma segunda pilha com os elementos da primeira pilha invertidos. Por fim, a função compara_pilha é utilizada para verificar
se as duas pilhas são iguais, o que significa que a string é um palíndromo.
A função cria_Pilha é responsável por alocar dinamicamente o espaço de memória necessário para a pilha e inicializá-la com NULL.
A função libera_Pilha é utilizada para desalocar a memória utilizada pela pilha.
A função insere_Pilha insere um novo elemento na pilha. Ela aloca dinamicamente espaço para o novo elemento, atribui o valor
do parâmetro n à variável letras do novo elemento e atualiza o ponteiro prox para apontar para o topo da pilha. A função
remove_Pilha remove o elemento do topo da pilha e libera a memória alocada para esse elemento.
A função imprime_Pilha é utilizada para imprimir todos os elementos da pilha. Ela percorre a pilha a partir do topo e imprime
o valor de letras de cada elemento.
A função pilha_inverso é responsável por criar uma segunda pilha com os elementos da primeira pilha invertidos.
Ela percorre a primeira pilha a partir do topo e, para cada elemento, aloca dinamicamente espaço para um novo elemento na
segunda pilha, atribui o valor de letras do elemento da primeira pilha ao elemento da segunda pilha e atualiza o ponteiro prox
para apontar para o topo da segunda pilha.
A função tamanho_Pilha retorna o número de elementos presentes na pilha. Ela percorre a pilha a partir do topo contando o
número de elementos.
A função compara_pilha compara os elementos de duas pilhas. Ela percorre ambas as pilhas a partir do topo e verifica se os
valores de letras de cada elemento são iguais. Se houver diferença em algum elemento, a função retorna 1, caso contrário, retorna 0.
No main, o programa cria uma pilha, lê a string digitada pelo usuário e insere cada caractere na pilha. Em seguida, o
programa cria uma segunda pilha com os elementos da primeira pilha invertidos e chama a função compara_pilha para verificar se
as duas pilhas são iguais. Se as pilhas forem iguais, o programa imprime a mensagem "String é palindromo", caso contrário, imprime a mensagem
 "String nao é palindromo". Por fim, as duas pilhas são liberadas da memória.*/