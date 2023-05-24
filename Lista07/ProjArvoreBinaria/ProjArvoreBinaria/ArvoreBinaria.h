
typedef struct NO* ArvBin;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);

int remove_ArvBin(ArvBin *raiz, int valor);
struct NO* remove_atual(struct NO* atual);
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
int totalNO_ArvBin(ArvBin *raiz);
int consulta_ArvBin(ArvBin *raiz, int valor);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);


//01
/*Observe as funções insere_Arvore e remove_Arvore faça testes com as
mesmas e descreva como cada função opera na árvore.*/
int insere_ArvBin(ArvBin* raiz, int valor);
/*A função insere_ArvBin é responsável por inserir um novo nó contendo um determinado valor em uma árvore binária de busca.
 Vou explicar o seu funcionamento passo a passo:
O parâmetro raiz é um ponteiro para um ponteiro de nó da árvore, ou seja, é um ponteiro que aponta para a raiz da árvore.
 Se esse ponteiro for nulo (indicando que a árvore está vazia), a função retorna 0, indicando falha na inserção.
Em seguida, um novo nó é alocado dinamicamente na memória usando malloc. A estrutura NO é uma estrutura que contém o valor
 (info) e os ponteiros para os nós filho esquerdo (esq) e direito (dir).
Se a alocação falhar (ou seja, novo for nulo), a função retorna 0 para indicar falha na inserção.
O valor é atribuído ao campo info do novo nó e os campos esq e dir são definidos como nulos.
Se a raiz da árvore (*raiz) for nula, isso significa que a árvore está vazia e o novo nó se torna a raiz.
Caso contrário, a árvore não está vazia e é necessário encontrar a posição correta para inserir o novo nó. A função
 utiliza dois ponteiros auxiliares: atual e ant. O ponteiro atual aponta para o nó atual sendo examinado e o ponteiro
 ant aponta para o nó anterior a atual.
É feito um loop enquanto o atual não for nulo. Dentro do loop, o nó anterior (ant) é atualizado para atual e então são
 realizadas as seguintes verificações:
Se o valor a ser inserido (valor) for igual ao valor do nó atual (atual->info), significa que o elemento já existe na
 árvore. Nesse caso, o nó novo é liberado da memória usando free e a função retorna 0 para indicar falha na inserção.
Se o valor a ser inserido for maior que o valor do nó atual, o atual é atualizado para o nó filho direito (atual->dir).
Caso contrário, o valor a ser inserido é menor ou igual ao valor do nó atual, então o atual é atualizado para o nó filho
 esquerdo (atual->esq).
Após o loop, a posição correta para inserir o novo nó foi encontrada. Nesse ponto, é feita uma última verificação usando
 o nó anterior (ant). Se o valor a ser inserido (valor) for maior que o valor do nó anterior, o novo nó é atribuído ao
 campo dir desse nó. Caso contrário, o novo nó é atribuído ao campo esq do nó anterior.
Por fim, a função retorna 1 para indicar o sucesso na inserção do novo nó na árvore binária de busca
Essa função segue a lógica básica de inserção em uma árvore binária de busca, garantindo que não haja duplicatas de valores na árvore.*/
int remove_ArvBin(ArvBin *raiz, int valor);
struct NO* remove_atual(struct NO* atual);
/* função remove_ArvBin é responsável por remover um nó contendo um valor específico de uma árvore binária de busca.
 * Além disso, a função remove_atual é utilizada como uma função auxiliar para auxiliar na remoção do nó atual da árvore.
 * Vou explicar o funcionamento dessas duas funções passo a passo:
Na função remove_ArvBin, é feita uma verificação inicial para garantir que o ponteiro raiz não seja nulo. Se for nulo,
 significa que a árvore está vazia, e a função retorna 0 para indicar falha na remoção.
São declarados dois ponteiros auxiliares: ant (que será o ponteiro para o nó anterior ao atual) e atual (que é inicializado
 como a raiz da árvore).
É feito um loop enquanto o atual não for nulo. Dentro do loop, é realizada a seguinte sequência de verificações:
Se o valor a ser removido (valor) for igual ao valor do nó atual (atual->info), significa que o nó a ser removido foi
 encontrado. Nesse caso, é feita uma verificação adicional para determinar se o nó atual é a raiz da árvore. Se for a
 raiz, a função remove_atual é chamada para remover o nó atual e, em seguida, a raiz é atualizada com o retorno dessa função.
Caso contrário, se o valor a ser removido for maior que o valor do nó atual, o ant é atualizado para o atual e o atual
 é atualizado para o nó filho direito (atual->dir).
Caso contrário, o valor a ser removido é menor que o valor do nó atual, então o ant é atualizado para o atual e o atual
 é atualizado para o nó filho esquerdo (atual->esq).
Após o loop, é verificado se o nó a ser removido foi encontrado ou não. Se o nó for encontrado, ele será removido da
 árvore e a função retornará 1 para indicar sucesso na remoção. Caso contrário, a função retorna 0 para indicar falha na remoção.
A função remove_atual é responsável por remover o nó atual da árvore. Ela recebe como parâmetro o nó atual a ser removido.
Na função remove_atual, são declarados dois ponteiros auxiliares: no1 e no2. O no1 será utilizado para rastrear o
 pai do no2, que é o nó que será retornado pela função.
É feita uma verificação inicial para determinar se o nó atual não possui um filho esquerdo. Se não possuir, o no2 é
 atualizado para o filho direito do nó atual, o nó atual é liberado da memória usando free e o no2 é retornado como o novo nó atual.
Caso contrário, se o nó atual possui um filho esquerdo, o no1 é atribuído ao nó atual e o no2 é atribuído ao filho esquerdo do nó atual.
É feito um loop enquanto o no2 tiver um filho direito. Dentro do loop, o no1 é atualizado para o no2 e o no2 é atualizado
 para o filho direito do no2. Esse loop serve para encontrar o nó que é o anterior na ordem de visita da árvore (e-r-d).
Após o loop, o no2 é o nó que é anterior ao nó atual na ordem de visita da árvore. O no1 é o pai do no2.
É feita uma verificação para determinar se o no1 é diferente do nó atual. Isso ocorre quando o no2 não é o filho direito
 direto do nó atual, ou seja, existem nós entre o nó atual e o no2.
Se o no1 for diferente do nó atual, o filho direito do no1 é atualizado para o filho esquerdo do no2 e o filho esquerdo
 do no2 é atualizado para o filho esquerdo do nó atual.
O filho direito do no2 é atualizado para o filho direito do nó atual.
O nó atual é liberado da memória usando free e o no2 é retornado como o novo nó atual.
Essas funções trabalham juntas para remover um nó específico de uma árvore binária de busca, garantindo que a estrutura
 da árvore seja preservada corretamente.*/
