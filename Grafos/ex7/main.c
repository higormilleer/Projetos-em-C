/*Crie as seguintes funções:
a. Encontrar um nó específico no grafo.
b. Encontrar a aresta de menor peso de um grafo.
c. Obter todos os nós adjacentes (vizinhos) a um no do grafo, dado
que o grafo e representado por uma matriz de adjacências.*/


#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"
int main(){
    int eh_digrafo = 1;
    Grafo* gr = cria_Grafo(5, 5, 0);

    insereAresta(gr, 0, 1, eh_digrafo, 0);
    insereAresta(gr, 1, 3, eh_digrafo, 0);
    insereAresta(gr, 1, 2, eh_digrafo, 0);
    insereAresta(gr, 2, 4, eh_digrafo, 0);
    insereAresta(gr, 3, 0, eh_digrafo, 0);
    insereAresta(gr, 3, 4, eh_digrafo, 0);
    insereAresta(gr, 4, 1, eh_digrafo, 0);

    imprime_Grafo(gr);
    printf("\nBusca \n");

    libera_Grafo(gr);

    system("pause");
    return 0;
}
