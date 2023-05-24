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
/*1) Utilizando o código de listas que está disponível junto com a aula no
arquivo “ProjListaDinEncad”, faça o que se pede:
a. Crie uma nova função que consulta a lista e retorna um aluno
pela sua matricula
b. Crie uma nova função que consulta a lista e retorna um aluno
pela sua posição na lista*/
/*a*/void imprimiMatricula(Lista* li, int num);
/*A função imprimiMatricula recebe como parâmetros um ponteiro para a lista (li) e um número de matrícula (num) que se deseja encontrar na lista.
O objetivo da função é percorrer a lista buscando um elemento que tenha a matrícula igual ao número informado como parâmetro (num).
 Para isso, a função utiliza um ponteiro no que começa apontando para o primeiro elemento da lista (*li) e percorre a lista através do comando no = no->prox;, ou seja, a cada iteração,
 o ponteiro no passa a apontar para o próximo elemento da lista. O laço de repetição é interrompido quando o ponteiro no
 chega ao final da lista (ponteiro nulo) ou quando encontra um elemento cuja matrícula é igual a num.
Se a matrícula é encontrada, as informações do aluno são impressas na tela através dos comandos printf. Caso contrário,
 a mensagem "Aluno com matrícula X não encontrado." é impressa na tela, em que "X" é o número de matrícula informado como parâmetro (num).
Em resumo, a função imprimiMatricula busca e imprime as informações de um aluno com base na matrícula informada como parâmetro.
 Se o aluno não for encontrado na lista, uma mensagem de erro é exibida.*/
/*b*/void imprimePosicao(Lista* li, int num);
/*A função imprimePosicao recebe uma lista encadeada li e um inteiro num, que representa a posição do elemento a ser impresso na lista.
O primeiro passo da função é verificar se a lista é válida, ou seja, se li não é nulo e se o primeiro elemento da lista também não é nulo.
 Se a lista for inválida, a função simplesmente retorna.
Caso a lista seja válida, a função inicializa uma variável posicao com o valor 1 e um ponteiro no que aponta para o primeiro elemento da lista.
Em seguida, a função percorre a lista enquanto no não for nulo e enquanto posicao for diferente de num. Durante a iteração,
 a função avança o ponteiro no para o próximo elemento da lista e incrementa a variável posicao.
Se a função percorreu toda a lista e não encontrou o elemento na posição num, a função imprime uma mensagem informando que o elemento não foi encontrado.
Caso contrário, a função imprime as informações do elemento encontrado na posição num, incluindo matrícula, nome e notas. Por fim,
 a função imprime uma linha horizontal separando as informações do próximo elemento, caso exista.*/

/*2) Faça duas funções recursivas. A primeira deve remover um nó da lista
encadeada a partir do seu valor armazenado (ex: int info). A segunda
deve receber duas listas encadeadas e verificar se elas são iguais*/
/*1*/ int removeNo(Lista* li, int num );
/*Essa função implementa a remoção de um elemento de uma lista encadeada de forma recursiva. Ela recebe como parâmetros a lista encadeada
(ponteiro para o primeiro elemento) e o valor que deve ser removido da lista (representado pela variável "num").
A função verifica se a lista está vazia ou se chegou ao final da lista, caso positivo retorna 0 (indica que a operação de remoção falhou).
 Em seguida, ela verifica se o elemento atual é o que deve ser removido, se sim, remove o elemento e retorna 1 (indica que a operação de remoção foi bem sucedida).
Se o elemento atual não é o que deve ser removido, a função é chamada recursivamente passando o próximo elemento da lista como parâmetro.
 Esse processo se repete até que o elemento seja encontrado e removido ou até chegar ao final da lista e retornar 0.*/
