/*Escreva uma função recursiva que determine quantas vezes um
dígito K ocorre em um número natural N. Por exemplo, o dígito
2 ocorre 3 vezes em 762021192.*/

#include <stdio.h>


int Contar(int numCompleto,int numContar){
    if(numCompleto==0)
    {
        return 0;
    }
    
    if(numCompleto%10==numContar)   //Verifica se ultimo numero completo coincide com o numero de verificacao
    {
        return 1 + Contar(numCompleto/10,numContar);    //Caso o numero se repetir, ele soma 1 e retorna a funcao Contar sem o ultimo numero
    }
    
    else
    {
        return Contar(numCompleto/10,numContar);    //Caso o ultimo numero nao coincidir com o numero de verificação ele retorna a funcao Contar sem o ultimo numero
    }
}

int main()
{
    int numCompleto,numContar;
    
    printf("Digite um numero: ");
    scanf("%d",&numCompleto);
    
    printf("Digite um numero para contar: ");
    scanf("%d",&numContar);
    
    printf("%d", Contar(numCompleto,numContar));

    return 0;
}


