#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main()
{
    Arvore *raiz = criaArvoreCalculo();

    printf("Resultado do calculo: %d\n", calcularResultado(raiz));
    
    printf("Infixa: ");
    imprimeInfixa(raiz);
    printf("\n");
    
    printf("Prefixa: ");
    imprimePrefixa(raiz);
    printf("\n");
    
    printf("Posfixa: ");
    imprimePosfixa(raiz);

    liberaArvore(raiz);
    return 0;
}

/*Na funcao criaArvoreCalculo(), criamos uma arvore e colocamos como a cabeca da mesma sendo o +, depois fomos colocando para ficar igual da imagem,
utilizando raiz->esq = criarNode('*')por exemplo, para cada caractere, assim construindo a arvore de maneira solicitada.
Na funcao calcularResultado(), usamos de forma recursiva para percorrer a arvore inteira, e caso encontrar algum caractere de calculo,e ele realiza o q foi pedido,
assim calculando de forma correta.
Nas funcoes imprimeInfixa, imprimePrefixa e imprimePosfixa utilizam da mesma logica, caso o no tiver filhos ele imprime o '(', depois imprime o valor do no, e percorre de forma recursiva
a arvore, e no final de cada recursao ele verifica, caso for um no folha imprime um ')' para fechar a conta*/