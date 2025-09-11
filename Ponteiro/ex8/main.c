/*Escrever um programa que cadastre alguns produtos em um vetor de
estruturas/registros alocado dinamicamente. Em seguida, imprima uma lista
com o código e nome da cada produto. Por último, consulte o preço de um
produto através de seu código.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {  //struct que armazena o codigo, nome e preco
    int codigo;
    char nome[30];
    float preco;
    } Produto;

int main()
{
    int numProdutos=0;
    printf("quantos produtos para realizar o cadastro: "); //quantos produtos deseja ser cadastrado
    scanf("%d", &numProdutos);
    
    Produto *produtos = (Produto *)malloc(numProdutos * sizeof(Produto)); //alocando dinamicamente o numero de produtos que deseja ser cadastrado
    if (produtos == NULL) {
        printf("Erro: Memória insuficiente\n"); //tratamento de erro
    }
    
    for (int i = 0; i < numProdutos; i++) {  //for para digitalizar o codigo, nome e preco do Produto, de acordo com a quantidade de numProdutos anteriormente digitados
        printf("Produto %d\n",i+1);
        printf("Qual o codigo do produto: ");
        scanf("%d", &produtos[i].codigo);
        printf("Qual o nome do produto: ");
        scanf(" %[^\n]", produtos[i].nome);
        printf("Qual o preco do produto: ");
        scanf("%f", &produtos[i].preco);
    }
    
    printf("Lista de Produtos Cadastrados:\n"); //lista com todas as informacoes de produtos que digitamos(codigo, nome e preco)
    for (int i = 0; i < numProdutos; i++) {
        printf("%d %s: %.1f\n", produtos[i].codigo,produtos[i].nome, produtos[i].preco);
    }

    int consultar;
    printf("\nQual o codigo que deseja consultar? "); //qual codigo deseja consultar
    scanf("%d", &consultar);
    
    for (int i = 0; i < numProdutos; i++) {
        if(produtos[i].codigo==consultar){ //caso o codigo do produto for igual ao consultar ele imprime o nome e o preco do mesmo
            printf("O preço do produto %s é R$ %.2f\n", produtos[i].nome, produtos[i].preco);
        }
    }
    
    free(produtos); //liberacao de memoria dos produtos anteriormente alocados dinamicamente
    return 0;
}

/*e definino no struct o nome, codigo e preco do produto. Na funcao principal e pedido a quantidade de produtos que deseja cadastrar e armazenado em numProduto, alocamos dinamicamente em produtos
a quantidade que deseja. No primeiro for serve para digitalizar o codigo, nome e preco do produto, de acordo com a quantidade de numProdutos. O segundo dor imprime o codigo, nome e preco que 
definimos para cada produto. Para constultar o produto pelo codigo, pedimos qual codigo deseja ver, armazenamos na variavel consultar, iniciamos um laço que de acordo com o numero de produtos,
verifica se o produto.codigo de cada um inserido e igual ao codigo que deseja ser consultado, caso encontrar, ele imprime o nome e preco. O free(produtos) para esvaziar a memoria alocada.*/


