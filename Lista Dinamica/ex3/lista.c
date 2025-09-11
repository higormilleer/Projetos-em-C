#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* criarPilha(){
    Lista *li= (Lista*)malloc(sizeof(Lista));
    if(li!=NULL) {
        *li == NULL;
    }
    return li;
}

void inserirLista(Lista* li, int numero, int posicao){
    if(li==NULL) return;
    
    Node* no = (Node*)malloc(sizeof(Node));
    if(no==NULL)return;
    
    no->numero = numero;
    no->prox=NULL;
    
    if((*li)==NULL){
        *li = no;
    }
    else{
        Node *ant;
        Node *aux = *li;
        int poze = 0;
        while(poze!=posicao && aux!=NULL){
            ant = aux;
            aux = aux->prox;
            poze++;
        }
        ant->prox = no;
        no->prox=aux;
    }
    if(no==NULL){
        free(no);
    }
    return;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Node* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

void imprimir(Lista *li){
    if(li==NULL||(*li)==NULL) return;
    
    Node* no = *li;
    
    while(no!=NULL){
        printf("%d",no->numero);
        printf("\n");
        no=no->prox;
    }
    return;
}
