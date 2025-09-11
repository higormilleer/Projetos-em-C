/*Faça uma função que consulta se um determinado valor existe na árvore
int Cons_Arvore(ArvBin *raiz, int valor).*/

#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"
int main(){
    int N = 8, dados[8] = {50,100,30,20,40,45,35,37};

    ArvBin* raiz = cria_ArvBin();

    int i;
    for(i=0; i < N; i++)
        insere_ArvBin(raiz,dados[i]);

    if (Cons_Arvore(raiz,3)){
        printf("Existe");
    }
    else{
        printf("Nao existe");
    }

    libera_ArvBin(raiz);
    
    return 0;
}

/*a função Cons_Arvore() compara o valor que está sendo buscado com o valor armazenado no nó atual, caso os valores forem iguais, significa que o valor foi encontrado e a 
função retorna 1. Caso contrario, o valor procurado não corresponder ao valor do nó atual,se o valor procurado é menor do que o valor do nó atual, 
a função faz uma chamada recursiva para buscar na subárvore esquerda,se o valor for maior,a busca vai para a na subárvore direita. 
Assim conseguindo achar o valor desejado*/