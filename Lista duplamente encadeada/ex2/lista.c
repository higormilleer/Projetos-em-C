#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* criarLista(){
    Lista *li = (Lista*)malloc (sizeof(Lista));
    if(li==NULL)return 0;
    
    if((*li)!=NULL){
        (*li)==NULL;
    }
    return li;
}

void imprimirLista(Lista* li){
    if(li==NULL||(*li)==NULL) return;
    
    Node *no = (*li);
    while(no!=NULL){
        printf("%d", no->numero);
        no = no->prox;
    }
    return;
}

void insereLista(Lista* li, int numero){
    if(li==NULL) return;
    
    Node *no = (Node*) malloc (sizeof(Node));
    if(no==NULL)return;
    
    no->numero=numero;
    no->prox=NULL;
    
    if((*li) == NULL){
        no->ant = NULL;
        (*li) = no;
    }
    else{
        Node *aux = (*li);
        while(aux->prox!=NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
    }
    return;
}

void insereOrdenada(Lista *li, int numero){
    if(li==NULL) return;
    
    Node* no = (Node*)malloc(sizeof(Node));
    if(no==NULL) return;
    
    no->numero = numero;
    
    if((*li)==NULL){
        (*li)=no;
        no->ant = NULL;
        no->prox = NULL;
        return;
    }
    else{
        Node *aux, *node = (*li);
        while(node!=NULL && node->numero<=numero){
            aux = node;
            node=node->prox;
        }
        if(node == (*li)){
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            (*li) = no;
        }
        else{
            no->prox = aux->prox;
            no->ant = aux;
            aux->prox = no;
        }
    }
    return;
}