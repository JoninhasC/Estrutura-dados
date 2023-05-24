//Arquivo PilhaDin.h

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct elemento* Pilha;

Pilha* cria_Pilha();
void libera_Pilha(Pilha* pi);
int consulta_topo_Pilha(Pilha* pi, struct aluno *al);
int insere_Pilha(Pilha* pi, struct aluno al);
int remove_Pilha(Pilha* pi);
int tamanho_Pilha(Pilha* pi);
int Pilha_vazia(Pilha* pi);
int Pilha_cheia(Pilha* pi);
void imprime_Pilha(Pilha* pi);

//1) Faça um programa que tenha uma nova função chamada pop2() para
//desempilhar dois elementos da pilha e uma outra função chamada
//push2() para empilhar 2 elementos a partir do topo da pilha. Não devem
//ser utilizadas as funções de push e pop já existentes.

int inserir2(Pilha* pi, struct aluno al);

/*A função inserir2 recebe como parâmetros um ponteiro para a estrutura Pilha e uma variável do tipo struct aluno.
* O objetivo dessa função é inserir um novo elemento no topo da pilha.
O código começa verificando se o ponteiro para a pilha é nulo, retornando 0 caso isso seja verdadeiro. Em seguida, dois
ponteiros para a estrutura Elem são criados utilizando a função malloc. O primeiro ponteiro (no) é criado para preservar
a ordem dos elementos já existentes na pilha, e o segundo ponteiro (no2) é criado para inserir o novo elemento no topo da pilha.
O próximo passo é atribuir os valores do elemento a ser inserido no topo da pilha ao ponteiro no2. Em seguida, o ponteiro no2
é ligado ao ponteiro que aponta para o antigo topo da pilha (*pi). Por fim, o ponteiro que aponta para o topo da pilha (*pi)
é atualizado para apontar para o ponteiro no2, que agora é o novo topo da pilha. O ponteiro no também é atualizado para receber
os mesmos valores do novo elemento a ser inserido. Porém, ele é ligado ao topo antigo da pilha antes de atualizar o ponteiro para o topo da
pilha. Essa operação permite manter a ordem dos elementos já existentes na pilha.
A função não retorna nenhum valor em caso de sucesso na inserção. Caso haja algum erro na alocação de memória, a função retorna 0.*/

int remove2(Pilha* pi);
/*Verifica se o ponteiro para a pilha é válido. Caso não seja, retorna 0 indicando que a remoção não foi possível.
Verifica se a pilha tem pelo menos dois elementos. Caso não tenha, retorna 0 indicando que a remoção não foi possível.
Cria dois ponteiros para elementos (no1 e no2), apontando para os dois elementos do topo da pilha.
Atualiza o ponteiro da pilha para apontar para o terceiro elemento da pilha (no2->prox).
Libera a memória alocada para os elementos no1 e no2.*/


//2) Faça um programa que tenha uma nova função chamada popN() para
//desempilhar n elementos a partir do topo da pilha. Não devem ser
//utilizadas as funções de push e pop já existentes.

int popN(Pilha* pi, int n);
/*Essa função recebe como parâmetros um ponteiro para a estrutura Pilha e um inteiro n. Ela tem como objetivo remover os n primeiros elementos da pilha.
O primeiro if verifica se o ponteiro para a estrutura Pilha é nulo, retornando 0 caso seja. O segundo if verifica se a pilha está vazia, retornando 0 caso esteja.
Dentro do loop while, a variável num é usada como contador para garantir que serão removidos exatamente n elementos. A cada iteração, o elemento no topo da pilha é
removido e liberado da memória, e o ponteiro para o topo da pilha é atualizado para o próximo elemento. Ao final, a função retorna 1, indicando que a remoção
foi bem-sucedida. Caso algum dos if seja verdadeiro, a função retorna 0, indicando que a remoção não foi realizada.*/

//3) Faça um programa que utilizando apenas as funções desenvolvidas
//para a pilha, implemente uma função que receba uma pilha como
//parâmetro e retorna como resultado uma cópia dessa pilha. Essa função
//deve obedecer ao protótipo:Pilha *pilha_copia (Pilha* p);
//Obs.: Ao final da função copia_pilha, a pilha p recebida como parâmetro
//deve estar no mesmo estado em que ela começou a função.

