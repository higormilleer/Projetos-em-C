/*Utilizando o arquivo “ProjGrafo” e o seu respectivo código:
a. Detalhe o funcionamento da função Grafo* cria_Grafo(int
nro_vertices, int grau_max, int eh_ponderado). Utilize trechos do
código para ilustrar sua resposta.
b. Detalhe o funcionamento da função libera_Grafo(Grafo* gr). Utilize
trechos do código para ilustrar sua resposta.
c. Detalhe o funcionamento da função insereAresta(Grafo* gr, int
orig, int dest, int eh_digrafo, float peso). Utilize trechos do código
para ilustrar sua resposta.
d. Detalhe o funcionamento da função removeAresta(Grafo* gr, int
orig, int dest, int*/


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
