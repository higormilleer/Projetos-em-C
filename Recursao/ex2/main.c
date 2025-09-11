#include <stdio.h>
#include <stdlib.h>

int Soma(int vet[], int tam) 
{

    if (tam == 0) 
    {
        return 0;
    }
    
    else
    {
    return vet[tam - 1] + Soma(vet, tam - 1); //  soma o último elemento com os elementos restantes
    }
    
}

int main() {
    int tam;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d",&tam);
    
    int *vet = (int *)malloc(tam * sizeof(int)); //Aloca dinamicamente o tamanho do vetor desejado
  
    for(int i = 0; i < tam; i++)
    {
        printf("Digite o numero do vetor %d: ", i + 1); //Preenche os vetores
        scanf("%d", &vet[i]);
    }
   
    printf("%d\n", Soma(vet, tam));
    
    free(vet); 
    
    return 0;
}
