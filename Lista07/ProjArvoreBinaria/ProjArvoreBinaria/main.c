#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"
int main(){
    int N = 8, dados[8] = {50,100,30,20,40,45,35,37};
    int num;
    ArvBin* raiz = cria_ArvBin();

    int i;
    for(i=0; i < N; i++)
        insere_ArvBin(raiz,dados[i]);
    printf("Preordem(r,e,d) –Preorder\n");
    preOrdem_ArvBin(raiz);
    printf("--------------------------------------------------");
    printf("\nEmordem(e,r,d) –Inorder\n");
    emOrdem_ArvBin(raiz);
    printf("--------------------------------------------------");
    printf("\nPósordem(e,d,r) –Postorder\n");
    posOrdem_ArvBin(raiz);

    printf("A árvore possui %d nós.\n", TotalNO_Arvore(raiz));
    Cons_Arvore(raiz,10);
    if(remove_ArvBin(raiz,50)){
        printf("removido\n");
        preOrdem_ArvBin(raiz);
    }else
        printf("NAO removido\n");


//    printf("altura: %d\n",altura_ArvBin(raiz));
//    printf("total NOs: %d\n",totalNO_ArvBin(raiz));
//
//    if (consulta_ArvBin(raiz, 4, &al))
//        printf("\n%d %s\n",al.mat,al.nome);

    libera_ArvBin(raiz);
    printf("\nFim!\n");
    return 0;
}
