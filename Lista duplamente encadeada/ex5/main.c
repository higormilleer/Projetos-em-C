#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    noDesc no;
    inicializa_noDesc(&no);
    
    enfileirar(&no, 0);
    enfileirar(&no, 1);
    
    imprimirNoDesc(&no);
    
    printf("\nApos remover:\n");
    
    int lista;
    desenfileirar(&no, &lista);
    
    imprimirNoDesc(&no);
    
    liberarNoDesc(&no);

    return 0;
}


/*A função enfileirar() recebendo como paremetro um ponteiro para um nó e um inteiro que representa o valor a ser inserido, ele inicia verificando se o nó existe, caso existir ele aloca memória 
para um novo nó da fila e inicializa seu valor com o inteiro que foi passado como paremetro, caso a fila está vazia, o novo nó se torna o início e o fim da fila, caso contrário, o novo nó é inserido
no final da fila: o ponteiro prox do nó que atualmente é o fim da fila é atualizado para apontar para o novo nó, e o ponteiro fim do nó descritor é atualizado para o novo nó.
A função desenfileirar() e passado como paremetro um ponteiro para um nó e um ponteiro para um inteiro onde será armazenado o valor do elemento removido, novamente, verificamos se o nó descritor é 
válido e se a fila não está vazia, logo depois, armazena o valor do nó que está no início da fila e ajusta o ponteiro ini do nó descritor para o próximo nó na fila, caso a fila
tinha apenas um elemento, tanto ini quanto fim são definidos como NULL, caso ainda tiver mais elementos, o próximo elemento se torna o novo início da fila. O nó removido é
liberado*/