/*Faça uma função recursiva que receba um número inteiro
positivo par N e imprima todos os números pares de 0 até N em
ordem decrescente.*/

#include <stdio.h>

int Par(int num){
    if(num<0)
    {
        return 0;   //O numero nao pode ser negativo
    }
    
    else
    {
        
        if(num % 2 == 0)
        {
            printf("%d ", num);     //Todos os numeros que o restante de 2 for 0, é par
        }
        return Par(num - 1);    //Verifica se num - 1 é par atraves da recursividade
    }
}

int main()
{
    int num;
    
    printf("Digite um numero par inteiro: ");
    scanf("%d", &num);
    
    Par(num);

    return 0;
}

