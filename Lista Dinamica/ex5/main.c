/*5) Receba um número inteiro não negativo e faça uma função que percorra
a lista e remova todos os nós que contiverem esse número inteiro
armazenado neles. Faça todas as condições de controle necessárias
para as remoções sejam corretas.*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    Aluno al[6] = {{69, "Sara"},{38, "Matheus"},{24, "Pedro"},{90, "Rogerio"},{23, "Rosangela"},{23,"rambo"}};

    Lista *li = criarLista();

    for(int i=0;i<6;i++)
        insereLista(li, al[i]);
    
    imprimir_lista(li);
    
    printf("\nDepois: \n");
    percorra(li, 23);
    
    imprimir_lista(li);
    
    libera_lista(li);
}

/*Na funcao percorra, declaramos as variaveis atual sendo igualada ao topo da lista e a anterior sendo igualada a null,
enquanto o no atual for diferente de null, caso os dados da matriculadas inseridos no main forem iguais ao dado de matricula 
q eu quero retirar, se o anterior for nulo, o topo da lista e igual ao proximo do atual assim removendo o primeiro nó ajustando 
o início da lista, caso contrario, o proximo do anterior e igual ao proximo do atual, assim, removendo um nó no meio da lista.
Depois, guarda o nó atual em uma variável temporária e avanca para o proximo nó da lista. E caso os valores da matricula nao forem
iguais, o anterior fica igualado no valor do atual, armazenando o valor e mexendo o ponteiro do atual para o proximo*/