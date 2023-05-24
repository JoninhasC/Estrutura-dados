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
/*Considerando filas, implemente um método que receba como parâmetro
a referência f1 e um valor de matrícula n e dívida a fila em duas, de tal
forma que a segunda fila comece no primeiro nó logo após a primeira
ocorrência de n na fila original. Esse método deve ser da seguinte
assinatura:
int separa(Fila f1, Fila f2, matricula n) */

int separa(Fila* f1, Fila* f2, int n);

/*
 * O método separa recebe como parâmetros as referências para duas filas (f1 e f2) e um valor de matrícula n.
 * Ele tem como objetivo separar a fila f1 em duas, de tal forma que a segunda fila (f2) comece no primeiro nó logo após
 * a primeira ocorrência de n na fila original.
O método começa verificando se as referências das filas passadas como parâmetros são válidas e se a fila f1 não está vazia.
Em seguida, é feita uma busca na fila f1 para encontrar o nó com a matrícula n. Se o nó não for encontrado, o método retorna 0.
Se o nó com a matrícula n for encontrado, a fila f1 é separada em duas. Se o nó estiver no início da fila,
o método atualiza o início da fila f1 para o nó seguinte ao nó encontrado. Caso contrário, o ponteiro do nó anterior é
atualizado para apontar para o nó seguinte ao nó encontrado.
Em ambos os casos, a quantidade de elementos da fila f1 é decrementada em 1.
Em seguida, o método atualiza o início, o final e a quantidade de elementos da fila f2 para que ela comece no nó encontrado
e contenha apenas esse nó.
O nó encontrado é removido da fila f1 e tem seu ponteiro para o próximo nó atualizado para NULL.
Por fim, os elementos que vêm depois do nó encontrado em f1 são movidos para a fila f2 através de um laço que percorre
os nós da fila f1 e insere seus dados na fila f2 através do método insere_Fila.
Cada nó inserido em f2 é removido de f1 através do método remove_Fila.
Ao final, o método retorna 1 indicando que a operação foi realizada com sucesso.
 */

/*2) Implemente as seguintes combinações de estruturas de dados com fila:
a. Uma fila de filas;
b. Uma fila de pilhas;
c. Uma pilha de filas;
 feito*/


/*Considere uma pilha P vazia e uma fila F não vazia. Utilizando apenas
os testes de fila e pilha vazias, as operações Enfileira, Desenfileira,
Empilha, Desempilha, e uma variável aux inteira, escreva um programa
que inverte a ordem dos elementos da fila.*/
void inverte_Fila(Fila* fi);
/*A função inverte_Fila recebe um ponteiro para a fila que será invertida. Ela cria uma pilha vazia usando a função cria_Pilha e uma variável al do tipo struct aluno.

Em seguida, enquanto a fila não estiver vazia, a função consulta o elemento da fila usando a função consulta_Fila, desenfileira o elemento usando a função remove_Fila e empilha o elemento na pilha usando a função insere_Pilha.

Depois que todos os elementos da fila foram empilhados na pilha, a função começa a desempilhar os elementos da pilha e enfileirar na fila. Isso é feito até que a pilha fique vazia.

Por fim, a função libera a pilha usando a função libera_Pilha.

Note que, para implementar essa função, é necessário ter uma implementação de pilha disponível. Caso contrário, pode-se implementar uma pilha usando uma lista encadeada, por exemplo, e usar a implementação dessa pilha na função inverte_Fila.*/
/*Considere a implementação de filas usando a característica de filas
“circulares”, pesquise sobre o assunto. Escreva uma função
FuraFila(Fila* f, float x) que insere um item na primeira posição da fila. O
detalhe é que seu procedimento deve ser O(1), ou seja, não pode
movimentar os outros itens da fila. (observe que este neste caso,
estaremos desrespeitando o conceito de FILA – primeiro a entrar é o
primeiro a sair). Altere também a função de percorrer a Fila para que ela
se aproveite da característica da fila circular.*/
void FuraFila(Fila* f, float x);
/*
A função FuraFila recebe um ponteiro para uma fila e um elemento x a ser inserido na primeira posição da fila.
 * Primeiro, a função verifica se a fila é nula, caso seja, ela retorna. Em seguida, é criado um novo elemento para ser inserido na fila.
 * Se a fila estiver vazia, o novo elemento é adicionado à fila e torna-se o único elemento da fila. O ponteiro inicio e final apontam para esse novo elemento.
 * Caso contrário, o novo elemento é adicionado na posição anterior ao inicio da fila.
 * O ponteiro prox do novo elemento é atualizado para apontar para o elemento que era o primeiro da fila. Em seguida, o ponteiro inicio é atualizado para apontar para o novo elemento.
 * Por fim, o ponteiro prox do último elemento da fila é atualizado para apontar para o novo elemento, tornando a fila circular.
 * /

/*Escreva um programa que simule o controle de uma pista de decolagem
de aviões em um aeroporto. Neste programa, o usuário deve ser capaz
de realizar as seguintes tarefas:
a) Listar o número de aviões aguardando na fila de decolagem;
b) Autorizar a decolagem do primeiro avião da fila;
c) Adicionar um avião à fila de espera;
d) Listar todos os aviões na fila de espera;
e) Listar as características do primeiro avião da fila.
 */

