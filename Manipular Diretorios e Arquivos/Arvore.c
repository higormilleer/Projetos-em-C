#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"


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

void imprimirDec(Arvore *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL)
    {
        if((*raiz)->esq == NULL && (*raiz)->dir ==  NULL){
            printf("%d ", (*raiz)->info);
        }
        else{
            imprimirDec(&((*raiz)->esq));
            imprimirDec(&((*raiz)->dir));
        }
    
    }
}
