#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"

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
int main(){
    struct aluno al,a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};
    Fila* fi;
    Fila* fi2;


    printf("Tamanho: %d\n\n\n\n",tamanho_Fila(fi));
    int i;
    for(i=0; i < 4; i++){
        insere_Fila(fi,a[i]);
        if(Fila_vazia(fi))
            printf("Erro!!!!!!\n");

        consulta_Fila(fi,&al);
        printf("Consulta: %d \t %s\n",al.matricula,al.nome);
    }
    printf("\nTamanho: %d\n\n",tamanho_Fila(fi));
    imprime_Fila(fi);


    /*printf("\nTamanho: %d\n\n",tamanho_Fila(fi));
    imprime_Fila(fi);
    separa(fi, fi2, 4);
    printf("\nTamanho: %d\n\n",tamanho_Fila(fi));
    imprime_Fila(fi);
    printf("\nTamanho: %d\n\n",tamanho_Fila(fi2));
    imprime_Fila(fi2);*/


    for(i=0; i < 4; i++){
        remove_Fila(fi);
        consulta_Fila(fi,&al);
        printf("Consulta: %d \t %s\n",al.matricula,al.nome);
    }
    printf("Tamanho: %d\n\n\n\n",tamanho_Fila(fi));
    imprime_Fila(fi);

    for(i=0; i < 4; i++)
        insere_Fila(fi,a[i]);

    printf("Tamanho: %d\n\n\n\n",tamanho_Fila(fi));
    imprime_Fila(fi);

    libera_Fila(fi);
    system("pause");
    /*menu();
    int opcao =0;
    scanf("%d",&opcao);
    while (opcao != 9){
        switch (opcao) {
            case 1:
                    fi2 =cria_Fila();
                break;
            case 2:
                    Fila_vazia(fi2);
                break;
            case 3:
                    Fila_cheia(fi2);
                break;
            case 4:
                    for(int i=0; i < 4; i++){
                        insere_Fila(fi2,a[i]);
                        if(Fila_vazia(fi2))
                            printf("Erro!!!!!!\n");
                    }
                break;
            case 5:
                    for(int i=0; i < 4; i++){
                        remove_Fila(fi2);
                    }
                break;
            case 6:
                    imprime_Primeiro(fi2);
                break;
            case 7:
                    void testar_tamanho_filas(fi, fi2);
                break;
            case 8:
                    void furar_fila( fi,4  , 3);
                break;
            default:
                printf("opção invalida");
                break;
        }
    }*/
    libera_Fila(fi);
    system("pause");
    return 0;
}


