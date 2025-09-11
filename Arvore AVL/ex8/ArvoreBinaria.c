#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

ArvBin* criaArvBin()
{
    ArvBin *raiz = (ArvBin*)malloc(sizeof(ArvBin));
    if(raiz !=  NULL)
        *raiz = NULL;
    return raiz;
}

void liberaNo(No *no)
{
    if(no == NULL)
        return;
    
    liberaNo(no->esq);
    liberaNo(no->dir);
    free(no);
    no = NULL;
}

void liberaArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;
    liberaNo(*raiz);
    free(raiz);
}

int insereArvBin(ArvBin *raiz, int valor)
{
    if(raiz == NULL)
        return 0;
    No *novo = (No*)malloc(sizeof(No));
    if(novo == NULL)
        return 0;
    
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;
    
    if(*raiz == NULL)
        *raiz = novo;
    else
    {
        No *atual = *raiz;
        No *ant = NULL;
        
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

void preOrdemArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL)
    {
        printf("%d ", (*raiz)->info);
        preOrdemArvBin(&((*raiz)->esq));
        preOrdemArvBin(&((*raiz)->dir)); 
    }
}

