/*Observe a função PREOrdem_Arvore e faça testes com essa. Com base
na função escreva as funções de varredura EMOrdem_Arvore e
POSOrdem_ArvBin*/

#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"
int main(){
    int N = 8, dados[8] = {50,100,30,20,40,45,35,37};

    ArvBin* raiz = cria_ArvBin();

    int i;
    for(i=0; i < N; i++)
        insere_ArvBin(raiz,dados[i]);

    preOrdem_ArvBin(raiz);
    emOrdem_ArvBin(raiz);
    posOrdem_ArvBin(raiz);

    if(remove_ArvBin(raiz,50)){
        printf("removido\n");
        preOrdem_ArvBin(raiz);
    }else
        printf("NAO removido\n");


    libera_ArvBin(raiz);
    
    return 0;
}

/*Na função preOrdem_ArvBin():
A função preOrdem_ArvBin realiza um moveimento em pré-ordem na árvore binária. Assim, o nó raiz é processado antes de suas subárvores. Primeiramente, a função verifica se o ponteiro para a árvore(raiz)
é nulo, caso ele for, a função retorna imediatamente, pois a árvore está vazia ou não foi inicializada ainda. Se o nó raiz não for nulo, a função imprime o valor do nó atual e, em seguida, chama
recursivamente  preOrdem_ArvBin para a subárvore esquerda e depois para a subárvore direita. Assim, a função visita o nó raiz antes de suas subárvores, assim, resulta na ordem de processamento: 
raiz, esquerda, direita.

Na função emOrdem_ArvBin():
A função emOrdem_ArvBin realiza uma movimento em ordem (ou infixa) na árvore binária. Neste caso, a função visita primeiro a subárvore esquerda, depois o nó raiz, e finalmente a subárvore direita.
Primeiramente, verifica se o ponteiro da árvore é nulo e retorna se for o caso, pois a árvore ou esta vazia, ou ainda nao foi inicializada. Se o nó raiz não for nulo, a função chama recursivamente 
emOrdem_ArvBin para a subárvore esquerda, imprime o valor  do nó atual, e então chama recursivamente emOrdem_ArvBin para a subárvore direita. Essa ordem garante que todos os nós da subárvore 
esquerda sejam processados antes do nó raiz e, finalmente, os nós da subárvore direita.

Na função posOrdem_ArvBin():
A função posOrdem_ArvBin realiza uma movimento em pós-ordem na árvore binária. Ja neste caso, a função visita primeiro a subárvore esquerda, depois a subárvore direita, e por último o nó raiz. 
Primeiramente, verifica se o ponteiro da árvore é nulo e retorna se for, pois a árvore ou esta vazia, ou ainda nao foi inicializada. Se o nó raiz não for nulo, a função chama recursivamente 
posOrdem_ArvBin para a subárvore esquerda e, em seguida, para a subárvore  direita. Após visitar ambas as subárvores, imprime o valor do nó atual. Isso garante que o nó raiz seja processado após suas
subárvores, resultando na ordem de processamento: esquerda, direita, raiz.*/

