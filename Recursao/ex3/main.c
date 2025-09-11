/*Crie uma função recursiva que receba um número inteiro
positivo N e calcule o somatório dos números de 1 a N.
*/

#include <stdio.h>

int Soma(int n){
    
    if(n==0)
    {
        return 0;
    }
    
    else
    {
        return Soma(n-1)+n; //valor do n somado a soma de (n-1)
    }
    return 0;
}

int main()
{
    int n;
    
    printf("Digite um numero inteiro: ");
    scanf("%d",&n);
    
    printf("%d",Soma(n));
    
    return 0;
}

