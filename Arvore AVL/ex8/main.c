/*Faça uma função Arv* transforma(Arv *raiz) que dada uma árvore binária
de busca qualquer, retorna uma nova árvore AVL.*/

#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"
#include "ArvoreBinaria.h"

void inserirVal(ArvBin *arvBin, ArvAVL *avl)
{
    if (avl == NULL)
        return;
    if (*arvBin == NULL)
        return;

    inserirVal(&((*arvBin)->esq), avl);
    inserirVal(&((*arvBin)->dir), avl);

    insere_ArvAVL(avl, (*arvBin)->info);
}

ArvAVL *binariaParaAVL(ArvBin *arvBin)
{
    if (arvBin == NULL || *arvBin == NULL)
        return NULL;

    ArvAVL *avl = cria_ArvAVL();

    inserirVal(arvBin, avl);

    return avl;
}

int main()
{
    ArvBin* bin = criaArvBin();
    for(int i=1;i<8;i++){
        insereArvBin(bin, i);
    }
    
    preOrdemArvBin(bin);
    
    printf("\n");
    
    ArvAVL *avl = binariaParaAVL(bin);

    preOrdem_ArvAVL(avl);
    
    libera_ArvAVL(avl);
    liberaArvBin(bin);

    return 0;
}

/* Utilizamos os documentos de arvore binaria para poder criar uma arvore binaria na funcao main.
A funcao inserirVal(), e reponsavel por inserir os valores da arvore binaria de uma forma balanceada recursivamente, se tornando uma ArvoreAVL
A funcao binariaParaAVL e reponsavel por criar uma arvore avl vazia e chamar a funcao de inserirValores(), retornando a arvore ja pronta no formato AVL*/