/*2*/
int verificarIgual(Lista* li, Lista* li2);
/*A função verificarIgual recebe duas listas encadeadas, li1 e li2, como argumentos e compara se elas são iguais ou diferentes.
A primeira verificação feita na função é para ver se ambas as listas estão vazias. Se estiverem vazias, a função imprime
 "As listas são iguais" e retorna 1, indicando que as listas são iguais.
Se apenas uma das listas estiver vazia, a função imprime "As listas são diferentes" e retorna 0, indicando que as listas
 são diferentes.
Se ambas as listas não estiverem vazias, a função compara os dados do primeiro nó (Elemento) de cada lista (matrícula,
 nome e notas). Se os dados dos nós forem iguais, a função chama a si mesma recursivamente, passando como argumentos os endereços dos próximos nós em ambas as listas.
Se os dados dos nós forem diferentes, a função imprime "As listas são diferentes" e retorna 0, indicando que as listas
 são diferentes.
Ao final da função, se todas as comparações forem iguais, a função retorna 1, indicando que as listas são iguais*/

/*3) Crie uma função que insere um valor em uma posição qualquer da lista
encadeada.*/
int inserirIndex(Lista* li, int index,  struct aluno al);
/*A função inserirIndex tem como objetivo inserir um novo elemento em uma lista encadeada em uma posição específica
 * indicada pelo parâmetro index.
A função inicia testando se o ponteiro para a lista encadeada li é nulo, o que significa que a lista não foi alocada
 ou está vazia. Em caso positivo, a função retorna 0, indicando que a operação de inserção não foi bem-sucedida.
Em seguida, a função aloca memória para um novo elemento no, que irá armazenar os dados da estrutura aluno. Caso a alocação
 de memória falhe, a função também retorna 0.
A função então testa se a lista encadeada está vazia ou se a inserção deve ser realizada na primeira posição, indicada pelo
 valor 1 do parâmetro index. Caso positivo, o novo elemento no é inserido no início da lista encadeada, apontando para o
 primeiro elemento atual da lista, indicado por *li. O ponteiro li é atualizado para apontar para o novo primeiro elemento,
 e a função retorna 1, indicando que a operação de inserção foi bem-sucedida.
Caso contrário, a função percorre a lista encadeada até a posição anterior à posição de inserção, indicada por index-1,
 apontando o ponteiro aux para cada elemento da lista, até chegar na posição desejada. Em seguida, o novo elemento no é
 inserido na lista, apontando seu ponteiro prox para o próximo elemento após a posição de inserção, e o ponteiro prox do
 elemento anterior é atualizado para apontar para o novo elemento no. A função retorna 1, indicando que a operação de inserção foi bem-sucedida.*/

/*4) Recebendo como parâmetro um vetor de float, por exemplo v[n] = “5.5,
8, 9.1, 25”, crie uma função que construa lista encadeada com esses
valores, seguindo a mesma ordem em que os números estão no vetor
recebido*/
//Lista05exe04

//5) Receba um número inteiro não negativo e faça uma função que percorra
//a lista e remova todos os nós que contiverem esse número inteiro
//armazenado neles. Faça todas as condições de controle necessárias
//para as remoções sejam corretas.
//Lista05exe05

/*6) Escrever uma função para concatenar duas listas encadeadas L1 e L2. */

void concatenar(Lista * li, Lista *li2);
/*
 * Esta função implementa a operação de concatenar duas listas encadeadas, representadas pelos ponteiros li e li2.
O primeiro if verifica se algum dos ponteiros passados é NULL. Caso um deles seja NULL, a função simplesmente retorna sem
 fazer nada, pois não há listas para concatenar.
O segundo if verifica se a lista li é vazia. Se ela for vazia, a função atribui o ponteiro li2 a li e retorna. Ou seja,
 a lista li passa a ser igual à lista li2.
Se a lista li não for vazia, a função percorre li até encontrar seu último elemento (ou seja, um elemento cujo ponteiro
 prox é NULL). Depois disso, ela atribui o ponteiro li2 ao ponteiro prox do último elemento de li, concatenando as duas
 listas.
*/

