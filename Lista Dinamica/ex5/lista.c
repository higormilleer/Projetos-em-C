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
    if(li!=NULL)
    {
        *li= NULL;        
    }
    
    return li;
}

int insereLista(Lista *li, Aluno al)
{
    if(li == NULL)
        return 0;
        
    Node *no;
    no = (Node*)malloc(sizeof(Node));
    if(no == NULL)
        return 0;
    
    no->dados = al;
    no->prox = NULL;
    
    if((*li) == NULL)
    {
        *li = no;
    }
    else
    {
        Node *aux;
        aux = *li;
        
        while(aux->prox != NULL)
            aux = aux->prox;
        
        aux->prox = no;
    }
    return 1;
}

int imprimir_lista(Lista *li)
{
    if(li == NULL || (*li)==NULL)
        return 0;
        
    Node *no = *li;
    
    while(no != NULL)
    {
        printf("%d - %s \n",no->dados.matricula, no->dados.nome);
        
        no = no->prox;
    }
        
    return 2;
}

int percorra(Lista *li, int remover)
{
    if(li == NULL || (*li) == NULL)
        return 0;
    
    Node *atual = *li;
    Node *anterior = NULL;
    
    while (atual != NULL)
    {
        if (atual->dados.matricula == remover)
        {
            if (anterior == NULL) 
            {
                *li = atual->prox;
            }
            else
            {
                anterior->prox = atual->prox;
            }
            
            Node *temp = atual;
            atual = atual->prox;
            free(temp);
    
        }
        else
        {
            anterior = atual;
            atual = atual->prox;
        }
    }
}