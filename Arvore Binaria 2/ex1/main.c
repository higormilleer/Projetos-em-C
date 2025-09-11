//Alunos: Matheus Plaza 2554119 & Higor Miller 2554070

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
    
    int N = 8, dados[8] = {50,100,30,20,40,45,35,37};

    ArvBin* raiz2 = cria_ArvBin();

    preOrdem_ArvBin(raiz);
    //emOrdem_ArvBin(raiz);
    //posOrdem_ArvBin(raiz);

    if(remove_ArvBin(raiz,20)){
        printf("removido\n");
        preOrdem_ArvBin(raiz);
    }else
        printf("NAO removido\n");

    printf("a quantidade de nos folha e :%d\n", nosFolha(raiz));

//    printf("altura: %d\n",altura_ArvBin(raiz));
//    printf("total NOs: %d\n",totalNO_ArvBin(raiz));
//
//    if (consulta_ArvBin(raiz, 4, &al))
//        printf("\n%d %s\n",al.mat,al.nome);

    libera_ArvBin(raiz);
    printf("\nFim!\n");
    return 0;
}
