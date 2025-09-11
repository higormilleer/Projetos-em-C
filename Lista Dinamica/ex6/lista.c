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

int insereLista(Lista *li, int numero)
{
    if(li == NULL)
        return 0;
        
    Node *no;
    no = (Node*)malloc(sizeof(Node));
    if(no == NULL)
        return 0;
    
    no->numero = numero;
    no->prox = NULL;
    
    if((*li) == NULL)
    {
        *li = no;
    }
    else
    {
        Node *aux = *li;
        
        while(aux->prox != NULL)
            aux = aux->prox;
        
        aux->prox = no;
    }
    return 1;
}

void imprimir(Lista* li)
{
    if(li == NULL || (*li) == NULL)
    {
        return;
    }
    
    Node *no = *li;
    
    while(no != NULL)
    {
        printf("%d",no->numero);
        no = no->prox;
    }
    return;
}

void concatenar(Lista *l1, Lista *l2)
{
    if(l1 == NULL || (*l1) == NULL)
    {
        return;
    }
    
    if(l2 == NULL || (*l2) == NULL)
    {
        return;
    }
    
    if(*l1 == NULL){
        *l1=*l2;
    }
    else{
        Node *aux = *l1;
        while(aux->prox!=NULL){
            aux=aux->prox;
        }
        aux->prox=*l2;
    }
}