//02
/*Observe a função PREOrdem_Arvore e faça testes com essa. Com base
na função escreva as funções de varredura EMOrdem_Arvore e
POSOrdem_ArvBin.*/
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
/*A função emOrdem_ArvBin é responsável por percorrer uma árvore binária de busca em ordem e imprimir os valores dos nós.
 * Vou explicar o seu funcionamento passo a passo:
A função começa com uma verificação para garantir que o ponteiro raiz não seja nulo. Se for nulo, isso significa que a
 árvore está vazia, e a função simplesmente retorna sem fazer nada.
Em seguida, é feita uma verificação adicional para determinar se o nó raiz (*raiz) não é nulo. Se não for nulo, significa
 que a árvore não está vazia e ainda há nós para percorrer.
Dentro do bloco de código executado quando o nó raiz não é nulo, a função realiza o percurso em ordem da árvore:
Primeiro, a função chama recursivamente a função preOrdem_ArvBin passando o endereço do nó filho esquerdo (&((*raiz)->esq)).
 Isso faz com que o percurso em ordem seja realizado para o nó filho esquerdo.
Em seguida, o valor do nó raiz ((*raiz)->info) é impresso usando printf. Nesse caso, o valor é impresso em uma nova linha,
 seguido por "\n".
Por fim, a função chama recursivamente a função preOrdem_ArvBin passando o endereço do nó filho direito (&((*raiz)->dir)).
 Isso faz com que o percurso em ordem seja realizado para o nó filho direito.
Essa recursão permite que a função percorra toda a árvore de forma recursiva, visitando todos os nós em ordem (esquerda,
 raiz, direita) e imprimindo seus valores.
Essa função é útil para imprimir os valores dos nós de uma árvore binária de busca em ordem crescente, fornecendo uma
 forma organizada de visualizar os elementos da árvore.*/
