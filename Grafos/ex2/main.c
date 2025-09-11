/*Faça o que se pede:
a. Construa um exemplo de grafo simples direcionado e um não
direcionado.
b. Construa um grafo simples conexo, com as seguintes sequências
de graus.
(a) (1, 1, 2, 3, 3, 4, 4, 6)
(b) (3, 3, 3, 3, 3, 5, 5, 5)*/


#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

int main() {
    int eh_digrafog1 = 1; 
    int eh_digrafog2 = 0; 

    //Grafo direcionado 
    Grafo *g1 = cria_Grafo(7, 9, eh_digrafog1);
    
    insereAresta(g1, 0, 1, 1, 0.0);
    insereAresta(g1, 1, 2, 1, 0.0);
    insereAresta(g1, 2, 3, 1, 0.0);
    insereAresta(g1, 3, 4, 1, 0.0);
    insereAresta(g1, 4, 5, 1, 0.0);
    insereAresta(g1, 5, 6, 1, 0.0);
    insereAresta(g1, 6, 0, 1, 0.0);
    insereAresta(g1, 0, 3, 1, 0.0);
    insereAresta(g1, 3, 5, 1, 0.0);

    // Grafo não direcionado 
    Grafo *g2 = cria_Grafo(8, 13, eh_digrafog2);
    
    insereAresta(g2, 0, 1, 0, 0.0);
    insereAresta(g2, 0, 2, 0, 0.0);
    insereAresta(g2, 0, 3, 0, 0.0);
    insereAresta(g2, 1, 2, 0, 0.0);
    insereAresta(g2, 1, 3, 0, 0.0);
    insereAresta(g2, 1, 4, 0, 0.0);
    insereAresta(g2, 2, 4, 0, 0.0);
    insereAresta(g2, 2, 5, 0, 0.0);
    insereAresta(g2, 3, 4, 0, 0.0);
    insereAresta(g2, 3, 6, 0, 0.0);
    insereAresta(g2, 4, 5, 0, 0.0);
    insereAresta(g2, 4, 6, 0, 0.0);
    insereAresta(g2, 4, 7, 0, 0.0);
    insereAresta(g2, 5, 6, 0, 0.0);
    insereAresta(g2, 5, 7, 0, 0.0);
    insereAresta(g2, 6, 7, 0, 0.0);
    
--------------------------------------------------------------------------------

    // Grafo não direcionado Conexo(exemplo a)
    Grafo *g3 = cria_Grafo(8, 15, eh_digrafog2);
    
    insereAresta(g3, 0, 1, 0, 0.0);
    insereAresta(g3, 0, 2, 0, 0.0);
    insereAresta(g3, 0, 3, 0, 0.0);
    insereAresta(g3, 1, 2, 0, 0.0);
    insereAresta(g3, 1, 4, 0, 0.0);
    insereAresta(g3, 2, 3, 0, 0.0);
    insereAresta(g3, 2, 4, 0, 0.0);
    insereAresta(g3, 2, 5, 0, 0.0);
    insereAresta(g3, 3, 4, 0, 0.0);
    insereAresta(g3, 3, 6, 0, 0.0);
    insereAresta(g3, 4, 5, 0, 0.0);
    insereAresta(g3, 4, 6, 0, 0.0);
    insereAresta(g3, 5, 6, 0, 0.0);
    insereAresta(g3, 5, 7, 0, 0.0);
    insereAresta(g3, 6, 7, 0, 0.0);

   // Grafo não direcionado Conexo(exemplo b)
    Grafo *g4 = cria_Grafo(8, 24, eh_digrafog2);
   
    insereAresta(g4, 0, 1, 0, 0.0);
    insereAresta(g4, 0, 2, 0, 0.0);
    insereAresta(g4, 0, 3, 0, 0.0);
    insereAresta(g4, 1, 2, 0, 0.0);
    insereAresta(g4, 1, 3, 0, 0.0);
    insereAresta(g4, 1, 4, 0, 0.0);
    insereAresta(g4, 2, 3, 0, 0.0);
    insereAresta(g4, 2, 5, 0, 0.0);
    insereAresta(g4, 3, 6, 0, 0.0);
    insereAresta(g4, 4, 5, 0, 0.0);
    insereAresta(g4, 4, 6, 0, 0.0);
    insereAresta(g4, 5, 6, 0, 0.0);
    insereAresta(g4, 5, 7, 0, 0.0);
    insereAresta(g4, 6, 7, 0, 0.0);
    insereAresta(g4, 1, 7, 0, 0.0);
    insereAresta(g4, 0, 4, 0, 0.0);
    insereAresta(g4, 2, 6, 0, 0.0);
    insereAresta(g4, 4, 7, 0, 0.0);
    insereAresta(g4, 3, 7, 0, 0.0);
    insereAresta(g4, 0, 5, 0, 0.0);

    
    printf("Grafo Direcionado:\n");
    imprime_Grafo(g1);
    printf("\n\n");

    printf("Grafo Não-Direcionado:\n");
    imprime_Grafo(g2);
    printf("\n\n");

    printf("Grafo Não-Direcionado Conexo (Sequência 1, 1, 2, 3, 3, 4, 4, 6):\n");
    imprime_Grafo(g3);
    printf("\n\n");

    printf("Grafo Não-Direcionado Conexo (Sequência 3, 3, 3, 3, 3, 5, 5, 5):\n");
    imprime_Grafo(g4);
    printf("\n\n");

    libera_Grafo(g1);
    libera_Grafo(g2);
    libera_Grafo(g3);
    libera_Grafo(g4);

    return 0;
}
