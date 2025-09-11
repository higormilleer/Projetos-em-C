/*Faça um programa que utilizando apenas as funções desenvolvidas
para a pilha, implemente uma função que receba uma pilha como
parâmetro e retorna como resultado uma cópia dessa pilha. Essa função
deve obedecer ao protótipo:
Pilha *pilha_copia (Pilha* p);
Obs.: Ao final da função copia_pilha, a pilha p recebida como parâmetro
deve estar no mesmo estado em que ela começou a função.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}Node, *Pilha;

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
//libera o espaco alocado da Pilha

Pilha* criarPilha()
{
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    if(p != NULL)
    {
        *p = NULL;
    }
    return p;
}
//cria uma pilha vazia

void push(Pilha *lista, int x){
    if(lista==NULL) return;
    
    Node *novo =(Node*)malloc(sizeof(Node));
    novo->valor=x;
    novo->proximo=*lista;
    *lista=novo;
}
//empilha um elemento a Pilha

void pop(Pilha *lista){
    if(lista==NULL)return;
    if(*lista==NULL) return;
    
    Node *remover = *lista;
    *lista = remover->proximo;
    free(remover);
}
//desempilha um elemento da Pilha

Pilha *pilha_copia (Pilha *p)
{
    Pilha *p1 = criarPilha();
    Node *n1 = *p;
    
    while(n1!=NULL)
    {
        push(p1,n1->valor);
        n1 = n1->proximo;
    }
    
    Pilha *p2 = criarPilha();
    Node *n2 = *p1;
    
    while(n2!=NULL)
    {
        push(p2,n2->valor);
        n2 = n2->proximo;
    }
    
    liberarPilha(p1);
    
    return p2;
}
//copia a pilha principal na segunda pilha, porem com a ordem invertida, depois copia a pilha invertida
//novamente, porem agora na terceira pilha, fazendo assim imprimir na mesma ordem que a principal

void imprimir(Pilha *lista){
    Node *atual = *lista;
    
    int i = 1;
    while(atual!=NULL){
        printf("elemento %d: %d\n",i,atual->valor);
        atual=atual->proximo;
        i++;
    }
}
//imprime os elementos presetes na Pilha

int main()
{
    Pilha *lista = criarPilha();
    
    push(lista,10);
    push(lista,50);
    push(lista,100);
    push(lista,150);
    
    
    Pilha *copia = pilha_copia(lista);

    printf("original\n");
    imprimir(lista);
    printf("\ncopia\n");
    imprimir(copia);
    
    liberarPilha(copia);
    liberarPilha(lista);
    
    return 0;
}

/*a funcao pilha_copia recebe como parametro a pilha original que foi empilhada, usa a mesma para empilhar na segunda pilha,
porem com a ordem invertida, pois o ultimo a entrar e o primeiro a sair,
assim, sendo necessario passar os valores da segunda pilha para um terceira, fazendo a pilha ser passa na mesma ordem que a principal*/
