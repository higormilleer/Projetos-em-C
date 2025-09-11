#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"


Arvore* criaArvBin()
{
    Arvore *raiz = (Arvore*)malloc(sizeof(Arvore));
    if(raiz !=  NULL)
        *raiz = NULL;
    return raiz;
}

void liberaNo(Node *no)
{
    if(no == NULL)
        return;
    
    liberaNo(no->esq);
    liberaNo(no->dir);
    free(no);
    no = NULL;
}

void liberaArvore(Arvore *raiz)
{
    if(raiz == NULL)
        return;
    liberaNo(*raiz);
    free(raiz);
}

Node* removeAtual(Node *atual) 
{
    Node *no1, *no2;
    if(atual->esq == NULL)
    {
        no2 = atual->dir;
        free(atual);
        return no2; 
    }
    
    no1 = atual;
    no2 = atual->esq;
    
    while(no2->dir != NULL)
    {
        no1 = no2; 
        no2 = no2->dir; 
    }
    
    if(no1 != atual)
    {
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

int insereArvore(Arvore *raiz, int valor)
{
    if(raiz == NULL)
        return 0;
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo == NULL)
        return 0;
    
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;
    
    if(*raiz == NULL)
        *raiz = novo;
    else
    {
        Node *atual = *raiz;
        Node *ant = NULL;
        
        while(atual != NULL)
        {
            ant = atual;
            if(valor == atual->info)
            {
                free(novo);
                return 0; 
            }
            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    
    return 1;
}

void preOrdemArvore(Arvore *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL)
    {
        printf("%d ", (*raiz)->info);
        preOrdemArvore(&((*raiz)->esq));
        preOrdemArvore(&((*raiz)->dir)); 
    }
}

void removePar(Arvore *raiz ,Node *cabeca)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL)
    {   
        
        removePar(&((*raiz)->esq), cabeca);
        removePar(&((*raiz)->dir), cabeca);
        if((*raiz)->info % 2 == 0){
            Node *atual = (*raiz);
            (*raiz) = removeAtual(atual);
        }
    }
}
