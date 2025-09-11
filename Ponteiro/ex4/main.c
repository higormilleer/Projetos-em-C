/*Crie um vetor V com n inteiros, onde n é um valor inteiro fornecido pelo
usuário. O vetor só deve ser alocado dinamicamente na memória depois que
o usuário fornecer o valor de n.*/

#include <stdio.h>
#include <stdlib.h>

int* alocacao(int num){
    return (int*)malloc(num*sizeof(int));
}
int main()
{
    int n;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    
    int *v = alocacao(num);
    
    for(int i=0;i<num;i++){
        printf("Digite os valores dos vetores %d: ",i+1);
        scanf("%d",&v[i]);
    }
    
    printf("Valores do vetor: ");
    for(int i = 0; i < num; i++) {
        printf("%d ", v[i]);
    }
    
    free(vet);
    return 0;
}

/*no main, o primeiro print pede qual o tamanho do vetor desejado, apos isso, e chamada a funcao alocacao,onde la ocorre a alocacao dinamica do tamanho do vetor 
que foi inserido anteriormente. Voltando para o main, o for pede para preencher os valores do vetor e armazena eles em v, o proximo for imprime os valores
que foi digitado para cada vetor sucessivamente*/



