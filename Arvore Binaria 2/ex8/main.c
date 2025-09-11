/*Dada uma árvore binária vazia, insira e imprima os seguintes elementos
na ordem que é mostrada: M, F, S, D, J, P, U, A, E, H, Q, T, W, K.*/

#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main()
{
    Arvore *raiz = criaArvBin();
    char elementos[] = {'M', 'F', 'S', 'D', 'J', 'P', 'U', 'A', 'E', 'H', 'T', 'W', 'Q','K'};
    
    for (int i = 0; i < 14; i++) {
        insereArvore(raiz, elementos[i]);
    }
    
    ordemLetra(raiz);
    
    
    liberaArvore(raiz);

    return 0;
}

/*Na função ordemLetra(), utilizamos uma fila para realizar a travessia da árvore binária em ordem de nível onde 
começamos inserindo o nó raiz na fila e enquanto houver elementos na fila, removemos o nó da frente, imprimimos o seu valor e adicionamos 
os filhos esquerdo e direito, se existirem, à fila, por conta deste método de uso da fila garantimos que os todos os nós sejam visitados do topo para a base e da esquerda 
para a direita em cada nível, garantindo que as letras sejam processadas na ordem correta conforme o nível da árvore.*/