/*Implemente um método que receba três filas, duas já preenchidas em
ordem crescente e preencha a última com os valores das duas primeiras
em ordem crescente.
 */
void preenche_fila_crescente(Fila* f1, Fila* f2, Fila* f3);
/*
 *A função preenche_fila_crescente utiliza as funções Fila_vazia, consulta_Fila, insere_Fila e remove_Fila para realizar a
 * operação de mesclar duas filas em ordem crescente e preencher uma terceira fila.
Inicialmente, as variáveis flag1 e flag2 são definidas como 1 para indicar que as filas f1 e f2 ainda possuem elementos.
Um laço while é utilizado para percorrer as filas f1 e f2 até que uma das filas seja completamente percorrida.
Dentro do laço while, a função consulta_Fila é utilizada para obter o primeiro elemento de cada fila. Em seguida, é verificado
 qual elemento possui a menor matrícula, utilizando um comando if.
O elemento de menor valor é então inserido na fila 3 utilizando a função insere_Fila e removido da respectiva fila utilizando a função remove_Fila.
Quando uma das filas for completamente percorrida, o laço while é interrompido e os elementos restantes da outra fila são adicionados
 na fila 3 utilizando um par de laços while semelhantes aos anteriores.
Ao final da função, a fila 3 estará preenchida com os elementos das filas 1 e 2 em ordem crescente.
 */

/*
implemente a função reverso, que reposiciona os elementos na fila de
tal forma que o início da fila torna-se o fim, e vice-versa.
*/
void reverso(Fila *fi);
/*
 * O código acima é uma implementação da função "reverso" que inverte a ordem dos elementos em uma fila.
 * O algoritmo é baseado na criação de uma nova fila, na qual os elementos são inseridos na ordem inversa à original. Em seguida, a fila original é atualizada com a nova fila invertida.
O código começa verificando se a fila passada como parâmetro é nula ou vazia. Se for, a função simplesmente retorna.
 Caso contrário, uma nova fila é criada usando a função "cria_Fila".
Em seguida, um loop é iniciado, que percorre a fila original enquanto ela não estiver vazia.
 A cada iteração, o elemento no início da fila original é obtido usando a função "consulta_Fila" e inserido no início da nova fila usando a função "insere_Fila".
 Em seguida, o elemento é removido da fila original usando a função "remove_Fila".
Após o término do loop, a fila original é atualizada com a nova fila invertida.
 As informações relevantes da nova fila, como o início, o final e o número de elementos, são copiadas para a fila original.
 A memória alocada para a nova fila é liberada usando a função "free".
Em resumo, a função "reverso" recebe uma fila como entrada, inverte a ordem dos elementos e atualiza a fila original com a ordem invertida.
 O algoritmo é baseado na criação de uma nova fila, na qual os elementos são inseridos na ordem inversa à original.
 */
/*
 Faça um programa que apresente um menu contínuo com as seguintes
opções e execute de acordo com a escolha do usuário.
void menu()
{
 printf("1-Inicializa fila.\n");
 printf("2-Verifica se a fila é vazia.\n");
 printf("3-Verifica se a fila é cheia.\n");
 printf("4-Enfileira o elemento na fila.\n");
 printf("5-Desefileira elemento da fila.\n");
 printf("6-Le o número no início da fila.\n");
 printf("7-Testar qual fila possui mais elementos .\n");
 printf("8-Furar a fila .\n");
 printf("9-Sair.\n");
}
 */
void imprime_Primeiro(Fila* fi);
/*
 * Esta função recebe uma Fila como parâmetro e imprime as informações do primeiro elemento da fila, se ela existir.
 * A impressão inclui a matrícula, o nome e as notas do aluno.
Para isso, a função começa verificando se a fila passada como parâmetro é válida. Se não for, a função simplesmente retorna.
 Caso contrário, ela acessa o primeiro elemento da fila através do ponteiro "inicio" e imprime as informações do aluno armazenadas na estrutura "dados".
 */
void testar_tamanho_filas(Fila* f1, Fila* f2);
/*
 * Esta função recebe duas filas como parâmetros e verifica qual delas possui mais elementos.
 * Se alguma das filas for inválida (NULL), a função imprime uma mensagem de erro. Caso contrário, compara o tamanho da fila 1 com o tamanho da fila 2 e
 * imprime uma mensagem indicando qual fila possui mais elementos ou se ambas possuem a mesma quantidade.
Por exemplo, se a fila 1 tiver 5 elementos e a fila 2 tiver 3, a função imprimirá "A fila 1 possui mais elementos."
 */
void furar_fila(Fila* f, int matricula, float divida);
/*
 * A função "furar_fila" recebe como parâmetros a fila, a matrícula e o valor da dívida de um aluno.
 *A função primeiro verifica se a fila é válida e, em seguida, cria um aluno com os dados informados.
 * O aluno é adicionado no início da fila usando a função "insere_Fila".
 * Por fim, a função imprime uma mensagem informando que o aluno foi adicionado no início da fila.
 */