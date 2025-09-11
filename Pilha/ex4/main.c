#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}Node, *Pilha;

Pilha* criarPilha()
{
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    if(p != NULL)
    {
        *p = NULL;
    }
    return p;
}
//criar uma pilha vazia 

void push(Pilha *lista, int x){
    if(lista==NULL) return;
    
    Node *novo = malloc(sizeof(Node));
    novo->valor = x; // Correção: atribuição do valor x ao novo nó
    novo->proximo = *lista;
    *lista = novo;
}
//empilhar um elemento na Pilha

void maior_menor_media(Pilha *lista) {
    if (*lista == NULL) return;

    int maior = (*lista)->valor;
    int menor = (*lista)->valor;
    int soma = 0;
    int contador = 0;

    Node *atual = *lista;

    while (atual != NULL) {
        int valor = atual->valor;
        if (valor > maior) {
            maior = valor;
        }
        if (valor < menor) {
            menor = valor;
        }
        soma += valor;
        contador++;
        atual = atual->proximo;
    }

    float media = (float)soma / contador;

    printf("Maior elemento: %d\n", maior);
    printf("Menor elemento: %d\n", menor);
    printf("Média aritmética: %.2f\n", media);
}
//pega os numeros que esta na pilha, varre ele e compara os valores maior e menor, logo apos e somado, fora do looping divido pelo numero de elementos da pilha dando a media
void imprimir(Pilha *lista){
    Node *atual = *lista;
    
    int i = 1;
    while(atual != NULL){
        printf("elemento %d: %d\n", i, atual->valor); 
        atual = atual->proximo;
        i++;
    }
}
//imprime os valores presentes na Pilha

void liberarPilha(Pilha *lista){
    if(lista==NULL)return;
    Node *no;
    while((*lista)!=NULL){
        no=*lista;
        *lista=(*lista)->proximo;
        free(no);
    }
    free(lista);
}
// libera o espaco alcoado na Pilha

int main()
{
    Pilha *lista = criarPilha();
    
    push(lista,10);
    push(lista,20);
    push(lista,30);
    push(lista,40);
    push(lista,50);

    printf("Pilha:\n");
    imprimir(lista);

    printf("\nAnálise da pilha:\n");
    maior_menor_media(lista); 

    liberarPilha(lista);
    return 0;
}

/*Na funcao maior_menor_media(), e passado como parametro a pilha, a variavel maior e menor inicializada com os valores da pilha e as variaveis soma e contador inicializada igual a 0,
depois e inicializada o no "atual" igual a pilha, entrando em um looping que enquanto o atual(ou seja, a pilha) for difente de nulo, comparados o valor inicializado com o valor do topo da pilha e comparamos:
caso ele for maior que a varivael 'maior', anteriormente definida com os valores da pilha, ele e definido como maior, assim achando qual o maior numero da pilha, assim feito com a mesma logica para descobrir o manor numero,
enquanto isso o "contador" sendo incrementado em um para descobrirmos os tamanho da pilha, pois, fora do looping dividimos a soma dos elementos pela quantidade, assim descobrindo a media. */


