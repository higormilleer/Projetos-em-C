/*) FaCa uma recursiva que conta a quantidade de nos que existem na
arvore int TotalNO_Arvore(ArvBin *raiz).*/

#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"
int main(){
    int N = 8, dados[8] = {50,100,30,20,40,45,35,37};

    ArvBin* raiz = cria_ArvBin();

    int i;
    for(i=0; i < N; i++)
        insere_ArvBin(raiz,dados[i]);

    printf("total Nos: %d\n",totalNO_ArvBin(raiz));

    libera_ArvBin(raiz);
    printf("\nFim!\n");
    return 0;
}

/*A função totalNO_ArvBin() inicia verificando se o nó raiz da árvore é nulo. Se for nulo, indica que a árvore está vazia. Caso contrário, a função continua a contar os nós das subárvores
esquerda e direita do nó atual, para realizar a contagem dos nós da subárvore esquerda, a função faz uma chamada recursiva,passando o ponteiro para a subárvore esquerda do nó atual. O resultado dessa chamada
é armazenado em uma variável chamada count_left. Desta mesma forma, a função é chamada recursivamente para contar os nós da subárvore direita,com o resultado armazenado em count_right, apos isso,
realizo a soma de ambas as variveis que armazena os numeros de nos encontrados, assim conseguindo identificar quantos nos ha na arvore*/