#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX 100
#include "PilhaDin.h" //inclui os Protótipos
int *cal;    //Aponta para regiao de memoria livre
int tos;   // Ponteiro para o topo da pilha
int *bos;  //Ponteiro para a base da pilha
//Definição do tipo Pilha
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Pilha* cria_Pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}
Pilha *pilha_copia (Pilha* p){
    if(p == NULL)
        return 0;
    if((*p) == NULL)
        return 0;
    Pilha* novapi = cria_Pilha();
    Pilha* Aux = cria_Pilha();
    Elem *no =*p;
    while (no != NULL){
        insere_Pilha(novapi, no->dados);
        insere_Pilha(Aux, no->dados);
        no = no->prox;
    }
    while (*Aux != NULL){
        libera_Pilha(Aux);
    }
    imprime_Pilha(novapi);
    return novapi;
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

int consulta_topo_Pilha(Pilha* pi, struct aluno *al){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    *al = (*pi)->dados;
    return 1;
}

int insere_Pilha(Pilha* pi, struct aluno al){
    if(pi == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*pi);
    *pi = no;
    return 1;
}
int inserir2(Pilha* pi, struct aluno al){
    if(pi == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    Elem* no2;
    no2 = (Elem*) malloc(sizeof(Elem));
    no2 -> dados = al;
    no2 ->prox = (*pi);
    *pi = no2;
    no -> dados = al;
    no -> prox = *pi;
    *pi = no;
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
int remove2(Pilha* pi){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    Elem *no1 = *pi;
    Elem *no2 = no1->prox;
    *pi = no2->prox;
    free(no1);
    free(no2);
    return 1;
}
int popN(Pilha* pi, int n){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    Elem  *no= *pi;
    int num =0;
    while ((num <n && no != NULL)){
        *pi = no->prox;
        free(no);
        no = *pi;
        num++;
    }
    return 1;
}

void maior_menor_media(Pilha* pi){
    if(pi == NULL)
        return ;
    if((*pi) == NULL)
        return ;
    float cont =0;
    float soma =0;
    float maior = -INFINITY;
    float menor = INFINITY;
    float media = 0;
    Elem* no =*pi;

    while(no !=NULL){
        if (!isinf(no->dados.n1)) {
            if (no->dados.n1 > maior)
                maior = no->dados.n1;

            if(no->dados.n1 < menor)
                menor = no->dados.n1;

            soma+= no->dados.n1;
            cont++;
        }

        if (!isinf(no->dados.n2)) {
            if (no->dados.n2 > maior)
                maior = no->dados.n2;

            if(no->dados.n2 < menor)
                menor = no->dados.n2;

            soma+= no->dados.n2;
            cont++;
        }

        if (!isinf(no->dados.n3)) {
            if (no->dados.n3 > maior)
                maior = no->dados.n3;

            if(no->dados.n3 < menor)
                menor = no->dados.n3;

            soma+= no->dados.n3;
            cont++;
        }

        no = no->prox;
    }

    if (cont != 0)
        media = soma/cont;

    printf("\nA maior nota  é: %.2f ", maior);
    printf("\nA menor nota  é: %.2f ", menor);
    printf("\nA media  é: %.2f ", media);
}
void par_impar(Pilha* pi) {
    if(pi == NULL)
        return ;
    if((*pi) == NULL)
        return ;
    Elem* no = *pi;
    int imparQuant = 0;

    while (no != NULL) {

        for(int i = 0; i < 3; i++) {
            int num = (i == 0) ? no->dados.n1 : (i == 1) ? no->dados.n2 : no->dados.n3;

            if(num % 2 == 0) {
                printf("\nPar: %d ", num);
            } else {
                printf("\nImpar: %d ", num);
                imparQuant++;
            }
        }
        no = no->prox;
    }

    if (imparQuant == 0) {
        printf("\nNão há números ímpares na pilha.\n");
    } else {
        printf("\nA quantidade de números ímpares é: %d.\n", imparQuant);
    }
}

char* decimalBinario(int n) {
    char* binario = (char*)malloc(33 * sizeof(char)); // vetor dinâmico para armazenar os dígitos binários
    int i = 0;

    do {
        binario[i++] = (n % 2) + '0'; // converte o dígito binário em um caractere '0' ou '1'
        n /= 2;
    } while (n > 0 && i < 32); // verifica se ainda há bits para converter e se não ultrapassou o limite de 32 bits

    binario[i] = '\0'; // termina a string com o caractere nulo

    // inverte a ordem dos dígitos binários
    int len = strlen(binario);
    for (int j = 0; j < len/2; j++) {
        char tmp = binario[j];
        binario[j] = binario[len-j-1];
        binario[len-j-1] = tmp;
    }
    printf(": %s",binario);
    return binario;
}
void menu(){
    printf("1-Inicializa pilha.\n");
    printf("2-Verifica se a pilha e vazia.\n");
    printf("3-Verifica se a pilha e cheia.\n");
    printf("4-Empilha o elemento na pilha.\n");
    printf("5-Desempilha elemento da pilha.\n");
    printf("6-Le topo de um pilha.\n");
    printf("7-Converte um numero decimal em binario.\n");
    printf("8-Sair.\n");
}

void calculadora( ){
    char operador[10];
    float resultado;
    int num =0, num2;

    cal = (int *) malloc(MAX * sizeof(int));
    if(cal == NULL)
        return ;

    if((*cal) == NULL)
        return ;

    tos = (int) cal;
    bos =cal+MAX-1;
    printf("Calculadora digite dois numero e dois operação(+, -, *, /\n)");
    do {
        printf(": ");
        gets(&operador);
        switch (*operador) {
            case '+':
               num = pop();
               num2 = pop();
               printf("\no resulado é: %d\n", num +num2);
               push(num+num2);
                break;
            case '-':
                num = pop();
                num2 = pop();
                printf("\no resulado é: %d\n", num -num2);
                push(num-num2);
                break;
            case '*':
                num = pop();
                num2 = pop();
                printf("\no resulado é: %d\n", num *num2);
                push(num*num2);
                break;
            case '/':
                num = pop();
                num2 = pop();
                if(num==0){
                    printf("Divisao por 0\n");
                    break;
                }
                printf("\no resulado é: %d\n", num /num2);
                push(num/num2);
                break;
            case '.': /*Mostra conteudo do topo da Pilha*/
                num = pop();
                push(num);
                printf("Valor corrente no topo da pilha: %d\n", num);
                break;
            default:
                push(atoi (operador));

        }

    } while (operador != 'f');
}
void push (int i){
    if (cal>bos) {
        printf("Pilha Cheia\n");
        return;
    }
    *cal = i;
    cal++;
}
int pop (void){
    cal--;
    if (cal<tos) {
        printf("Pilha Vazia\n");
        return 0;
    }
    return *cal;
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

int Pilha_cheia(Pilha* pi){
    printf("Pilha cheia");
    return 0;
}

int Pilha_vazia(Pilha* pi){
    if(pi == NULL) {
        printf("Pilha Vazia");
        return 1;
    }
    if(*pi == NULL)
        return 1;
    printf("Pilha cheia");
    return 0;
}

void imprime_Pilha(Pilha* pi){
    if(pi == NULL)
        return;
    Elem* no = *pi;
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
