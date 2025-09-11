/*4) Refaça as funções de inserir e remover no início e fim para que a lista
comporte-se de forma circular. No fim, faça uma função que para
percorrer a lista inteira utilizando o comportamento circular da mesma*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    Lista* li = criarLista();
    
    inserir_inicio(li,1);
    inserir_inicio(li,2);
    inserir_inicio(li,3);
    inserir_inicio(li,1);
    inserir_inicio(li,2);
    inserir_inicio(li,3);
    
    imprimirLista(li);
    
    remover_final(li);
    imprimirLista(li);
 
    liberarLista(li);
    return 0;
}

/*Na funcao imprimirLista(), igual o no a cabeca da lista, depois usei um do while para percorrer e imprmir ate o no for igual
ao a cabeca da lista.
Na funcao inserir_inicio(), caso a lista for nula, igualamos a cabeca da lista para o no e o prox e ant tambem, caso for diferente
de nulo a lista, o proximo do no igualamos a cabeca da lista e o anterior do mesmo ao ultimo elemento da lista, o proximo do 
ultimo elemento da lista igualamos tambem ao novo no e o anterior da cabeca da lista ao no e agora a cabeca da lista se torna o no.
Na funcao inserir_final(), caso a lista for nula, fizemos a mesma coisa que para inserir no inicio, caso contrario,
o proximo do no e a cabeca da lista e o anterior do no e igual ao ultimo elemento da lista, ja o proximo do ultimo elemento da lista
igualamos ao no e o anterior da cabeca ao novo no.
Na funcao remover_inicio(), caso a lista tiver apenas um elemento, igualamos a lista a nulo e damos um free apos isso, caso contrario,
tornamos o proximo elemento do anterior(no caso, olugar que estava o proprio no), ao anteior do no, e vice versa, e igualamos
o proximo do nó a cabeca da lista, assim podendo dar o free no nó.
Na funcao remover_final(), declaramos uma variavel do tipo no e igualamos ao ultimo elemento da lista. Caso a lista tiver apenas um
elemento, damos free no nó e  a cabeca da lista se torna nula, caso contrario, o penultimo elemento da lista vai apontar para 
a cabeca, e o anterior da cabeca e igual ao penultimo elemente (vice e versa), depois damos free no nó.*/