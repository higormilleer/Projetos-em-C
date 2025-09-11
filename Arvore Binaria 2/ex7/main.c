#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"
int main(){

    ArvBin* raiz = cria_ArvBin();

    int M = 8, dados1[8] = {53,102,31,20,40,45,35,37};

    
    int N = 8, dados[8] = {50,100,30,20,40,45,35,37};

    ArvBin* raiz2 = cria_ArvBin();

   int j;
    for(j=0; j < M; j++)
        insere_ArvBin(raiz,dados1[j]);

    int i;
    for(i=0; i < N; i++)
        insere_ArvBin(raiz2,dados[i]);
        
    if(verificaArvore(raiz, raiz2))
        printf("as arvores sao semelhantes\n");
        
    else
        printf("as arvores sao diferentes\n");
    

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

    libera_ArvBin(raiz);
    printf("\nFim!\n");
    return 0;
}
