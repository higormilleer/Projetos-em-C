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

/*A funcao de remove_ArvAVL(), caso o valor é menor que o no atual, o filho que esta na esquerda e chamado, ali ocorrera a remocao
e o fator de balanceamento da arvore onde caso ele for maior ou igual a 2 acontecera RR ou o RL
Caso o valor e maior que o no atual, o filho que esta na direita e chamado, e faz o mesmo processo citado a cima,
caso ele for menor ou igual a -2 ele fazer a LL ou LR.
Durante este processo, ele faz a verificao se existe um filho ou dois filhos, no caso de ter apenas um filho, o nó filho
entra no lugar do pai, caso contrario e o no tiver dois filhos, encontra o menor filho a direita, fazendo este virar o pai,ele entrar no lugar do no
que esta para ser removido.
Depois, so falta arrumar a altura da arvore apos a remocao, importante para futuras chamadas*/