Pilha *pilha_copia (Pilha* p);
/*A função pilha_copia recebe como parâmetro uma pilha e retorna uma cópia dessa pilha. Ela utiliza apenas as funções desenvolvidas
para a pilha. Caso a pilha passada seja nula ou vazia, a função retorna 0.
A função cria duas novas pilhas: "novapi", que será a cópia da pilha passada, e "Aux", utilizada para auxiliar na cópia.
Em seguida, a função percorre a pilha passada e insere seus elementos na "novapi", bem como na "Aux".
Por fim, a função libera a pilha "Aux", já que seu uso foi finalizado. A cópia da pilha é então impressa e retornada.*/

//4) Dado uma pilha que armazene números, escreva uma função que
//forneça o maior, o menor e a média aritmética dos elementos da pilha.

void maior_menor_media(Pilha* pi);
/*Essa função recebe como parâmetro uma pilha de dados do tipo Aluno, que contém três notas para cada aluno.
A função calcula a maior nota, a menor nota e a média das notas presentes em todos os elementos da pilha, ignorando notas que são infinitas.
Em seguida, imprime esses valores na tela.
A função utiliza uma variável cont para contar a quantidade de notas presentes na pilha, uma variável soma para armazenar a soma das notas e as
variáveis maior e menor para armazenar a maior
e a menor nota encontradas, respectivamente.
A função percorre todos os elementos da pilha, verificando se cada nota não é infinita. Se não for, compara a nota com as variáveis maior e menor e, se necessário, atualiza essas variáveis.
Em seguida, soma a nota na variável soma e incrementa a variável cont.
Após percorrer toda a pilha, a função calcula a média das notas dividindo a variável soma pela variável cont, desde que cont seja diferente de zero. Em seguida, a
 função imprime na tela a maior nota, a menor nota e a média das notas, com duas casas decimais de precisão.*/

//5) Faça um programa que implemente uma calculadora, contendo as
//operações básicas (+, -, *, /)
void push(int i);
int pop (void);
void calculadora();

//6) Escreva um programa solicite ao usuário uma sequência de caracteres
//sem limite de tamanho máximo e realize as seguintes operações usando
//uma pilha:
//a) Imprimir o texto na ordem inversa;
//b) Verificar se o texto é um palíndromo, ou seja, se o texto é escrito da
//mesma maneira de frente para trás e de trás para frente. Ignore espaços
//e pontos.
int compara_pilha(Pilha* pi, Pilha* pi_invertido);
void pilha_inverso(Pilha* pi, Pilha* pi_invertido);

//7) Faça uma função para retornar o número de elementos da pilha que
//possuem valor par e o número de elementos com valor ímpar.
//char* par_impar_string(int n);

void par_impar(Pilha* pi);
/*A função par_impar recebe como parâmetro um ponteiro para a cabeça de uma pilha (Pilha* pi). Se essa pilha for nula
 (pi == NULL), a função simplesmente retorna. Se a pilha estiver vazia ((*pi) == NULL), a função também retorna.
A função percorre a pilha utilizando um ponteiro no para acessar cada elemento. Para cada elemento, a função realiza um
loop de 3 iterações, verificando se cada um dos três números (n1, n2, n3) é par ou ímpar.
Se um número for par, a função imprime "Par" seguido do valor do número utilizando a função printf. Se o número for ímpar,
a função imprime "Impar" seguido do valor do número, e incrementa a variável imparQuant, que conta a quantidade de números
ímpares encontrados na pilha.
Após percorrer todos os elementos da pilha, a função verifica se a variável imparQuant é igual a zero. Se for, a função
imprime a mensagem "Não há números ímpares na pilha". Caso contrário, a função imprime a quantidade de números ímpares encontrados na pilha.
Em resumo, a função par_impar percorre uma pilha de elementos que contém três números em cada nó, e imprime se cada um desses números é par ou ímpar.
Além disso, a função conta a quantidade de números ímpares na pilha e imprime essa quantidade no final.A função par_impar recebe como parâmetro um
ponteiro para a cabeça de uma pilha (Pilha* pi).
Se essa pilha for nula (pi == NULL), a função simplesmente retorna. Se a pilha estiver vazia ((*pi) == NULL), a função também retorna.
A função percorre a pilha utilizando um ponteiro no para acessar cada elemento. Para cada elemento, a função realiza um loop de 3 iterações, verificando
se cada um dos três números (n1, n2, n3) é par ou ímpar.
Se um número for par, a função imprime "Par" seguido do valor do número utilizando a função printf. Se o número for ímpar, a função imprime "Impar" seguido do valor do número,
e incrementa a variável imparQuant, que conta a quantidade de números ímpares encontrados na pilha.
Após percorrer todos os elementos da pilha, a função verifica se a variável imparQuant é igual a zero. Se for, a função imprime
a mensagem "Não há números ímpares na pilha". Caso contrário, a função imprime a quantidade de números ímpares encontrados na pilha.
Em resumo, a função par_impar percorre uma pilha de elementos que contém três números em cada nó, e imprime se cada um desses números é par ou ímpar.
 Além disso, a função conta a quantidade de números ímpares na pilha e imprime essa quantidade no final.*/

