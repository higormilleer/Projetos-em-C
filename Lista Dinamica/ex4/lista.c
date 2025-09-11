#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

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

Lista* criarLista()
{
    Lista *li = (Lista*)malloc(sizeof(Lista));
    if(li != NULL)
    {
        *li = NULL;
    }
    return li;
}


void imprimirLista(Lista *li)
{
    if(li==NULL||*li==NULL) return;
    
    Node *no = *li;
    while(no!=NULL){
        printf(" %.2f",no->numero);
        no = no->prox;
    }
    return;
}

int inserirLista(Lista *li, float numero)
{
    if(li==NULL);
    
    Node* no = (Node*)malloc(sizeof(Node));
    if(no==NULL)return 0;
    
    no->prox=NULL;
    no->numero = numero;
    
    if((*li)==NULL){
        *li=no;
    }
    else{
        Node* aux= *li;
        while(aux->prox!=NULL){
            aux=aux->prox;
        }
        aux->prox=no;
    }
  return 1;  
}
