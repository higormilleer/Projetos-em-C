/* Faça uma função para imprimir a árvore de modo que seja possível
identificar os nós filhos, pais e folhas.*/

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
    
    imprimeArv(raiz, *raiz);

    liberaArvore(raiz);

    return 0;
}

/*A funcao imprimirArv(), varre a arvore usando a logica de, caso o no nao tiver ninguem na direita e direita ele e uma folha, caso contrario, ele e pai.
depois, para identificar se ele e filho ou nao, neste caso, ele so nao sera filho caso for a cabeca da arvore, que e apenas pai, dito isso, caso nao for a cabeca
ele e filho*/