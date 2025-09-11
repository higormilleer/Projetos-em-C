/*Faça um programa que apresente um menu contínuo com as seguintes
opções e execute de acordo com a escolha do usuário.*/

#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_MAXIMO 10

typedef struct no{
    int valor;
    struct no *proximo;
}Node,*Pilha;

int menu()
{
    printf("1-Inicializa pilha.\n");
    printf("2-Verifica se a pilha e vazia.\n");
    printf("3-Verifica se a pilha e cheia.\n");
    printf("4-Empilha o elemento na pilha.\n");
    printf("5-Desempilha elemento da pilha.\n");
    printf("6-Le topo de um pilha.\n");
    printf("7-Converte um numero decimal em binario.\n");
    printf("8-Sair.\n");
}
Pilha* inicializarPilha()
{
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    if(p != NULL)
    {
        *p = NULL;
    }
    return p;
}


int pilhaVazia(Pilha *lista) {
    if (lista!=NULL){
        printf("A pilha esta vazia.\n\n");
    }
    else {
        printf("A pilha nao esta vazia.\n\n");
    }

}

void pilhaCheia(Pilha *lista) {

    int i = 0;
    Node *atual = *lista;

    while (atual != NULL) {
        i++;
        atual = atual->proximo;
    }

    if (i >= TAMANHO_MAXIMO) {
        printf("A pilha esta cheia.\n\n");
    }
    else {
        printf("A pilha nao esta cheia.\n\n");
    }
}

void liberarPilha(Pilha *lista){
    if(lista==NULL)return;
    Node *no;
    while((*lista)!=NULL){
        no=*lista;
        *lista=(*lista)->proximo;
        free(no);
    }
    free(lista);
}


void push(Pilha *lista, int x){

    if(lista == NULL) return;

    Node *novo = (Node*)malloc (sizeof(Node));
    if(novo == NULL) return;

    novo->valor = x;
    novo->proximo = *lista;
    *lista=novo;
}

void pop(Pilha *lista){

    if(*lista == NULL) return;

    Node *remover = *lista;
    *lista = remover->proximo;
    free(remover);
}

void imprimir(Pilha *lista){
    if(lista == NULL || *lista == NULL) return;
    Node *atual = *lista;
    int i = 1;
    while(atual!=NULL){
        printf("Elemento %d: %d |",i,atual->valor);
        atual = atual->proximo;
        i++;
    }
}

void imprimirBin(Pilha *lista){
    Node *atual = *lista;
    int i = 1;
    while(atual!=NULL){
        printf("%d",atual->valor);
        atual = atual->proximo;
        i++;
    }
    printf("\n\n");
}


int lerTopo(Pilha *lista){
    if(lista!=NULL){
        int valorTopo = (*lista)->valor;
        printf("O valor no topo da pilha e: %d\n\n", valorTopo);
    }
    else{
        printf("\nO topo e nulo\n\n");
    }
}

int empilhaNaPilhaBin(Pilha *p, int elemento)
{
    if(p==NULL) return 0;

    Node *node = (Node*)malloc(sizeof(Node));
    if(node == NULL) return 0;

    node->valor = elemento;
    node->proximo = (*p);
    *p = node;

    return 1;
}

void transformarBinario(Pilha *p, int decimal){
    if(decimal > 0){
        empilhaNaPilhaBin(p, decimal%2);
        transformarBinario(p, decimal/2);
    }
}


void execucaoMenu(Pilha *pilha){
    int opcao;

    do {
        menu();
        printf("Digite a opcao: \n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inicializarPilha();
                printf("\nA pilha esta inicializada.\n\n");
                break;

            case 2:
                pilhaVazia(pilha);
                break;

            case 3:
                pilhaCheia(pilha);
                break;

            case 4:;
                int x;
                printf("Digite um numero para ser adicionado: ");
                scanf("%d",&x);
                push(pilha,x);
                printf("\nPilha com os termos inseridos:\n\n");
                imprimir(pilha);
                printf("\n\n");
                break;

            case 5:
                pop(pilha);
                printf("\nPilha com os termos desempilhados:\n\n");
                imprimir(pilha);
                printf("\n\n");
                break;

            case 6:
                lerTopo(pilha);
                break;

            case 7:;
                int decimal;
                printf("Digite um numero decimal: \n");
                scanf("%d", &decimal);
                transformarBinario(pilha,decimal);
                imprimirBin(pilha);
                break;

            case 8:
                printf("Saindo do programa!\n\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n\n");
        }

    } while (opcao != 8);

}

int main()
{
    Pilha *pilha = inicializarPilha();

    execucaoMenu(pilha);
    liberarPilha(pilha);

    return 0;
}

/*
O programa funciona de tal forma que a função executarMenu() exibe o menu e pede para a escolha de qual opcao
deseja ser utilizada, as funcoes padroes de uma pilha sao utilizadas, como o push, pop, monstrar ela vazia, cheia e etc, exceto a
função transformarBinario(), ela recebe como parâmetro um numero decimal e uma pilha,o numero tem que ser maior que 0, caso ele cumpra,
o seu resto por 2 será calculado e sera empilhado, chamando função de novo, mas agora dividindo o numero decimal por 2 */


