/*8) Escrever um procedimento para fazer a fusão de duas listas encadeadas
ordenadas, mantendo-a ordenada. Não devem ser alocados (criados)
nós extras. Os nós serão religados para compor a nova lista ordenada. */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    Lista *l1 = criarLista();
    Lista *l2 = criarLista();
    
    for(int i = 0;i<5;i++){
        inserirLista(l1,i);
    }
    
    for(int i = 5;i<10;i++){
        inserirLista(l2,i);
    }
    
    imprimirLista(l1);
    printf("\n");
    imprimirLista(l2);
    printf("\n");
    ordenadaLista(l1,l2);
    imprimirLista(l1);
  
    libera_lista(l1);
}

/*A função ordenadaLista() tem a tarefa de misturar as duas listas encadeadas em uma única lista ordenada. Primeiro, ela verifica se l2 está vazia, caso ela estiver,
a função faz l1 apontar para l2 e coloca a l2 como NULL. Se l1 estiver vazia, o processo é muito parecido,a lista l1 aponta para l2, e l2 é esvaziada. Depois a função faz um o nó inicial da 
lista mesclada (cabeca), como auxiliar e compara os primeiros nós de l1 e l2 e define cabeca como o nó com o menor valor, apos, ela percorre ambas as listas, inserindo os nós da lista l2 em l1 na posição
correta para manter a ordem crescente. Isso é feito ao ajustar os ponteiros dos nós para garantir que a sequência de valores permaneça ordenada.
Caso a lista l1 não tem mais nós após o ponto de inserção, a função simplesmente anexa o restante da lista l2 a l1, igualmente, se a lista l2 chega ao fim, 
o restante de l1 é anexado a l2, pois, isso define que estara em ordem o resto, depois de misturar as lista, a lista l1 é recolocada para iniciar em cabeca, que agora aponta para o início da lista ordenada,
e l2 é definida como NULL, indicando que todos os nós de l2 foram todos para l1.*/