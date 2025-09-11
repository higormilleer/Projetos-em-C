/*A função fatorial duplo é definida como o produto de todos os
números naturais ímpares de 1 até algum número natural ímpar
N. Assim, o fatorial duplo de 5 é 5!! = 1 * 3 * 5 = 15 Faça uma
função recursiva que receba um número inteiro positivo impar N
e retorne o fatorial duplo desse número*/

#include <stdio.h>

int FatorialDuplo(int n){
    if(n==1)
    {
        return 1;
    }
    
    if(n%2!=0) //Verifica se o numero e impar
    {
        return n * FatorialDuplo(n-2);  //Multiplica o numero com o restante - 2(para continuar impar)
    }
    
}
int main()
{
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    
    printf("%d",FatorialDuplo(n));

    return 0;
}

