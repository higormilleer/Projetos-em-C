/*Crie um programa em C que receba um vetor de números reais
com 100 elementos. Escreva uma função recursiva que inverta
ordem dos elementos presentes no vetor.*/

#include <stdio.h>

int inverte(int vet[], int tam){
    if(tam==0){
        return 0;
    }
    
    else{
        printf("%d, ",vet[tam - 1]); //Imprime o ultimo nummero, punultimo e assim sucessivamente
        return inverte(vet,tam - 1); //Chama a funcao recursivamente decrementando a variavel tam
    }
}

int main()
{
    int tam =100;
    int vet[tam];
    
    for(int i=0;i<tam;i++){
        printf("Digite os numeros do vetor: ");
        scanf("%d",&vet[i]);
    }
    
    inverte(vet, tam);

    return 0;
}






