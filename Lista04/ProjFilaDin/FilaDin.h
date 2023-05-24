//Arquivo FilaDin.h
struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct fila Fila;

Fila* cria_Fila();
void libera_Fila(Fila* fi);
int consulta_Fila(Fila* fi, struct aluno *al);
int insere_Fila(Fila* fi, struct aluno al);
int remove_Fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int Fila_cheia(Fila* fi);
void imprime_Fila(Fila* fi);
/*Considerando filas, implemente um m�todo que receba como par�metro
a refer�ncia f1 e um valor de matr�cula n e d�vida a fila em duas, de tal
forma que a segunda fila comece no primeiro n� logo ap�s a primeira
ocorr�ncia de n na fila original. Esse m�todo deve ser da seguinte
assinatura:
int separa(Fila f1, Fila f2, matricula n) */

int separa(Fila* f1, Fila* f2, int n);

/*
 * O m�todo separa recebe como par�metros as refer�ncias para duas filas (f1 e f2) e um valor de matr�cula n.
 * Ele tem como objetivo separar a fila f1 em duas, de tal forma que a segunda fila (f2) comece no primeiro n� logo ap�s
 * a primeira ocorr�ncia de n na fila original.
O m�todo come�a verificando se as refer�ncias das filas passadas como par�metros s�o v�lidas e se a fila f1 n�o est� vazia.
Em seguida, � feita uma busca na fila f1 para encontrar o n� com a matr�cula n. Se o n� n�o for encontrado, o m�todo retorna 0.
Se o n� com a matr�cula n for encontrado, a fila f1 � separada em duas. Se o n� estiver no in�cio da fila,
o m�todo atualiza o in�cio da fila f1 para o n� seguinte ao n� encontrado. Caso contr�rio, o ponteiro do n� anterior �
atualizado para apontar para o n� seguinte ao n� encontrado.
Em ambos os casos, a quantidade de elementos da fila f1 � decrementada em 1.
Em seguida, o m�todo atualiza o in�cio, o final e a quantidade de elementos da fila f2 para que ela comece no n� encontrado
e contenha apenas esse n�.
O n� encontrado � removido da fila f1 e tem seu ponteiro para o pr�ximo n� atualizado para NULL.
Por fim, os elementos que v�m depois do n� encontrado em f1 s�o movidos para a fila f2 atrav�s de um la�o que percorre
os n�s da fila f1 e insere seus dados na fila f2 atrav�s do m�todo insere_Fila.
Cada n� inserido em f2 � removido de f1 atrav�s do m�todo remove_Fila.
Ao final, o m�todo retorna 1 indicando que a opera��o foi realizada com sucesso.
 */

/*2) Implemente as seguintes combina��es de estruturas de dados com fila:
a. Uma fila de filas;
b. Uma fila de pilhas;
c. Uma pilha de filas;
 feito*/


