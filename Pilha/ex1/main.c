/*Faça um programa que tenha uma nova função chamada pop2() para
desempilhar dois elementos da pilha e uma outra função chamada
push2() para empilhar 2 elementos a partir do topo da pilha. Não devem
ser utilizadas as funções de push e pop já existentes.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
} Node, *pilha;

pilha* criarPilha()
{
    pilha *p = (pilha*)malloc(sizeof(pilha));
    if(p != NULL)
    {
        *p = NULL;
    }
    return p;
}
//funcao para criar uma pilha vazia

void liberarPilha(pilha *lista){
    if(lista==NULL)return;
    Node *no;
    while((*lista)!=NULL){
        no=*lista;
        *lista=(*lista)->proximo;
        free(no);
    }
    free(lista);
}
//funcao para liberar a memoria alocada na pilha

void push2(pilha *lista, int x, int y){
    if(lista == NULL) return;

    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo == NULL) return;

    novo->valor = x;
    novo->proximo = *lista;
    *lista = novo;
    
    Node *novo2 =(Node*)malloc(sizeof(Node));
    if(novo2 == NULL) return;
    
    novo2->valor = y;
    novo2->proximo=*lista;
    *lista=novo2;
}
//funcao que recebe como parametro a pilha, o primeiro e segundo valor a ser empilhados

void pop2(pilha *lista){
    if(lista == NULL) return;
    for(int i=0;i<2;i++)
    {
        if(*lista == NULL) return;
    
        Node *remover = *lista;
        *lista = remover->proximo;
        free(remover);
    }
}
//funcao que recebe como parametro a pilha ja empilhada anteriormente, porem nessa funcao sera desempilhados.

void imprimir(pilha *lista){
    if(lista==NULL) return;
    
    Node *atual = *lista;
    int i = 1;
    while(atual != NULL){
        printf("Elemento %d: %d\n", i, atual->valor);
        atual = atual->proximo;
        i++;
    }
}
//funcao para imprimir os valores que estao na pilha no momento

int main(){
    pilha *lista = criarPilha();

    push2(lista, 10, 5);
    push2(lista, 7, 4);
    
    printf("Pilha com 2 termos inseridos:\n");
    imprimir(lista);
    
    printf("Pilha com menos 2 termos: ");
    pop2(lista);
    imprimir(lista);
    
    liberarPilha(lista);

    return 0;
}

/*A função push2() empilha dois elementos na pilha, enquanto a função pop2() desempilha dois elementos,a função criarPilha() inicializa uma nova pilha vazia,
e liberarPilha() libera a memória alocada para a pilha, ja a função imprimir() imprime os elementos da pilha anteriormente empilhados e/ou desempilhados.
O  main() demonstra a utilização dessas funções, inserindo elementos na pilha e imprimindo a pilha, logo depois e removido os elementos e impreso novamente.*/


