/*Recebendo como parâmetro um vetor de float, por exemplo v[n] = “5.5,
8, 9.1, 25”, crie uma função que construa lista encadeada com esses
valores, seguindo a mesma ordem em que os números estão no vetor
recebido.*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    float vetor[4] = {5.5, 8, 9.1, 25};
    
    Lista* li = criarLista();
    
    for(int i = 0;i<4;i++)
    {
        inserirLista(li, vetor[i]);
    }
    
    imprimirLista(li);
    
    libera_lista(li);
}

/*Na funcao inserirLista, passamos como parametro a lista e o numero como float, criamos um no para auxiliar e novamente fizemos o tratamento para ver se a aloacao
deu certo. caso a cabeca da lista seja vazia, colocamos o valor dela como ao numero em que passamos, caso contrario, criamos outro no auxiliar como cabeca, varremos
o no, e vamos passamos o auxiliar com ele, quando achamos o ultimo no, saimos do while e igualamos o proximo deste auxiliar ao valor do no em que queremos,
assim colocando os numeros na ordem em que foi digitalizada anteriormente*/