/*Considere uma pilha P vazia e uma fila F n�o vazia. Utilizando apenas
os testes de fila e pilha vazias, as opera��es Enfileira, Desenfileira,
Empilha, Desempilha, e uma vari�vel aux inteira, escreva um programa
que inverte a ordem dos elementos da fila.*/
void inverte_Fila(Fila* fi);
/*A fun��o inverte_Fila recebe um ponteiro para a fila que ser� invertida. Ela cria uma pilha vazia usando a fun��o cria_Pilha e uma vari�vel al do tipo struct aluno.

Em seguida, enquanto a fila n�o estiver vazia, a fun��o consulta o elemento da fila usando a fun��o consulta_Fila, desenfileira o elemento usando a fun��o remove_Fila e empilha o elemento na pilha usando a fun��o insere_Pilha.

Depois que todos os elementos da fila foram empilhados na pilha, a fun��o come�a a desempilhar os elementos da pilha e enfileirar na fila. Isso � feito at� que a pilha fique vazia.

Por fim, a fun��o libera a pilha usando a fun��o libera_Pilha.

Note que, para implementar essa fun��o, � necess�rio ter uma implementa��o de pilha dispon�vel. Caso contr�rio, pode-se implementar uma pilha usando uma lista encadeada, por exemplo, e usar a implementa��o dessa pilha na fun��o inverte_Fila.*/
/*Considere a implementa��o de filas usando a caracter�stica de filas
�circulares�, pesquise sobre o assunto. Escreva uma fun��o
FuraFila(Fila* f, float x) que insere um item na primeira posi��o da fila. O
detalhe � que seu procedimento deve ser O(1), ou seja, n�o pode
movimentar os outros itens da fila. (observe que este neste caso,
estaremos desrespeitando o conceito de FILA � primeiro a entrar � o
primeiro a sair). Altere tamb�m a fun��o de percorrer a Fila para que ela
se aproveite da caracter�stica da fila circular.*/
void FuraFila(Fila* f, float x);
/*
A fun��o FuraFila recebe um ponteiro para uma fila e um elemento x a ser inserido na primeira posi��o da fila.
 * Primeiro, a fun��o verifica se a fila � nula, caso seja, ela retorna. Em seguida, � criado um novo elemento para ser inserido na fila.
 * Se a fila estiver vazia, o novo elemento � adicionado � fila e torna-se o �nico elemento da fila. O ponteiro inicio e final apontam para esse novo elemento.
 * Caso contr�rio, o novo elemento � adicionado na posi��o anterior ao inicio da fila.
 * O ponteiro prox do novo elemento � atualizado para apontar para o elemento que era o primeiro da fila. Em seguida, o ponteiro inicio � atualizado para apontar para o novo elemento.
 * Por fim, o ponteiro prox do �ltimo elemento da fila � atualizado para apontar para o novo elemento, tornando a fila circular.
 * /

/*Escreva um programa que simule o controle de uma pista de decolagem
de avi�es em um aeroporto. Neste programa, o usu�rio deve ser capaz
de realizar as seguintes tarefas:
a) Listar o n�mero de avi�es aguardando na fila de decolagem;
b) Autorizar a decolagem do primeiro avi�o da fila;
c) Adicionar um avi�o � fila de espera;
d) Listar todos os avi�es na fila de espera;
e) Listar as caracter�sticas do primeiro avi�o da fila.
 */

/*Implemente um m�todo que receba tr�s filas, duas j� preenchidas em
ordem crescente e preencha a �ltima com os valores das duas primeiras
em ordem crescente.
 */
void preenche_fila_crescente(Fila* f1, Fila* f2, Fila* f3);
/*
 *A fun��o preenche_fila_crescente utiliza as fun��es Fila_vazia, consulta_Fila, insere_Fila e remove_Fila para realizar a
 * opera��o de mesclar duas filas em ordem crescente e preencher uma terceira fila.
Inicialmente, as vari�veis flag1 e flag2 s�o definidas como 1 para indicar que as filas f1 e f2 ainda possuem elementos.
Um la�o while � utilizado para percorrer as filas f1 e f2 at� que uma das filas seja completamente percorrida.
Dentro do la�o while, a fun��o consulta_Fila � utilizada para obter o primeiro elemento de cada fila. Em seguida, � verificado
 qual elemento possui a menor matr�cula, utilizando um comando if.
O elemento de menor valor � ent�o inserido na fila 3 utilizando a fun��o insere_Fila e removido da respectiva fila utilizando a fun��o remove_Fila.
Quando uma das filas for completamente percorrida, o la�o while � interrompido e os elementos restantes da outra fila s�o adicionados
 na fila 3 utilizando um par de la�os while semelhantes aos anteriores.
Ao final da fun��o, a fila 3 estar� preenchida com os elementos das filas 1 e 2 em ordem crescente.
 */

