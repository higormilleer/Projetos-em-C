#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* criarLista()
{
    Lista *li = (Lista*)malloc(sizeof(Lista));
    if(li != NULL)
    {
        *li = NULL;
    }
    return li;
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

void imprimirLista(Lista *li)
{
    if(li==NULL||*li==NULL) return;
    
    Node *no = *li;
    while(no!=NULL){
        printf("%d", no->numero);
        no = no->prox;
    }
    return;
}

void inserirLista(Lista *li, int numero){
    if(li==NULL) return;
    
    Node *no = (Node*)malloc(sizeof(Node));
    if(no==NULL) return;
    
    no->prox = NULL;
    no->numero = numero;
    
    if((*li)==NULL){
        *li=no;
    }
    else
    {
        Node *aux = *li;
        while(aux->prox!=NULL)
        {
            aux = aux->prox;
        }
        aux->prox=no;
     }  
    return;
}

int remove_lista(Lista* li){
    if(li==NULL||*li==NULL) return 0;
    
    Node *no = (*li);
    
    while(no!=NULL)
    {
        Node *ant = no;
        Node *aux = no->prox;
        while(aux!=NULL)
        {
            if(no->numero == aux->numero)
            {
                Node *temp = aux;
                ant->prox = aux->prox;
                aux = aux->prox;
                free(temp);
            }
            else{
                ant = aux;
                aux = aux->prox;
            }
        }
        no = no->prox;
    }
    return 1;
}