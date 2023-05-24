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
    if(pi == NULL)
        return 0;

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
void inverte_pilha(Pilha* pi, Pilha* pi_invertido){
    Elem* no = *pi;

    while(no != NULL){
        char c = no->letras;
        // converte 'A' para 'B' e vice-versa
        if (c == 'A')
            c = 'B';
        else if (c == 'B')
            c = 'A';
        insere_Pilha(pi_invertido, c);
        no = no->prox;
    }
}

void imprime_Pilha(Pilha* pi){
    if(pi == NULL)
        return;

    Elem* no = *pi;
    while(no != NULL){
        printf("%c.", no->letras);
        no = no->prox;
    }
    printf("\n");
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

    while(no != NULL && no2 != NULL){
        if(no->letras != no2->letras)
            return 1;
        no = no->prox;
        no2 = no2->prox;
    }

    if(no == NULL && no2 == NULL)
        return 0;
    else
        return 1;
}

int main(){
    Pilha* pi = cria_Pilha();
    Pilha* pi2 = cria_Pilha();

    char aux, sw = 0;

    do {
        scanf("%c", &aux);

        if(aux == '\n')
            break;
        else if (aux == ' ')
            continue;
        else if(aux == 'C') {
            sw = 1;
            continue;
        }

        if (sw == 0)
            insere_Pilha(pi, aux);
        else
            insere_Pilha(pi2, aux);

    } while (1);
    inverte_pilha(pi,pi2);

    if(compara_pilha(pi, pi2) == 1)
        printf("\nEntrada segue a regra descrita\n");
    else
        printf("\nEntrada nao segue a regra descrita\n");

    libera_Pilha(pi);
    libera_Pilha(pi2);

    system("pause");
    return 0;
}
/*Este é um programa em C que utiliza pilhas para verificar se uma entrada segue uma determinada regra.
O programa lê uma sequência de caracteres do usuário, inserindo-os em uma pilha. Em seguida, inverte a pilha e compara a
sequência invertida com a sequência original, convertendo as letras 'A' em 'B' e vice-versa.
Se as sequências forem diferentes, o programa exibe a mensagem "Entrada não segue a regra descrita", caso contrário, exibe "Entrada segue a regra descrita".
O programa começa com a definição das estruturas e funções da pilha. A função cria_Pilha() cria uma pilha vazia e retorna um ponteiro para ela.
A função libera_Pilha() libera a memória alocada para a pilha. A função insere_Pilha() insere um elemento no topo da pilha.
A função remove_Pilha() remove o elemento do topo da pilha. A função inverte_pilha() inverte uma pilha, copiando seus elementos para outra pilha.
A função imprime_Pilha() imprime todos os elementos da pilha. A função tamanho_Pilha() retorna o número de elementos na pilha.
A função compara_pilha() compara duas pilhas, elemento por elemento.
Em seguida, o programa define as pilhas pi e pi2 e lê a sequência de caracteres do usuário, ignorando espaços em branco e armazenando
'C' em uma variável sw para indicar quando começar a inserir caracteres na segunda pilha pi2.
O programa então inverte a pilha pi para a pilha pi2 usando a função inverte_pilha(). Em seguida, compara as duas pilhas
usando a função compara_pilha(). Se as duas pilhas forem iguais, o programa exibe "Entrada segue a regra descrita", caso contrário,
exibe "Entrada não segue a regra descrita".
Por fim, o programa libera a memória alocada para as pilhas e pausa a execução do programa, aguardando que o usuário pressione uma tecla para finalizá-lo.*/