//8) Faça um programa para determinar se uma cadeia de caracteres (string)
//é da forma:
//x C y onde x e y são cadeias de caracteres compostas por letras ‘A’ e/ou ‘B’, e y é
//o inverso de x. Isto é, se x = “ABABBA”, y deve equivaler a “BABAAB”. Em
//cada ponto, você só poderá ler o próximo caractere da cadeia.



//9) Faça um programa que apresente um menu contínuo com as seguintes
//opções e execute de acordo com a escolha do usuário.
//void menu()
//{
// printf("1-Inicializa pilha.\n");
// printf("2-Verifica se a pilha e vazia.\n");
// printf("3-Verifica se a pilha e cheia.\n");
// printf("4-Empilha o elemento na pilha.\n");
// printf("5-Desempilha elemento da pilha.\n");
// printf("6-Le topo de um pilha.\n");
// printf("7-Converte um numero decimal em binario.\n");
// printf("8-Sair.\n");
//}
void menu();
/*O programa inicia com a exibição do menu e solicita que o usuário escolha uma opção. Em seguida, executa a ação correspondente à opção escolhida e retorna ao menu para uma nova escolha.
O programa utiliza uma variável "opcao" para controlar o fluxo do menu, e uma variável "i" para controle de iteração em loops.
 A variável "decimal" é utilizada para receber o número decimal que será convertido em binário.
O programa utiliza uma pilha implementada com lista encadeada, representada pelo tipo de dado Pilha.
 As operações de criação, liberação, verificação de pilha vazia, verificação de pilha cheia, inserção, remoção e consulta
 do elemento no topo da pilha são implementadas por funções específicas.
A função "decimalBinario" é utilizada para converter um número decimal em binário e imprime o resultado na tela.
O programa é encerrado quando o usuário escolhe a opção "8" no menu, após liberar a memória alocada para a pilha.
O programa inicia com a exibição do menu e solicita que o usuário escolha uma opção. Em seguida, executa a ação correspondente
à opção escolhida e retorna ao menu para uma nova escolha.
O programa utiliza uma variável "opcao" para controlar o fluxo do menu, e uma variável "i" para controle de iteração em loops.
A variável "decimal" é utilizada para receber o número decimal que será convertido em binário.
O programa utiliza uma pilha implementada com lista encadeada, representada pelo tipo de dado Pilha.
As operações de criação, liberação, verificação de pilha vazia, verificação de pilha cheia, inserção, remoção e consulta do
elemento no topo da pilha são implementadas por funções específicas.
A função "decimalBinario" é utilizada para converter um número decimal em binário e imprime o resultado na tela.
O programa é encerrado quando o usuário escolhe a opção "8" no menu, após liberar a memória alocada para a pilha.
*/
char* decimalBinario(int n);
/*O código implementa uma função chamada decimalBinario que recebe um número inteiro n e converte seu valor para binário,
retornando uma string que representa o número em binário. Para isso, é criado um vetor dinâmico binario
com 33 posições (32 bits + 1 caractere nulo no final) e inicialmente o índice i é igual a zero.
Em seguida, é realizado um loop do-while que faz a conversão do número decimal n para binário, armazenando os dígitos binários no vetor binario.
A cada iteração, é calculado o resto da divisão de n por 2 (que pode ser 0 ou 1) e é adicionado o caractere correspondente
('0' ou '1') no vetor binario. Depois, o valor de n é atualizado dividindo-o por 2. O loop continua enquanto n for maior que zero e enquanto i for menor que 32.
Em seguida, é adicionado o caractere nulo ao final da string binario e é realizada a inversão da ordem dos dígitos binários,
para que a string represente o número em binário de forma correta. Essa inversão é realizada com um loop for que percorre metade da string, trocando os caracteres de posição.
Por fim, a função imprime a string binario na tela (para fins de depuração) e retorna o ponteiro para o vetor binario.
É importante destacar que o vetor dinâmico alocado precisa ser desalocado em algum momento após o uso, para evitar vazamento de memória.*/