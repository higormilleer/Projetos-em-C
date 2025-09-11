#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

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
    
    imprimirDec(raiz);

    
    liberaArvore(raiz);

    return 0;
}
