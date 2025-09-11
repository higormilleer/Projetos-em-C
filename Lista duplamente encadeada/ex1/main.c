/*1) Faça uma função que remova um aluno dada a sua respectiva matricula.
Sua função deve reajustar os ponteiros ant e prox assim que remover o
elemento, não esqueça de verificar se a elemento que será removido
está em uma célula que é a primeira ou a última ou alguma célula do
meio da lista, para cada posição o ajuste dos ponteiros é diferente.


Integrante: Higor Miller Grassi     Ra: 2554070
       Matheus Menezes Plaza     Ra: 2554119
*/
       
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    Lista *li = criarLista();
    
    for(int i = 0; i<5; i++){
        inserir_lista_final(li,i);
    }
    
    imprimirLista(li);
    
    remover_numero(li,0);
    remover_numero(li,2);
    
    printf("\n");
    
    imprimirLista(li);
    
    return 0;
}

/* Na funcao remover_numero(), no primeiro while, achamos o numero em que queremos remover, apos isso,
caso o numero procurado seja o primeiro numero da lista, igualamos a cabeca da lista ao prox do no, assim
podendo dar um free no nó sem comprometer a cabeca da lista. Caso nao esteja no comeco da lista, o proximo
do no anterior, ser igual ao proximo do no(assim, o no anterior aponta para o proximo do no atual), e,
o anterior do proximo e igual ao no anterior assim desconectando do numero que queremos excluir, dando 
free no nó;*/