#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* criarLista(){
    Lista* li = (Lista*)malloc(sizeof(Lista));
    if(li==NULL) return 0;
    
    if((*li)!=NULL){
        (*li)==NULL;
    }
    return li;
    
}

void imprimirLista(Lista *li){
    if(li == NULL || (*li)==NULL) return;
    
    Node *no = *li;
    
    while(no!=NULL){
        printf("%d",no->numero);
        no = no->prox;
    }
}

void liberarLista(Lista *li){
    if(li!=NULL){
        
        Node *no;
        while((*li)!=NULL){
            no = (*li);
            (*li)=(*li)->prox;
            free(no);
        }
        free(li);
    }
}

void inserir_lista_inicio(Lista *li, int numero){
    if(li==NULL) return;
    
    Node *no = (Node*)malloc(sizeof(Node));
    if(no==NULL)return;
    
    no->numero = numero;
    no->prox = (*li);
    no->ant = NULL;
    
    if((*li)!=NULL)
        (*li)->ant = no;
        
    (*li) = no;
}

void inserir_lista_final(Lista *li, int numero){
    if(li==NULL) return;
    
    Node *no = (Node*)malloc(sizeof(Node));
    if(no==NULL)return;
    
    no->numero = numero;
    no->prox = NULL;
    
    if((*li)==NULL){
        no->ant = NULL;
        (*li)=no;
    }
    else{
        Node *aux = (*li);
        while(aux->prox!=NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
    }
}

void remover_inicio(Lista *li){
    if(li == NULL || (*li)==NULL) return;
    
    Node *no = (*li);
    (*li) = no->prox;
    if(no->prox==NULL){
        no->prox->ant = NULL;
    }
    
    free(no);
}

void remover_final(Lista *li){
    if(li == NULL || (*li)==NULL) return;
    
    Node *no = (*li);
    
    while(no->prox!=NULL){
        no = no->prox;
    }
    
    if(no->ant == NULL){
        (*li) = no->prox;
    }
    else{
        no->ant->prox =NULL;
    }
    
    free(no);
}

void remover_numero(Lista *li, int numero){
    if(li == NULL || (*li)==NULL) return;
    
    Node *no = (*li);
    if(no==NULL) return;
    
    while(no!=NULL && no->numero!=numero){
        no = no->prox;
    }
    
    if(no->ant ==NULL){
        (*li) = no->prox;
    }
    else{
        no->ant->prox = no->prox;
        if (no->prox != NULL) {
            no->prox->ant = no->ant;
        }
    }
    free(no);
}