/*
Crie um programa em C, que contenha uma função recursiva
que receba dois inteiros positivos k e n e calcule kn. Utilize
apenas multiplicações. O programa principal deve solicitar ao
usuário os valores de k e n e imprimir o resultado da chamada
da função
*/

#include <stdio.h>

int Mult(int n, int k)
{
    if(k == 0)
    {
        return 0;
    }
    
    else
    {
        return n + Mult(n, k-1); //soma o n com a multiplicação de n com k-1
    }
}

int main()
{
    int n,k;
    
    printf("Digite um valor para n: ");
    scanf("%d",&n);
    
    printf("Digite um valor para k: ");
    scanf("%d",&k);

    printf("%d",Mult(n,k));
    
    return 0;
}

