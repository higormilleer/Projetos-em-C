/*Crie uma função que represente o algoritmo de PRIM, para encontrar a
Árvore Geradora Mínima de um grafo.*/


#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"
int main(){
    
    int eh_digrafoG2 = 0;
    int* PRIM(Grafo* g, int comeco);
    void imprimirPRIM(int* pi, int tamanho);
    
    Grafo *G2 = cria_Grafo(9,3,1);

    insereAresta(G2, 0,1, eh_digrafoG2, 10);
    insereAresta(G2, 0,2, eh_digrafoG2, 12);
    insereAresta(G2, 1,2, eh_digrafoG2, 9);
    insereAresta(G2, 1,3, eh_digrafoG2, 8);
    insereAresta(G2, 2,4, eh_digrafoG2, 3);
    insereAresta(G2, 2,5, eh_digrafoG2, 1);
    insereAresta(G2, 3,4, eh_digrafoG2, 7);
    insereAresta(G2, 3,7, eh_digrafoG2, 5);
    insereAresta(G2, 4,5, eh_digrafoG2, 3);
    insereAresta(G2, 4,2, eh_digrafoG2, 3);
    insereAresta(G2, 5,7, eh_digrafoG2, 6);
    insereAresta(G2, 5,3, eh_digrafoG2, 6);
    insereAresta(G2, 6,8, eh_digrafoG2, 2);
    insereAresta(G2, 6,7, eh_digrafoG2, 9);
    
    
    int *pi = PRIM(G2, 0);
    
    imprimirPRIM(pi, 9);

    libera_Grafo(G2);
    return 0;
}

/*Funcao POP_MIN(), ela remove o vertice com o menor peso(key), passando como parametro o Q(fila de vertices nao incluso),
key(pesos associados), numero de Vertices. comecamos falando que nao acahamos o menor peso para chegar ate certo vertice,
e a chave com o valor enorme que certamente sera trocado pelo valor que acharmos chamada de minKey. Varre todos os vertices e caso o vertice ainda nao foi excluido,
e seu peso e menor que minKey, atualiza a mesma e o atualiza falando que achamos o menor vertice, depois pega o mesmo vertice e fala que ja utilizamos ele e retorna o mesmo.

Funcao Prim(), faz a verificacao comum para ver se o grafo e nulo, depois aloca as variaveis key(valor 'infinito'), pi(-1, para colocar ela como que nao tem predecessores inicialmente) 
e Q(indice vertice), e faz a verificacao em todos para garantir que a alocacao deu certo. Define verticeInicial como 0 inicialmente, para partirmos desse vertice na busca da arvore.
O for faz com que conseguimos acessar todos os vertices e conseguimos achar os menores pesos de cada um (origem para destino), chamando a funcao de POP_MIN para ajudar na busca, depois de achar
os menores valores, ele libera a ley usada e o Q, e retorna os predecessores de cada vertice que achamos, neles constendo a arvore geradora minima.

Funcao imprimirPRIM(), pega os valores que descobrimos na funcao Prim(), e imprime de acordo.*/