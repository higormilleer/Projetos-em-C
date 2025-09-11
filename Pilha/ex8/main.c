/*Faça um programa para determinar se uma cadeia de caracteres (string)
é da forma:
x C y
onde x e y são cadeias de caracteres compostas por letras ‘A’ e/ou ‘B’, e y é
o inverso de x. Isto é, se x = “ABABBA”, y deve equivaler a “BABAAB”. Em
cada ponto, você só poderá ler o próximo caractere da cadeia.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char letra;
    struct node *proximo;
} Node, *Pilha;

Pilha* criarPilha()
{
    Pilha *p = (Pilha*)malloc(sizeof(Node));
    if(p!=NULL)
        *p = NULL;
        
    return p;
}
//cria pilha vazia

void liberarPilha(Pilha *p)
{
    if(p!=NULL)
    {
        Node *node;
        while((*p) != NULL)
        {
            node = *p;
            (*p) = (*p) -> proximo;
            free(node);
        }
        free(p);
    }
}
//libera espaco alocado na Pilha

int lenghtS(char *s)
{
    int tamanho = 0;
    while((*s) != '\0'){
        tamanho++;
        s++;
    }
    return tamanho;
}
//desobre o tamanho da string

void push(Pilha *pilha, int num, char *str){
    if(pilha==NULL) return;
    int n = num;
    for(int i=0;i<n;i++){
        Node *novo = (Node*)malloc(sizeof(Node));
        
        novo->letra = str[i];
        novo->proximo = *pilha;
        *pilha = novo;
    }
    return;
}
//aloca dinamicamente o tamanho da pilha de acordo com o numero de caracteres digitados

int inverso(char *str1, char *str2){
    
    Pilha *pilha1 = criarPilha();
    Pilha *pilha2 = criarPilha();
    
    int tamStr = lenghtS(str1);
    int tamStr2 = lenghtS(str2);
    
    if(tamStr!=tamStr2){
        printf("Eles nao sao iguais");
        return 0;
    }
    
    push(pilha1,tamStr,str1);
    push(pilha2,tamStr2,str2);
    
    Node *string1 = *pilha1;
    Node *string2 = *pilha2;
    
    for(int i=0;i<tamStr;i++){
        if((string1)->letra == (string2)->letra){
            printf("Nao estao no padrao x C y");
            liberarPilha(pilha1);
            liberarPilha(pilha2);
            return 0;
        }
        string1 = string1->proximo;
        string2 = string2->proximo;
    }
    
    printf("Estao no padrao x C y");
    liberarPilha(pilha1);
    liberarPilha(pilha2);
    return 0;
    
}
//cria duas pilhas e descobre o tamanho de cada uma, depois percorremos as duas strings, quando as duas forem iguais, o looping acaba, ja que as duas nao estao no padrao
int main(){
    char palavra1[20];
    char palavra2[20];
    
    printf("Digite uma a primeira palavra (compostas por letras ‘A’ e/ou ‘B’): ");
    scanf("%[^\n]",palavra1);
    printf("Digite uma a segunda palavra (compostas por letras ‘A’ e/ou ‘B’): ");
    scanf(" %[^\n]",palavra2);
    
    inverso(palavra1,palavra2);
    return 0;
    
}

/*Criamos duas pilhas, uma com cada palavra digitada, descobrimos o tamanho de ambas, caso o tamanho for diferente, imprime a mensagem dizendo que nao sao iguais, depois 
e empilhado os valores em ambas pilhas (apenas com as letras A e B) e as mesmas igualadas a uma variavel Node para poder ser utilziada dentro da funcao, o laco de repeticao percorre o tamanho da strings e
caso eles forem iguais em algum momento, nao estao no padrao  x C y, caso forem difentes durante a pilha,estao no padrao  x C y*/

