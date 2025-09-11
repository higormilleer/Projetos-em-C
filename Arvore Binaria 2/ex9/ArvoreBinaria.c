#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"


Arvore* criaArvBin()
{
    Arvore *raiz = (Arvore*)malloc(sizeof(Arvore));
    if(raiz != NULL)
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
}

void liberaArvore(Arvore *raiz)
{
    if(raiz == NULL)
        return;
    liberaNo(*raiz);
    free(raiz);
}

Node* criarNode(char info)
{
    Node *no = (Node*)malloc(sizeof(Node));
    if(no == NULL)
        return NULL;
    
    no->info = info;
    no->esq = NULL;
    no->dir = NULL;
    
    return no;
}

int calcularResultado(Arvore *raiz)
{
    if(raiz == NULL || *raiz == NULL)
        return 0;
    
    if((*raiz)->esq == NULL && (*raiz)->dir == NULL)
        return (*raiz)->info - '0'; 
        
    int esq = calcularResultado(&((*raiz)->esq));
    int dir = calcularResultado(&((*raiz)->dir));
    
    switch((*raiz)->info)
    {
        case '+':
            return esq + dir;
        case '*':
            return esq * dir;
        case '-':
            return esq - dir;
    }
    return 0;
}

void imprimeInfixa(Arvore *raiz)
{
    if(raiz == NULL || *raiz == NULL)
        return;
    if((*raiz)->esq != NULL || (*raiz)->dir != NULL)
        printf("(");
        
    imprimeInfixa(&((*raiz)->esq));
    
    printf("%c", (*raiz)->info);
        
    imprimeInfixa(&((*raiz)->dir));
    
    if((*raiz)->esq != NULL || (*raiz)->dir != NULL)
        printf(")");
}

void imprimePrefixa(Arvore *raiz)
{
    if(raiz == NULL || *raiz == NULL)
        return;
    
    if((*raiz)->esq != NULL || (*raiz)->dir != NULL)
        printf("(");
    printf("%c", (*raiz)->info);
    
    imprimePrefixa(&((*raiz)->esq));
    imprimePrefixa(&((*raiz)->dir));
    if((*raiz)->esq != NULL || (*raiz)->dir != NULL)
        printf(")");
}

void imprimePosfixa(Arvore *raiz)
{
    if(raiz == NULL || *raiz == NULL)
        return;
    if((*raiz)->esq != NULL || (*raiz)->dir != NULL)
        printf("(");
        
    imprimePosfixa(&((*raiz)->esq));
    imprimePosfixa(&((*raiz)->dir));
        
    printf("%c", (*raiz)->info);
    if((*raiz)->esq != NULL || (*raiz)->dir != NULL)
        printf(")");
}

Arvore* criaArvoreCalculo()
{
    Arvore *nova = criaArvBin();
    Node *raiz = criarNode('+');
    
    raiz->esq = criarNode('*');
    raiz->dir = criarNode('5');
    
    raiz->esq->esq = criarNode('-');
    raiz->esq->dir = criarNode('+');
    
    raiz->esq->esq->esq = criarNode('6');
    raiz->esq->esq->dir = criarNode('3');
    
    raiz->esq->dir->esq = criarNode('4');
    raiz->esq->dir->dir = criarNode('1');
    
    *nova = raiz;
    return nova;
}
