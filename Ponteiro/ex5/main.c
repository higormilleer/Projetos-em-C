/*Crie um programa para manipular vetores com ponteiros. O seu programa
deve implementar uma função chamada inverte_vetor, que recebe como
parâmetro dois vetores V1 e V2, ambos de tamanho N. A função deve copiar
os elementos de V1 para V2 na ordem inversa. Ou seja, se a função receber
V1 = {1,2,3,4,5}, a função deve copiar os elementos para V2 na seguinte
ordem: V2 = {5,4,3,2,1}. Além disso, a função também deve retornar o maior
valor encontrado em V1. A função deve obedecer ao seguinte protótipo: int
inverte_vetor(int *v1, int *v2, int n).*/

#include <stdio.h>
#include <stdlib.h>

int* alocacaoV1(int n){
    return (int*)malloc(n*sizeof(int)); //alocando dinamicamente o numero anteriormente digitado
}

int* alocacaoV2(int n){
    return (int*)malloc(n*sizeof(int)); //alocar dinamicamente o v2
}

int inverte_vetor(int *v1, int *v2, int n){

    for(int i=0,j=n-1;i<n;i++,j--){ //copia os elementos inversamentes de v1 em v2, onde o v1[i], i e incrementado e v2[j], j e decrementado
        v2[j]=v1[i];
    }

    for(int i=0;i<n;i++){
        printf("%d", v2[i]); //imprime o valor de v2 anteriormente copiados inversamente de v1
    }
    
    int maior = v1[0]; //declarando a variavel maior igual ao v1 no primeiro indice
    for (int i = 0; i < n; i++) {
        if (v1[i] > maior){
            maior = v1[i];
        }
    }
    
    return maior; //retorna para o int inverte_vetor o maior valor encontrado em v1
    
}
/*no ultimo for, caso v1[i] seja maior que a variavel maior onde i e o numero do indice que esta sendo chamado no for, sempre sendo incrementado 1,
maior = v1[i]; onde i e o numero do indice que esta sendo chamado no for, sempre sendo incrementado 1,a varial maior vai igual a v1[i] agora, assim achando o maior numero do vetor*/

int main()
{
    int n;
    
    printf("Digite o numero de vetores: "); //guardar o numero de vetores
    scanf("%d",&n);
    
    int *v1 = alocacaoV1(n);
    
    for(int i = 0; i<n;i++){
        printf("Digite os valores do vetor %d: ",i+1);  //guardar os valores dos vetores
        scanf("%d", &v1[i]);
    }
    
    int *v2 = alocacaoV2(n);
    
    int maior= inverte_vetor(v1,v2,n);
    printf("\nO maior numero e: %d",maior); //printando a chamada da funcao

    free(v1); //liberando a memoria de v1
    free(v2); //liberando a memoria de v2
    return 0;
}

/*Na funcao main, primeiro guardamos o numero de vetores que o usuarios digitou, apos isso e chamada a funcao alocacaov1, onde e alocado dinamicamente o valor do numero de vetores e igual a *V1 na funcao main.
Depois, e guardado em v1, os valores de cada numero do vetor no for, apos, e chamada a funcao alocacao v2 que aloca dinamicamente o numero de vetores n igualados em *v2 na funcao main.
depois chamamos a funcao inverte_valor onde la transcrevemos os valores que foram depositados em v1 para v2 invertido e retornamos para a main o maior valor encontrado em v1, onde e impresso logo em seguida.
No final, libremos as memorias alcoadas de v1 e v2.*/





