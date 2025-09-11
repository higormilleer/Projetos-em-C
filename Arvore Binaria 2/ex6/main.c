/*Faça uma função que elimine todos os valores pares da árvore.*/

#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main()
{
    Arvore *raiz = criaArvBin();
    
    insereArvore(raiz, 10); // head
    insereArvore(raiz, 13); // dir
    insereArvore(raiz, 8); // esq
    insereArvore(raiz, 6); // esq->esq
    insereArvore(raiz, 2); // esq->esq->esq
    insereArvore(raiz, 4); // esq->esq->esq->dir
    insereArvore(raiz, 6); // esq->esq->dir
    insereArvore(raiz, 12); // dir->esq
    insereArvore(raiz, 15); // dir->dir
    insereArvore(raiz, 18); // dir->dir->dir
    insereArvore(raiz, 16); // dir->dir->dir->esq
    insereArvore(raiz, 20); // dir->dir->dir->dir
    
    printf("Arvore completa: ");
    preOrdemArvore(raiz);
    
    removePar(raiz, *raiz);
    
    printf("\n");
    
    printf("Arvore Sem numero pares: ");
    preOrdemArvore(raiz);
    
    liberaArvore(raiz);

    return 0;
}

/*A funcao removePar, varre a arvore inteira, e caso o valor em que o no atual esta for resto 2, ou seja, for par, o no e removido*/