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

int insereArvore(Arvore *raiz, char valor) {
    if (raiz == NULL)
        return 0;

    Node *novo = (Node*)malloc(sizeof(Node));
    if (novo == NULL)
        return 0;

    novo->info = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    if (*raiz == NULL) {
        *raiz = novo;
    } else {
        Node *atual = *raiz;
        Node *ant = NULL;

        while (atual != NULL) {
            ant = atual;
            if (valor < atual->info)
                atual = atual->esq;
            else if (valor > atual->info)
                atual = atual->dir;
            else {
                free(novo);
                return 0;
            }
        }

        if (valor < ant->info)
            ant->esq = novo;
        else
            ant->dir = novo;
    }

    return 1;
}

void preOrdemArvore(Arvore *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL)
    {
        printf("%c ", (*raiz)->info);
        preOrdemArvore(&((*raiz)->esq));
        preOrdemArvore(&((*raiz)->dir)); 
    }
}

void ordemLetra(Arvore *raiz) {
    if (raiz == NULL) {
        return;
    }

    Node** fila = (Node**)malloc(sizeof(Node*) * 100);
    int i = 0, j = 0;
    fila[j++] = *raiz;

    while (i < j) {
        Node* atual = fila[i++];

        printf("%c ", atual->info);
        
        if (atual->esq != NULL) {
            fila[j++] = atual->esq;
        }

        if (atual->dir != NULL) {
            fila[j++] = atual->dir;
        }
    }

    free(fila);
}
