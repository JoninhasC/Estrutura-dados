#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"

int main(){
    struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};
    Pilha* pi = cria_Pilha();

    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));
    int i;
    //int n;

   for(i=0; i < 4; i++)
        insere_Pilha(pi,a[i]);
  //  inserir2(pi,a[1]);


   // calculadora();
    imprime_Pilha(pi);
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));
    par_impar(pi);
    //maior_menor_media(pi);
    for(i=0; i < 4; i++)
        remove_Pilha(pi);
   // remove2(pi);
  //  printf("\n retirar quantos elementos:  ");
  // scanf("%d",&n);
  // popN(pi,n);
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));
    imprime_Pilha(pi);

    for(i=0; i < 4; i++)
        insere_Pilha(pi,a[i]);

    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));
    imprime_Pilha(pi);


    libera_Pilha(pi);
    system("pause");
      return 0;

    /*Pilha* pi;
    int i=0;
    int opcao =0;
    int decimal;

    menu();
    while (opcao !=8){
        printf("\nEscolha uma opcao: ");
        scanf("%d",&opcao);
        switch (opcao) {
            case 1:
                    cria_Pilha(pi);
                    printf("\nPilha criada");
                break;
            case 2:
                    Pilha_vazia(pi);
                break;
            case 3:
                    Pilha_cheia(pi);
                break;
            case 4:
                    for( i=0; i < 4; i++)
                     insere_Pilha(pi,a[i]);
                break;
            case 5:
                    for(i=0; i < 4; i++)
                     remove_Pilha(pi);
                break;
            case 6:
                    consulta_topo_Pilha(pi, a);
                break;
            case 7:
                    printf("Informe um numero pra ser convertido: ");
                    scanf("%d",&decimal);
                    decimalBinario(decimal);
                break;
            default:
                printf("\n");
        }

    }
    libera_Pilha(pi);
    system("pause");
    return 0;*/

}

