/*Construa a função de rotação simples a esquerda void
RotacaoRR(ArvAVL *raiz).*/

#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

int main(){
    ArvAVL* avl;
    int res,i;
    int N = 10, dados[10] = {1,10,15,2,6,8,9,18,7,3};

    avl = cria_ArvAVL();

    for(i=0;i<N;i++){
        res = insere_ArvAVL(avl,dados[i]);
    }

    emOrdem_ArvAVL(avl);
    printf("\n\n");

    libera_ArvAVL(avl);


    return 0;
}

/*A rotacao esqueda simples (RR)e muito parecida com a direita simples(LL), portanto, para fazer a esquerda simples é so trocar no codigo
o que seria esq para direita, e vice versa, assim conseguindo o codigo RR */