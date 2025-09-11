/*Faça um programa que implemente uma calculadora, contendo as
operações básicas (+, -, *, /)*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}Node, *Pilha;

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
//liberar pilha alocada

Pilha* criarPilha()
{
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    if(p != NULL)
    {
        *p = NULL;
    }
    return p;
}
//criar pilha vazia

void push(Pilha *pilha,int x){
    if(pilha==NULL) return;
    
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo==NULL) return;
    novo->valor=x;
    novo->proximo = *pilha;
    *pilha=novo;
}
//empilhar um elemento na Pilha

void pop(Pilha *pilha){
    if(pilha==NULL) return;
    Node *temp = *pilha;
    *pilha = temp->proximo;
    free(temp);
}
//desempilhar um elemento na Pilha

int soma(Pilha *p){
    if(*p == NULL || (*p)->proximo == NULL) return 4;
    
    (*p)->proximo->valor += (*p)->valor;
    pop(p);
    return 0;
}
//usado para descobrir a soma dos elementos

int subtracao(Pilha *p){
    if(*p == NULL || (*p)->proximo == NULL) return 3;
    (*p)->proximo->valor -= (*p)->valor;
    pop(p);
    return 0;

}
//usado para descobrir a subtracao dos elementos

int multiplicacao(Pilha *p){
    if(*p == NULL || (*p)->proximo == NULL) return 2;
    (*p)->proximo->valor *= (*p)->valor;
    pop(p);
    return 0;
}
//usado para descobrir a multiplicacao dos elementos

int divisao(Pilha *p){
    if(*p == NULL || (*p)->proximo == NULL) return 1; 
    
    if((*p)->valor == 0) 
    {
        pop(p);
        pop(p);
        
        return 5;
    }
    
    (*p)->proximo->valor /= (*p)->valor;
    pop(p);
    return 0;
}
//usado para descobrir a divisao dos elementos

int calculadora(Pilha *p){
    
    printf("Divisao por 0 encerra o codigo");
    while(1){
        
        int segundoNum;
        char operacaoMat;
        
        printf("\nDigite qual operacao deseja utilizar(+  -  *  /): ");
        scanf(" %c",&operacaoMat);
        
        if(*p==NULL){
            int primeiroNum;
            printf("Digite o primeiro numero: ");
            scanf("%d", &primeiroNum);
            push(p, primeiroNum);
        }
        
        printf("Digite o segundo numero: ");
        scanf("%d",&segundoNum);
        push(p, segundoNum);
        
    
        switch(operacaoMat){
            case('+'):
            soma(p);
            break;
            
            case('-'):
            subtracao(p);
            break;
            
            case('*'):
            multiplicacao(p);
            break;
            
            case('/'):
            divisao(p);
            break;
            
            default:
            printf("\nValor invalido");
            scanf("%c",&operacaoMat);
        }
        printf("\nresultado: %d \n", (*p)->valor);
    }
}
//pergunta qual a operacao matematica deseja utilizar e os dois elementos, depois efetua a operacao chamando cada funcao no switch quando necessario

int main()
{
   Pilha *pilha = criarPilha();
   
   calculadora(pilha);
   
   liberarPilha(pilha);

    return 0;
}

/*a funcao soma, divisao, subtracao e multiplicacao sao usadas para efetuar as opercoes matematicas comuns. Ja na funcao calculadora, pede qual das operacoes anteriores deseja utilziar e quais
os dois numeros deseja, assim empilhando ambos na pilha, depois entra no switch case, onde cada case e uma operacao chamando as funcoes desejadas para calcular, caso for a soma por exemplo,
o topo da pilha(segundo valor), e somado ao primeiro, onde caso o primeiro for 5 e for somado com 6, o primeiro elemento da pilha se torna o 11, enquanto o segundo continua sendo o 6,
assim, conseguimos eliminar o segundo termo e continuar apenas com o primeiro, depois voltando ao looping, porem agora ja com o primeiro termo empilhado, pedindo apenas qual a opecao e qual 
o segundon termo que deseja ser empilhado para efetuar a operacao matematica*/
