/*Crie uma função que insere um valor em uma posição qualquer da lista
encadeada.*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    Lista *li = criarPilha();
    
    inserirLista(li,10,0);
    inserirLista(li,9,2);
    inserirLista(li,12,3);
    inserirLista(li,10,1);
    
    imprimir(li);
    
    libera_lista(li);
}

/*Na funcao inserirLista, passamos como parametro a lista, o numero em que desejamos inserir e qual a posicao. criamos um node para auxiliar e fazemos o tratamento
para ver se deu certo a insercao, caso a lista estiver vazia, a cabeca da lista e igualada ao valor em que desejamos, caso contrario, utilizamos uma estrategia em que
passamos no while o no e fazemos com que a variavel ant seja o valor anterior ao no ate achar a posicao em que queremos colocar o numero, quando encontrar,
mudamos os ponteiros, em que, o proximo do no anterior aponte para o no(no caso o que queremos inserir) e que o proximo do numero que queremos inserir, aponte para o 
auxiliar, assim ajustando ele na posicao correta*/