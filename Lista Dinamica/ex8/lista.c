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

void imprimirLista(Lista* li)
{
    if(li == NULL || (*li) == NULL)
    {
        return;
    }
    
    Node *no = *li;
    
    while(no != NULL)
    {
        printf(" %d",no->numero);
        no = no->prox;
    }
    return;
}

void inserirLista(Lista *li, int numero)
{
    if(li==NULL){
        return;
    }
    
    Node *no = (Node*)malloc(sizeof(Node));
    if(no == NULL)
        return;
        
        no->numero=numero;
        no->prox=NULL;
        
        if((*li)==NULL){
            *li=no;
        }
        else{
            Node *aux = *li;
            
            while(aux->prox!=NULL){
                aux = aux->prox;
            }
            aux->prox=no;
        }
        return;
    
}

void ordenadaLista(Lista* l1, Lista* l2) {
    if (*l2 == NULL) {
        return;  
    }
    if (*l1 == NULL) {
        *l1 = *l2;  
        *l2 = NULL;  
        return;
    }
    
    Node* cabeca;
    if((*l1)->numero > (*l2)->numero)
        cabeca = (*l2);

    else
        cabeca = (*l1);
    
    while((*l1)!=NULL && (*l2)!=NULL)
    {
        if((*l1)->prox == NULL)
        {
            (*l1)->prox = (*l2);
            break;
        }

        if((*l2)->prox == NULL)
        {
            (*l2)->prox = (*l1);
            break;
        }

        if((*l2)->numero >= (*l1)->numero)
        {
            if((*l1)->prox->numero >= (*l2)->numero)
            {
                Node *aux = (*l2) ;
                (*l2) = (*l2)->prox;
                aux->prox = (*l1)->prox;
                (*l1)->prox = aux;
                (*l1) = aux;
            }
            else
                (*l1) = (*l1)->prox;
        }
        else {
            if((*l2)->prox->numero >= (*l1)->numero)
            {
                Node *aux = (*l1);
                (*l1) = (*l1)->prox;
                aux->prox = (*l2)->prox;
                (*l2) ->prox = aux;
                (*l2) = aux;
            }
            else
                (*l2) = (*l2)->prox;
        }
    }
    
    (*l1) = cabeca;
    l2 = NULL;
}