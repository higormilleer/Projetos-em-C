#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* criarLista(){
    Lista* li = (Lista*)malloc(sizeof(Lista));
    if(li==NULL)return 0;
    
    (*li)=NULL;
    
    return li;
}

void liberarLista(Lista *li) {
    if (li == NULL || *li == NULL) return; 
    
    Node *no = *li;  
    Node *aux;         
    
    do {
        aux = no->prox;  
        free(no);        
        no = aux;    
    } while (no != *li); 
    
    free(li);
}

void imprimirLista(Lista* li) {
    if (li == NULL || (*li) == NULL) {
        return;
    }
    
    Node *no = (*li);
    
    do {
        printf(" %d", no->numero);
        no = no->prox;
    } while (no != (*li));
    
    printf("\n");
}

void inserir_inicio(Lista *li, int numero){
    if(li==NULL) return;
    
    Node *no = (Node*)malloc(sizeof(Node));
    if(no==NULL)return;
    
    no->numero = numero;
    
    if((*li)==NULL){
        (*li) = no;
        (*li)->ant = no;
        (*li)->prox = no;
    }
    else{
        no->prox = (*li);
        no->ant = (*li)->ant;
        (*li)->ant->prox = no;
        (*li)->ant = no;
        (*li)=no;
    }  
}

void inserir_final(Lista *li, int numero){
    if(li==NULL) return;
    
    Node *no = (Node*)malloc(sizeof(Node));
    if(no==NULL)return;
    
    no->numero = numero;
    
    if((*li)==NULL){
        (*li) = no;
        (*li)->ant = no;
        (*li)->prox = no;
    }
    else {
        no->prox = (*li);
        no->ant = (*li)->ant;
        (*li)->ant->prox = no;
        (*li)->ant = no;
    }
}


void remover_inicio(Lista* li){
    if(li==NULL||(*li)==NULL) return;
    
    Node *no = (*li);
    if(no->prox==NULL){
        no->prox->ant = NULL;
    }
    no->prox->ant=no->ant;
    no->ant->prox=no->prox;
    (*li) = no->prox;
    
    free(no);
}

void remover_final(Lista* li) {
    if (li == NULL || *li == NULL) return;
    
    Node* no = (*li)->ant;
    
    if (no == *li) {
        free(no);
        (*li) = NULL;
    } else {
        no->ant->prox = (*li);
        (*li)->ant = no->ant;
        free(no);
    }
}