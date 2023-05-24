#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"

int main(){
    struct aluno al, a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {4,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};
    struct aluno al2, a2[4] = {{225,"Andre",9.5,7.8,8.5},
                             {144,"Ricardo",7.5,8.7,6.8},
                             {155,"Bianca",9.7,6.7,8.4},
                             {666,"Ana",5.7,6.1,7.4}};
    Lista* li = cria_lista();
    //Lista* li2 = cria_lista();
    printf("Tamanho: %d\n\n\n\n",tamanho_lista(li));
    //printf("Tamanho: %d\n\n\n\n",tamanho_lista(li2));
    int i;
    for(i=0; i < 4; i++)
        insere_lista_ordenada(li,a[i]);
   /*for(i=0; i < 4; i++)
        insere_lista_ordenada(li2,a2[i]);
    imprime_lista(li2);*/
    //imprime_lista(li);
    removeRepete(li);
    //concatenar(li,li2);
   // fusaoListasOrdenadas(li,li2);
    printf("Tamanho: %d\n\n\n\n",tamanho_lista(li));
    imprime_lista(li);
    //printf("Tamanho: %d\n\n\n\n",tamanho_lista(li2));
   // imprime_lista(li2);
   // imprime_lista(li);
    //imprime_lista(li2);
    /*inserirIndex(li,5,a2[0]);
    imprime_lista(li);
    printf("Tamanho: %d\n\n\n\n",tamanho_lista(li));*/
    /*int num =0;
    printf("informe o matricula: ");
    scanf("%d", &num);
    imprimiMatricula(li, num );
    printf("informe o posicao: ");
    scanf("%d", &num);
    imprimePosicao( li,  num);*/
    /*printf("informe o matricula: ");
    scanf("%d", &num);
    removeNo(li, num);
    imprime_lista(li);*/
    //verificarIgual(li,li2);
    /* printf("\n\n\n\n Tamanho: %d\n",tamanho_lista(li));

     for(i=0; i < 4; i++){
         remove_lista_final(li);
         imprime_lista(li);
         printf("\n Tamanho: %d\n\n\n",tamanho_lista(li));
     }

     for(i=0; i < 4; i++)
         insere_lista_ordenada(li,a[i]);
     imprime_lista(li);*/

    libera_lista(li);
   // libera_lista(li2);
    system("pause");
    return 0;
}

