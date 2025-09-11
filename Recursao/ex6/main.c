/*) O máximo divisor comum dos inteiros x e y é o maior inteiro que
é divisível por x e y. Escreva uma função recursiva mdc em C,
que retorna o máximo divisor comum de x e y. O mdc de x e y é
definido como segue: se y é igual a 0, então mdc(x,y) é x; caso
contrário, mdc(x,y) é mdc (y, x%y), onde % é o operador resto.*/

#include <stdio.h>

int mdc(int x, int y)
{
    if(y==0)
    {
        return x; //quando y é igual a 0, o valor retorna sendo x
    }    
    
    else
    {
        return mdc(y,x%y); //caso contrario o mdc e x resto y
    }

}

int main()
{
    int x,y;
    
    printf("Digite o valor de x: ");
    scanf("%d",&x);
    
    printf("Digite o valor de y: ");
    scanf("%d",&y);
    
    printf("%d", mdc(x,y));

    return 0;
}


