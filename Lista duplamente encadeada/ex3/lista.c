#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* criarLista() {
    Lista* li = (Lista*)malloc(sizeof(Node));
    if (li != NULL) {
        (*li) = NULL;
    }
    return li;
}

void liberarLista(Lista *li){
    if(li!=NULL){
        Node *no;
        while((*li)!=NULL){
            no=(*li);
            (*li)=(*li)->prox;
            free(no);
        }
        free(li);
    }    
}

void imprimirLista(Lista* li){
    if(li==NULL || (*li)==NULL) return;
    
    Node *no = (*li);
    
    while(no!=NULL){
        printf("%d", no->numero);
        no = no->prox;
    }
    return;
}

void inserirLista(Lista* li, int numero){
    if(li==NULL) return;
    
    Node* no = (Node*)malloc(sizeof(Node));
    if(no==NULL) return;
    
    no->numero = numero;
    no->prox = NULL;
    
    if((*li)==NULL){
        no->ant=NULL;
        (*li)=no;
    }
    else{
        Node *aux=(*li);
    while(aux->prox!=NULL){
        aux = aux->prox;
    }
    aux->prox=no;
    no->ant = aux;
    }
}

int conta_lista_nota(Lista* li, int numero)
{
    if(li==NULL||(*li)==NULL) return 0;
    
    int count = 0;
    
    if((*li)->numero==numero) count++;
    
    while((*li)->prox!=NULL){
        if((*li)->prox->numero==numero){
            count++;
        }
        (*li)=(*li)->prox;
    }
    
    (*li)=(*li)->ant;    
    
    while((*li)->ant!=NULL){
        (*li)=(*li)->ant;
    }

    return count;
}