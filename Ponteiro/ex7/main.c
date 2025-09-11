/*Escreva uma função que aloca dinamicamente um vetor inteiro v[0..n-1] e os
endereços de duas variáveis inteiras, digamos min e max, e deposite nessas
variáveis o valor de um elemento mínimo e o valor de um elemento máximo
do vetor. Por fim, realoque o tamanho desse vetor dobrando sua capacidade
de armazenamento.*/

#include <stdio.h>
#include <stdlib.h>

int* alocacao(int tam){
    return (int*)malloc(tam*sizeof(int)); //alocando dinamicamente este mesmo tamanho
}

int Encontre(int *vet,int *max,int *min,int tam){
    
    *max=vet[0]; //inicialiazando o ponteiro de max igual a vet no lugar inicial
    *min=vet[0]; //inicialiazando o ponteiro de min igual a vet no lugar inicial
    
    for (int i = 0; i < tam; i++) { 
        if(vet[i]>*max){   //se o vet de i(onde o 'for' esta), for maior que o max(valor anteriormente inicializado no valor inicial, o max e igual ao vet de i)
         *max=vet[i];   
        }
        
        if(vet[i]<*min){  //se o vet de i(onde o 'for' esta), for maior que o min(valor anteriormente inicializado no valor inicial, o min e igual ao vet de i)
            *min=vet[i];
        }
    }
    
    return (*min,*max);
}

int main()
{
    int tam, maximo, minimo;
    printf("Qual o tamanho do vetor?: ");
    scanf("%d",&tam); //guardando o valor do tamanho digitalizado
    
    int *vet = alocacao(tam);
    
    for (int i = 0; i < tam; i++) {
        printf("Preencha o vetor: ");  //preenchendo os valores do vetor
        scanf("%d", &vet[i]);
    }
    
    Encontre(vet,&maximo,&minimo,tam); //passando as variaveis vet, o endereço de maximo e minimo para poder ser manipulado na funcao 'Encontre' e a variavel que esta o tamanho do vetor
    
    printf("Maior: %d\nMenor: %d\n", maximo, minimo); 
    
    vet = realloc (vet,(tam*2)*sizeof(int));

    free(vet);
    
    return 0;
}

/*Na main, pedimos o tamanho no vetor no primeiro print e armazenamos em tam, logo apos, chamamos a funcao de alocacao onde o valor e alocado dinamicamente e igualado em *vet,
entramos no laco de repeticao onde e preenchido todos os vetores com valores que e colocado pelo usado e armazendos em *vet. Na segunda funcao chamada, e passado as varaiaveis
vet, maximo, minimo e tam para poder ser manipulado e encontrar o maior: se o vet de i(onde o 'for' esta), for maior que o max(valor anteriormente inicializado no 
valor inicial, o max e igual ao vet de i) e o menor: //se o vet de i(onde o 'for' esta), for maior que o min(valor anteriormente inicializado no valor inicial, o min e igual ao 
vet de i) e retornando os mesmo para a funcao principal. Voltando ao main, e impresso o maior e o menor vetor, logo depois,o vet e reallocado para o dobro do vetor
anteriormente definido pelo usario. O free (vet) e para a liberacao de memoria*/



