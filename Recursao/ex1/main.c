
#include <stdio.h>



int Inverte(int num)
{
        
    if(num==0)
    {
        return 0;
    }
        
    else
    {
        printf("%d", num %10); //printa o ultimo numero 
        return inverte(num/10); //divide o numero por 10(retirando o ultimo numero), e resolve de modo recursivo
    }
    
}
    
int main()
{
    int num;
        
    printf("Digite um numero: ");
    scanf("%d", &num);
        
    Inverte(num);
       
    return 0;
}



