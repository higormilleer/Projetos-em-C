/*Escrever uma função para concatenar duas listas encadeadas L1 e L2. */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    Lista *l1 = criarLista();
    Lista *l2 = criarLista();
    
    for(int i=0;i<5;i++){
        insereLista(l1,i);
    }
    
    for(int i=5;i<10;i++){
        insereLista(l2,i);
    }
    
    imprimir(l1);
    printf("\n");
    concatenar(l1,l2);
    imprimir(l1);
    
    libera_lista(l1);
}

/*Na funcao concatenar, caso a lista 1 fosse nula, so igualava ao l2, caso contrario, com a ajuda do auxiliar
percorro a mesma inteira ate chegar no ultimo elemento, apos isso, igualo o valor do proximo da lista 1
para a lista 2, assim concatenando ambas*/
