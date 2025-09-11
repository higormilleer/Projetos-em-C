/*Escrever uma função para remover elementos repetidos de uma lista
encadeada*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    Lista *li = criarLista();
    
    inserirLista(li,1);
    inserirLista(li,2);
    inserirLista(li,2);
    inserirLista(li,6);
    inserirLista(li,6);
    imprimirLista(li);
    printf("\n");
    remove_lista(li);
    imprimirLista(li);
  
    libera_lista(li);
}
   
/*Na funcao remove_lista, passamos a lista como parametro.Ate esse no nao chegar no final da lista, percorremos ele, apos isso criamos um no auxiliar e mais duas 
variaveis uma para representar o no anterior e o auxiliar para representar o proximo no. e colocamos outro while para percorrer o auxiliar agora
Comparamos o numero do no atual ao numero do proximo no(no caso, o no auxiliar), caso forem iguais, mudamos os ponteiros para com que o numero repetido se 
desconcte do anterior(variavel ant) e do proximo numero (variavel aux), caso os numeros nao forem iguais, a variavel anterior iguala ao aux, e o aux passa para o 
proximo numero, apos sair desse segundo while, passamos para o proximo no, assim conseguindo identificar todos os numeros que sao iguais*/ 

    
