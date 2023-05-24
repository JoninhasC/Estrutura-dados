//Arquivo ListaDinEncad.h

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_inicio(Lista* li, struct aluno al);
int insere_lista_ordenada(Lista* li, struct aluno al);
int remove_lista(Lista* li, int mat);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int lista_cheia(Lista* li);
void imprime_lista(Lista* li);
//01
void remove_lista_matricula(Lista* li, int mat);
/*
Essa função recebe como parâmetros um ponteiro para ponteiro para o início da lista e uma matrícula de um aluno a ser removido.
 Ela começa verificando se a lista é nula ou vazia, retornando imediatamente caso seja esse o caso. Em seguida, ela cria dois
 ponteiros para elementos da lista, um para o elemento atual e outro para o elemento anterior. O ponteiro atual começa apontando
 para o início da lista. Em um laço de repetição, a função percorre a lista procurando um elemento cuja matrícula seja igual à passada
 como parâmetro. Durante a iteração, o ponteiro anterior é atualizado para apontar para o elemento atual antes de ele ser atualizado
 para apontar para o próximo elemento da lista. Se o elemento atual for nulo, isso significa que o aluno não foi encontrado na lista e
 a função retorna. Caso contrário, a função atualiza os ponteiros para remover a célula que contém o aluno. Se o aluno estiver na primeira
 posição da lista, o ponteiro para o início da lista é atualizado para apontar para o próximo elemento. Se o aluno não estiver na última
 posição da lista, o ponteiro do próximo elemento do elemento atual é atualizado para apontar para o elemento anterior. Em seguida, a célula é
 liberada da memória usando a função free().*/

//02
 void insere_lista_ordenada_chave(Lista* li, struct aluno al);
 /* função primeiro aloca memória para um novo elemento novo e atribui os dados do parâmetro al para o campo dados do novo
  * elemento. Em seguida, a função verifica se a lista é nula ou vazia. Se a lista for nula, a função imprime uma mensagem
  * de erro e libera a memória alocada para o novo elemento. Se a lista estiver vazia, a função insere o novo elemento no início da lista.
Caso a lista não esteja vazia, a função busca a posição correta de inserção percorrendo a lista enquanto a chave matricula
  do elemento atual for menor do que a chave do novo elemento al.matricula. A função utiliza os ponteiros atual e ant para percorrer a lista.
Ao encontrar a posição de inserção, a função verifica se o novo elemento deve ser inserido no início, no meio ou no final
  da lista. Se o novo elemento deve ser inserido no início, a função atualiza o ponteiro do início da lista e ajusta os
  ponteiros de encadeamento. Se o novo elemento deve ser inserido no final da lista, a função atualiza o ponteiro do
  último elemento e ajusta os ponteiros de encadeamento. Se o novo elemento deve ser inserido no meio da lista, a função
  ajusta os ponteiros de encadeamento do novo elemento, do elemento anterior e do elemento seguinte.
Ao final da função, o novo elemento já foi inserido na lista de forma ordenada pela chave matricula.
*/
 //03
 int conta_lista_nota(Lista* li, int n1);
 /*A função conta_lista_nota recebe como parâmetros um ponteiro para a lista encadeada li e um inteiro n1, que representa
  * a nota a ser contada na lista.
Inicialmente, a função verifica se a lista é vazia ou nula, retornando 0 em caso positivo e imprimindo uma mensagem
  informando que a lista está vazia.
Em seguida, a função declara uma variável cont para contar a quantidade de alunos com a nota n1 e inicializa um ponteiro
  atual com o valor apontado pelo ponteiro li. Esse ponteiro atual será utilizado para percorrer a lista encadeada.
Dentro do loop while, a função avança o ponteiro atual para o próximo elemento da lista, verificando se a nota do aluno
  atual é igual a n1. Caso positivo, incrementa a variável cont.

Ao final do loop, a função atualiza o ponteiro li para apontar para o último elemento da lista, que é uma célula cabeça.
  Isso é feito para que a lista possa ser percorrida novamente a partir da primeira célula cabeça.
Por fim, a função retorna a quantidade de alunos com a nota n1 encontrados na lista.*/

 //04
