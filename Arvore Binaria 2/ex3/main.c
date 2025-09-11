#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"
int main(){

    ArvBin* raiz = cria_ArvBin();

    insere_ArvBin(raiz, 10); // head
    insere_ArvBin(raiz, 13); // dir
    insere_ArvBin(raiz, 8); // esq
    insere_ArvBin(raiz, 6); // esq->esq
    insere_ArvBin(raiz, 2); // esq->esq->esq
    insere_ArvBin(raiz, 4); // esq->esq->esq->dir
    insere_ArvBin(raiz, 6); // esq->esq->dir
    insere_ArvBin(raiz, 12); // dir->esq
    insere_ArvBin(raiz, 15); // dir->dir
    insere_ArvBin(raiz, 18); // dir->dir->dir
    insere_ArvBin(raiz, 16); // dir->dir->dir->esq
    insere_ArvBin(raiz, 20); // dir->dir->dir->dir

    preOrdem_ArvBin(raiz);
    //emOrdem_ArvBin(raiz);
    //posOrdem_ArvBin(raiz);

    if(remove_ArvBin(raiz,20)){
        printf("removido\n");
        preOrdem_ArvBin(raiz);
    }else
        printf("NAO removido\n");


//    printf("altura: %d\n",altura_ArvBin(raiz));
//    printf("total NOs: %d\n",totalNO_ArvBin(raiz));
//
//    if (consulta_ArvBin(raiz, 4, &al))
//        printf("\n%d %s\n",al.mat,al.nome);
    int buscar;
    printf("digite o valor que deseja buscar: \n");
    scanf("%d", &buscar);
    printf("a quantidade de valores encontrados e: %d", apareceu(raiz, buscar));

    libera_ArvBin(raiz);
    printf("\nFim!\n");
    return 0;
}
