/*Construa um programa (main) que aloque dinamicamente uma matriz de
ordem m x n (linha por coluna) e preencha ela usando 1+m chamadas a
função malloc. Em seguida imprima os valores da matriz e libere a área de
memória alocada por essa.*/
#include <stdio.h>
#include <stdlib.h>

int** alocacaoLinhas(int m){
    return (int **)malloc(m * sizeof(int *)); //aloca dinamicamente o valor de linhas na matriz
}

int alocacaoColunas(int n,int m,int **matriz){
    
    for (int i = 0; i < m; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));  //aloca dinamicamenteo valor de colunas que a matriz tera
    }
}

int main()
{
    int m, n;
    printf("Digite o tamanho linhas da matriz: "); //inicializa o numero de linhas da matriz
    scanf("%d",&m);
    printf("Digite o tamanho colunas da matriz: "); //inicializa o numero de colunas da matriz
    scanf("%d",&n);
    
    int **matriz=alocacaoLinhas(m);

    alocacaoColunas(m,n,matriz);
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j]=m+1;
            printf(" %d",matriz[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < m; i++) {
        free(matriz[i]);  //primeiro liberamos cada linha da matriz
    }
    
    free(matriz); //liberacao da memoria alocada para o array de ponteiros, evitando que vaze memoria
    return 0;
}

/*Na main, pedimos o tamanho de linhas e de colunas que deseja, chamamos a funcao alocarLinhas para ser alocado dinamicamente a quantidade que foi posta em linhas e igualamos
a **matriz, que logo apos e passada para a funcao alocacaoColunas e la e alocado o tamanho de colunas que foi desejado. O primeiro laço de repeticao serve para imprimir
todos os numeros do vetores sendo o numero que foi digitado em linhas mais 1(m+1). Ja o segundo for e usado para liberar o espaço das linhas da matriz, e depois
acontece a liberacao da memoria alocada para o array de ponteiro, fazendo isso, evita que a memoria seja vazada*/