/*7) Escrever uma função para remover elementos repetidos de uma lista
encadeada*/
int removeRepete(Lista *li);
/*
A função removeRepete é responsável por percorrer uma lista encadeada e remover elementos repetidos com base no campo
 matricula de cada elemento. Ela recebe como parâmetro um ponteiro para o início da lista li.
Primeiro, a função verifica se a lista é vazia ou se o ponteiro passado é nulo. Em ambos os casos, ela retorna 0 indicando
 que a operação não foi bem-sucedida.
Se a lista não é vazia e o ponteiro não é nulo, a função define dois ponteiros: atual e aux. O ponteiro atual percorre a
 lista elemento por elemento, enquanto o ponteiro aux é usado para comparar cada elemento com os demais.
Em um loop externo, a função percorre a lista, avançando o ponteiro atual. Dentro deste loop, há um loop interno que
 avança o ponteiro aux até encontrar um elemento com o mesmo valor de matricula do elemento apontado por atual, ou até
 chegar ao final da lista.
Se o elemento é encontrado, a função remove esse elemento da lista e libera a memória alocada para ele. Caso contrário,
 avança o ponteiro atual para o próximo elemento e o loop continua.
Por fim, a função retorna 1 indicando que a operação foi bem-sucedida.*/

/*8) Escrever um procedimento para fazer a fusão de duas listas encadeadas
ordenadas, mantendo-a ordenada. Não devem ser alocados (criados)
nós extras. Os nós serão religados para compor a nova lista ordenada*/
void fusaoListasOrdenadas(Lista *lista1, Lista *lista2);
/*O procedimento fusaoListasOrdenadas recebe dois ponteiros para lista encadeada lista1 e lista2. Caso uma das listas esteja vazia, o procedimento retorna sem fazer nada.

Em seguida, são criados três ponteiros: atual1, atual2 e aux. O ponteiro atual1 é inicializado como o primeiro elemento
 da lista1, o ponteiro atual2 é inicializado como o primeiro elemento da lista2 e o ponteiro aux é inicializado como NULL.
Em um loop while, o procedimento compara os elementos apontados pelos ponteiros atual1 e atual2 e escolhe o menor entre
 eles, atribuindo-o ao ponteiro aux. Em seguida, o ponteiro aux é inserido na lista resultante. Isso é feito alterando os ponteiros prox dos elementos adjacentes da lista encadeada. Por fim, o ponteiro aux é atualizado para o próximo elemento da lista em que se encontrava anteriormente.
O loop while continua até que pelo menos um dos ponteiros atual1 e atual2 tenha percorrido toda a lista correspondente.
 Quando isso acontece, os elementos restantes são adicionados ao final da lista resultante.
Ao final do procedimento, a lista encadeada apontada pelo ponteiro lista1 contém todos os elementos das duas listas originais,
 ordenados.*/

/*9)Considere a implementação de listas encadeadas. Escreva um
procedimento Troca(TipoLista* pLista, TipoCelula* p) que, dado um
apontador para uma célula qualquer (p), troca de posição essa célula
com a sua célula seguinte da lista, como mostrado na figura abaixo.
(Obs. Não vale trocar apenas o campo item! Você deverá fazer a
manipulação dos apontadores para trocar as duas células de posição).
Não esqueça de tratar os casos especiais.*/

void Troca(Lista *li);

/*O código acima é uma implementação possível do procedimento Troca que recebe um apontador para uma célula (li) e troca de posição essa célula com a sua célula seguinte na lista encadeada.

O procedimento inicia verificando se a célula não é nula e se possui uma célula seguinte. Se sim, o apontador aux é usado para armazenar o endereço da célula seguinte. Em seguida, o apontador da célula atual é atualizado para apontar para a célula seguinte da próxima célula, e o apontador da célula seguinte é atualizado para apontar para a célula atual.

Depois, são realizadas verificações adicionais para atualizar os apontadores da célula anterior e posterior à célula atual, bem como o apontador da célula seguinte à célula seguinte.

É importante mencionar que esse código funciona apenas para listas duplamente encadeadas, que possuem apontadores tanto para a célula anterior quanto para a próxima célula. Para listas simplesmente encadeadas, o código precisaria ser modificado.*/