void posOrdem_ArvBin(ArvBin *raiz);
/*A função posOrdem_ArvBin é responsável por percorrer uma árvore binária de busca em pós-ordem e imprimir os valores dos
 * nós. Vou explicar o seu funcionamento passo a passo:
Assim como nas funções anteriores, a função começa com uma verificação para garantir que o ponteiro raiz não seja nulo.
 Se for nulo, isso significa que a árvore está vazia, e a função simplesmente retorna sem fazer nada.
Em seguida, é feita uma verificação adicional para determinar se o nó raiz (*raiz) não é nulo. Se não for nulo, significa
que a árvore não está vazia e ainda há nós para percorrer.
Dentro do bloco de código executado quando o nó raiz não é nulo, a função realiza o percurso em pós-ordem da árvore:
Primeiro, a função chama recursivamente a função preOrdem_ArvBin passando o endereço do nó filho esquerdo (&((*raiz)->esq)).
 Isso faz com que o percurso em pós-ordem seja realizado para o nó filho esquerdo.
Em seguida, a função chama recursivamente a função preOrdem_ArvBin passando o endereço do nó filho direito (&((*raiz)->dir)).
 Isso faz com que o percurso em pós-ordem seja realizado para o nó filho direito.
Por fim, o valor do nó raiz ((*raiz)->info) é impresso usando printf. Nesse caso, o valor é impresso em uma nova linha,
 seguido por "\n".
Essa recursão permite que a função percorra toda a árvore de forma recursiva, visitando todos os nós em pós-ordem (esquerda,
 direita, raiz) e imprimindo seus valores.
Essa função é útil para imprimir os valores dos nós de uma árvore binária de busca em pós-ordem, fornecendo uma forma organizada
 de visualizar os elementos da árvore*/


//03 Faça uma recursiva que conta a quantidade de nós que existem na
//árvore int TotalNO_Arvore(ArvBin *raiz).
int TotalNO_Arvore(ArvBin *raiz);
/*A função verifica se a árvore está vazia, verificando se raiz ou *raiz é NULL. Em caso afirmativo, retorna 0, indicando
 * que não há nós na árvore.
Caso contrário, a função chama recursivamente TotalNO_Arvore para a subárvore esquerda ((*raiz)->esq) e para a subárvore
 direita ((*raiz)->dir), armazenando a quantidade de nós retornada em qtde_esq e qtde_dir, respectivamente.
Em seguida, retorna o valor total, que é a soma de 1 (representando o nó atual) com a quantidade de nós nas subárvores
esquerda e direita.
Essa implementação é válida para contar a quantidade de nós em uma árvore binária de busca.*/

//04 Faça uma função que consulta se um determinado valor existe na árvore
//int Cons_Arvore(ArvBin *raiz, int valor).

int Cons_Arvore(ArvBin *raiz, int valor);
/*A função Cons_Arvore é responsável por realizar uma busca em uma árvore binária de busca para verificar se um determinado
 * valor está presente ou não na árvore. Abaixo está a explicação de cada parte da função:
Verificação da condição de parada: A função verifica se a árvore está vazia (ou seja, raiz é NULL) ou se o nó atual (*raiz)
 é nulo. Se qualquer uma dessas condições for verdadeira, significa que a árvore está vazia ou o valor não foi encontrado.
 Nesse caso, a função exibe uma mensagem indicando que o valor não foi encontrado e retorna 0.
Verificação do valor atual: A função verifica se o valor do nó atual ((*raiz)->info) é igual ao valor procurado. Se for igual,
 significa que o valor foi encontrado na árvore. A função exibe uma mensagem indicando que o valor foi encontrado e retorna 1.
Busca na subárvore esquerda: Se o valor procurado for menor que o valor do nó atual, a função chama recursivamente a função
 Cons_Arvore passando a subárvore esquerda como novo parâmetro raiz. Isso significa que a busca será realizada na subárvore esquerda da árvore atual.
Busca na subárvore direita: Se o valor procurado for maior que o valor do nó atual, a função chama recursivamente a função
 Cons_Arvore passando a subárvore direita como novo parâmetro raiz. Isso significa que a busca será realizada na subárvore direita da árvore atual.
Essa abordagem de busca em uma árvore binária de busca permite percorrer a árvore de forma eficiente, aproveitando a estrutura
 ordenada da árvore para determinar o caminho correto durante a busca.
Você pode usar a função Cons_Arvore para verificar a existência de um valor específico na árvore binária de busca, exibindo uma
 mensagem indicando se o valor foi encontrado ou não.*/