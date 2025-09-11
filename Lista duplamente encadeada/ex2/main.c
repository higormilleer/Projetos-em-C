/*2) Faça uma função que insira um novo elemento na lista de forma
ordenada, lembrando que essa inserção pode acontecer para o novo
elemento no início, no fim e no meio da lista dependendo da ordem da
mesma. Utilize a função insere_lista_ordenada da lista encadeada como
base para criar essa função.*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    Lista *li = criarLista();
    
    for(int i= 1; i<5;i++){
        insereLista(li,i);
    }
    imprimirLista(li);
    printf("\n");
    insereOrdenada(li, 3);
    imprimirLista(li);
    return 0;
}

/*Na funcao insereOrdenada(), no primeiro if,  quando a "cabeca" da lista e nula, apotamos a "cabeca" para o no, e os ponteiro de ant
e prox para NULL)*, depois usamos o while para percorrer ate a lista fosse nula e achar o numero q fosse menor ou igual ao que
queremos colocar em ordem, caso o node passado como pametro fosse igual a "cabeca" da lista, direcionamos o ponteiro ant para NULL
usamos a o ant da "cabeca" da lista apotando para o no, e ajustamos o ponteiro do no->prox para apontar para a "cabeca", apos insere_lista_ordenada
definimos que a cabeca da lista era agora o no. Caso o node nao fosse igual ao comeco da lista, usamos o no->prox seria igual ao
proximo do auxliar, e para colocar os dois ponteiros no lugar certo, igualamos o anterior do no igual ao auxiliar, e apos isso 
o proximo do auxiliar igual ao no. */