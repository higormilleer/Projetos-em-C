/*Faça um programa que tenha uma nova função chamada popN() para
desempilhar n elementos a partir do topo da pilha. Não devem ser
utilizadas as funções de push e pop já existentes*/

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
//cria uma pilha vazia

void empilhar(pilha *lista, int x){
    if(lista == NULL) return;

    Node *novo =(Node*)malloc(sizeof(Node));
    if(novo == NULL) return;

    novo->valor = x;
    novo->proximo = *lista;
    *lista = novo;
}
//empilha um elemento na pilha

void popN(pilha *lista,int n){
    if(lista == NULL) return;
    for(int i=0;i<n;i++)
    {
        if(*lista == NULL) return;
    
        Node *remover = *lista;
        *lista = remover->proximo;
        free(remover);
    }
}
//desempilha n elementos da pilha (quantos forem digitados, desde que seja o mesmo tanto presente na pilha)

void imprimir(pilha *lista){
    Node *atual = *lista;
    int i = 1;
    while(atual != NULL){
        printf("Elemento %d: %d\n", i, atual->valor);
        atual = atual->proximo;
        i++;
    }
}
//imprime os elementos presente na pilha no momento

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
//libera o espaco alocado da pilha

int main(){
    pilha *lista = criarPilha();

    int n, valor; 
    
    printf("Quantos termos deseja empilhar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Digite o valor do termo %d: ", i+1);
        scanf("%d", &valor);
        empilhar(lista, valor);
    }

    printf("\nPilha com %d termos inseridos:\n", n);
    imprimir(lista);
    
    int termos_desempilhar;
    printf("\nQuantos termos deseja desempilhar(maximo de %d)? ", n);
    scanf("%d", &termos_desempilhar);

    popN(lista, termos_desempilhar);
    printf("\nPilha após desempilhar %d elementos usando popN:\n", termos_desempilhar);
    imprimir(lista);

    liberarPilha(lista);
    return 0;
}

/*A função criarPilha() inicializa uma nova pilha vazia, a função liberarPilha() libera a memória alocada, 
empilhar() insere um elemento na pilha,popN() desempilha n elementos da pilha (quantos forem digitados, desde que seja o mesmo tanto presente na pilha) 
e imprimir() imprime os elementos que estao na pilha no momento*/




