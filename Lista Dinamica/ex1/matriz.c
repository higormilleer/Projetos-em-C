#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Aluno consultaAl(Lista* li, int mat)
{
    if(li == NULL)
        exit(1);
        
    if((*li) == NULL)
        exit(1);
        
    Node *ant, *no = *li;
    
    while(no->prox != NULL && no->dados.matricula != mat){ /* inteiro enquanto o proximo dele nao ser nulo ate a matricula do no forem diferentes da matricula desejada*/
        ant = no; /*o ant e declarado como igual ao no*/
        no = no->prox;/*o no passa passa para o seu proximo, assim deixando o ant anterior a ele*/
    }
    
    if(no == NULL)
        exit(1);

    return no->dados;
}

Aluno posicaoAL(Lista* li, int posicao)
{
    
    if(li == NULL)
        exit(1);
        
    if((*li) == NULL)
        exit(1);
        
    Node *no = *li;
    int poze = 0;
    
    while(no->prox != NULL && poze != posicao){ /*percorre o no inteiro enquanto o proximo dele nao ser nulo ate a poze ser diferente da posicao desejada  */
        no = no->prox; /*passa para oproximo do no, assim percorrendo ele inteiro*/
        poze++; /*concatenacao no valor do poze*/
    }
    
    if(no == NULL)
        exit(1);

    return no->dados;
}

Lista * criarLista()
{
    Lista *li = (Lista*)malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    
    return li;
}

void libera_lista(Lista *li)
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
