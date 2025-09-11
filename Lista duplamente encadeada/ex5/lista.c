#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int inicializa_noDesc(noDesc *no)
{
    *no = (noDesc)malloc(sizeof(struct nodesc));
    
    if (!(*no))
        return 0;
    
    (*no)->ini = NULL;
    (*no)->fim = NULL;
    
    return 1;
}

int enfileirar(noDesc *no, int elem)
{
    if (!(*no))
        return 0;
    
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    if (fila == NULL)
        return 0;
    
    fila->info = elem;
    fila->prox = NULL;
    
    if ((*no)->fim == NULL)
    {
        (*no)->ini = fila;
        (*no)->fim = fila;
    }
    else
    {
        (*no)->fim->prox = fila;
        (*no)->fim = fila;
    }
    
    return 1;
}

int desenfileirar(noDesc *no, int *elem)
{
    if (no == NULL || (*no)->ini == NULL)
        return 0;
    
    Fila *f = (*no)->ini;
    *elem = f->info;
    
    if ((*no)->ini == (*no)->fim)
    {
        (*no)->ini = NULL;
        (*no)->fim = NULL;
    }
    else
    {
        (*no)->ini = (*no)->ini->prox;
    }
    
    free(f);
    
    return 1;
}

void imprimirNoDesc(noDesc *no)
{
    if (no != NULL && (*no)->ini != NULL)
    {
        Fila *f = (*no)->ini;
        int i = 1;
        while (f != NULL)
        {
            printf("Numero: %d\n", f->info);
            i++;
            f = f->prox;
        }
    }
}

int liberarNoDesc(noDesc *no)
{
    if ((*no))
    {
        if ((*no)->ini != NULL)
        {
            Fila *f = (*no)->ini;
            Fila *temp;
            
            while (f != NULL)
            {
                temp = f;
                f = f->prox;
                free(temp);
            }
            
            (*no)->ini = NULL;
            (*no)->fim = NULL;
        }
        
        free(*no);
        *no = NULL;
    }
    return 1;
}