/*3) Faça um função que conte quantos alunos tem uma nota qualquer n1
igual, com o seguinte protótipo int conta_lista_nota(Lista* li, int n1). A
função deve utilizar apenas o ponteiro li passado como parâmetro, não
pode ser criado nenhum outro ponteiro auxiliar. Ao final além de informar
a quantidade alunos com a mesma nota, o ponteiro li deve estar
apontado para a primeira célula “cabeça” da lista.*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    Lista* li =  criarLista();
    
    inserirLista(li,1);
    inserirLista(li,1);
    inserirLista(li,3);
    inserirLista(li,4);
    inserirLista(li,4);
    
    imprimirLista(li);
    
    int contagem = conta_lista_nota(li,1);
    
    printf("\n");
    printf("%d", contagem);
    printf(" %d", (*li)->numero);

    liberarLista(li);
    return 0;
}

/*Na funcao conta_lista_nota(), passamos como parametro o numero em que queremos fazer a contagem,
, caso o numero da lista for igual ao numero desejado, caso o primeiro numero desejado
igual a variavel conta mais 1, no while, enquanto o proximo da lista nao for nulo, e o numero for igual ao numero desaejado,
conta mais 1 e passa para o proximo. depois igualo a cabeca da lista ao final da mesma, entro em um while e enquanto o anterior
da lista nao for nulo, ela vai "avancado" ao contrario, ate chegar no lugar certo. */