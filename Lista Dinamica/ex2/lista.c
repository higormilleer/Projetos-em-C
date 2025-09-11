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

int remove_lista(Lista* li, int dado){
    if(li == NULL)
        return 0;
    if((*li) == NULL)
        return 0;

    
    if((*li)->dados.matricula == dado){
        
        Node *no = *li;
        *li = (*li)->prox;
        
        free(no);
        
        return 1;
    }
    
    return remove_lista((&(*li)->prox), dado);
}

int comparacao(Lista *l1, Lista *l2)
{
    if(l1 == NULL || l2 == NULL)
        return 0;
    if((*l1) == NULL || (*l2) == NULL)
        return 0;
        
    if((*l1)->dados.matricula != (*l2)->dados.matricula)
    {
        return 0;
    }
    
    if((*l1)->prox == NULL && (*l2)->prox == NULL )
    {
        return 1;
    }
        
    return comparacao(&(*l1)->prox,&(*l2)->prox);    
        
}

Lista * criarLista()
{
    Lista *li = (Lista*)malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    
    return li;
}

void liberarLista(Lista *li)
{
    if(li != NULL)
    {
        Node *no;
        while((*li) != NULL)
        {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
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