/*
implemente a fun��o reverso, que reposiciona os elementos na fila de
tal forma que o in�cio da fila torna-se o fim, e vice-versa.
*/
void reverso(Fila *fi);
/*
 * O c�digo acima � uma implementa��o da fun��o "reverso" que inverte a ordem dos elementos em uma fila.
 * O algoritmo � baseado na cria��o de uma nova fila, na qual os elementos s�o inseridos na ordem inversa � original. Em seguida, a fila original � atualizada com a nova fila invertida.
O c�digo come�a verificando se a fila passada como par�metro � nula ou vazia. Se for, a fun��o simplesmente retorna.
 Caso contr�rio, uma nova fila � criada usando a fun��o "cria_Fila".
Em seguida, um loop � iniciado, que percorre a fila original enquanto ela n�o estiver vazia.
 A cada itera��o, o elemento no in�cio da fila original � obtido usando a fun��o "consulta_Fila" e inserido no in�cio da nova fila usando a fun��o "insere_Fila".
 Em seguida, o elemento � removido da fila original usando a fun��o "remove_Fila".
Ap�s o t�rmino do loop, a fila original � atualizada com a nova fila invertida.
 As informa��es relevantes da nova fila, como o in�cio, o final e o n�mero de elementos, s�o copiadas para a fila original.
 A mem�ria alocada para a nova fila � liberada usando a fun��o "free".
Em resumo, a fun��o "reverso" recebe uma fila como entrada, inverte a ordem dos elementos e atualiza a fila original com a ordem invertida.
 O algoritmo � baseado na cria��o de uma nova fila, na qual os elementos s�o inseridos na ordem inversa � original.
 */
/*
 Fa�a um programa que apresente um menu cont�nuo com as seguintes
op��es e execute de acordo com a escolha do usu�rio.
void menu()
{
 printf("1-Inicializa fila.\n");
 printf("2-Verifica se a fila � vazia.\n");
 printf("3-Verifica se a fila � cheia.\n");
 printf("4-Enfileira o elemento na fila.\n");
 printf("5-Desefileira elemento da fila.\n");
 printf("6-Le o n�mero no in�cio da fila.\n");
 printf("7-Testar qual fila possui mais elementos .\n");
 printf("8-Furar a fila .\n");
 printf("9-Sair.\n");
}
 */
void imprime_Primeiro(Fila* fi);
/*
 * Esta fun��o recebe uma Fila como par�metro e imprime as informa��es do primeiro elemento da fila, se ela existir.
 * A impress�o inclui a matr�cula, o nome e as notas do aluno.
Para isso, a fun��o come�a verificando se a fila passada como par�metro � v�lida. Se n�o for, a fun��o simplesmente retorna.
 Caso contr�rio, ela acessa o primeiro elemento da fila atrav�s do ponteiro "inicio" e imprime as informa��es do aluno armazenadas na estrutura "dados".
 */
void testar_tamanho_filas(Fila* f1, Fila* f2);
/*
 * Esta fun��o recebe duas filas como par�metros e verifica qual delas possui mais elementos.
 * Se alguma das filas for inv�lida (NULL), a fun��o imprime uma mensagem de erro. Caso contr�rio, compara o tamanho da fila 1 com o tamanho da fila 2 e
 * imprime uma mensagem indicando qual fila possui mais elementos ou se ambas possuem a mesma quantidade.
Por exemplo, se a fila 1 tiver 5 elementos e a fila 2 tiver 3, a fun��o imprimir� "A fila 1 possui mais elementos."
 */
void furar_fila(Fila* f, int matricula, float divida);
/*
 * A fun��o "furar_fila" recebe como par�metros a fila, a matr�cula e o valor da d�vida de um aluno.
 *A fun��o primeiro verifica se a fila � v�lida e, em seguida, cria um aluno com os dados informados.
 * O aluno � adicionado no in�cio da fila usando a fun��o "insere_Fila".
 * Por fim, a fun��o imprime uma mensagem informando que o aluno foi adicionado no in�cio da fila.
 */