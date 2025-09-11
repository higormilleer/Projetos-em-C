#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

No* inserir(No *inicio, int x){
    No *novo = malloc(sizeof(No)); //descobrir o tamanho do No e mandar para o *novo
    if(novo){ //caso nao for nulo
        novo->valor = x; //quero inserir o x
        novo->proximo = inicio; //proximo vai apontar para o inicio atual
    }
    else{
        printf("Pilha vazia");
    }
    return novo;
}

/*void inserir2(No **inicio, int x){
    No *novo = malloc(sizeof(No)); //descobrir o tamanho do No e mandar para o *novo
    if(novo){ //caso nao for nulo
        novo->valor = x; //quero inserir o x
        novo->proximo = *inicio; //proximo vai apontar para o conteudo do inicio da lista, no caso a *lista da main
        *inicio = novo; //atualiza a lista por conta que a lista vai receber o endereço do novo no
    }
    else{
        printf("Pilha vazia");
    }
}*/

No* desempilhar(No **lista){

    if(*lista){
        No *remover = *lista;
        *lista = remover ->proximo;
        return remover;
    }
    
    else{
    printf("Pilha vazia");
    }
}


void imprimir(No *inicio){
    if(inicio){
        printf("%d ", inicio->valor); //seta pq tem um ponteiro para o no, nao e o proprio no
        imprimir(inicio->proximo);//passando o proximo ate que vai ser nulo, onde o if e falso e o procedimento finaliza
    }
    else{
        printf("pilha vazia");
    }
}  

int main()
{
    No *lista = NULL; //no inicio a lista e nula
    
    lista = inserir(lista, 10);
    lista = inserir(lista, 50);
    lista = inserir(lista, 100);
    
    /*inserir2(&lista, 17);
    inserir2(&lista, 57);
    inserir2(&lista, 107);*/
    
    imprimir(lista);
    
    printf("\n");
    No* remover = desempilhar(&lista);
    if(remover){
        imprimir(lista);
        free(remover);
    }
    else{
        printf("Nao foi removido nada");
    }
    
    return 0;
}


