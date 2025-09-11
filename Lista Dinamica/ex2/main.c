/*2) Faça duas funções recursivas. A primeira deve remover um nó da lista
encadeada a partir do seu valor armazenado (ex: int info). 
A segunda deve receber duas listas encadeadas e verificar se elas são iguais.*/
#include "lista.h"
#include <stdio.h>


int main()
{
    Aluno al[5] = {{69, "Sara"},{38, "Matheus"},{24, "Pedro"},{90, "Rogerio"},{23, "Rosangela"}};

    Lista *li = criarLista();

    for(int i=0;i<5;i++)
        insereLista(li, al[i]);
    
    imprimir_lista(li);
        
    printf("\ndepois: \n");
    remove_lista(li, 23);
    
    imprimir_lista(li);
    
    printf("\n");
    Lista *l1 = criarLista();
    Lista *l2 = criarLista();
    
    for(int i=0;i<5;i++)
        insereLista(l1, al[i]);
    
    for(int i=1;i<5;i++)
        insereLista(l2, al[i]);
        
    if(comparacao(l1,l2))
    {
        printf("E igual");
    }
    else
    {
        printf("E diferente");
    }
    
    libera_lista(li);
}

/* Na função remove_lista e comparado o valor armazenado no nó atual com o dado que foi passado como parametro para ser removido, se
encontrar o dado no nó atual, libera o nó e ajusta os ponteiros para remover o nó da lista, caso contrário, 
ele chama recursivamente a função para o próximo nó da lista, ate achar o dado.
Na função comparacao os valores armazenados nos nós atuais de l1 e l2 sao comparados de modo que se os valores forem diferentes, 
retorna o codigo, indicando que as listas não são iguais, porem, se os valores forem iguais, verifica se ambos os nós atuais têm o próximo nó como nulo, 
indicando o fim das listas,caso isso nao ocorra, chama recursivamente a função para os próximos nós de l1 e l2
*/
