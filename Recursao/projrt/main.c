
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int coluna;
    int linha;
    struct node *cima;
    struct node *baixo;
    struct node *dir;
    struct node *esq;
    int dados;
}Node;

typedef struct matriz{
    int coluna;
    int linha;
    Node *inicio;
}Matriz;

Node *criarNode(int val){
    Node *no = (Node*)malloc(sizeof(Node));
    if(no==NULL) return 0;

    no->dados = val;
    no->dir = NULL;
    no->esq = NULL;
    no->cima = NULL;
    no->baixo = NULL;

    return no;
}
Matriz *criarMatriz(){

    int col;
    int lin;

    printf("Para criar Matriz a digite: \n\nNumero de colunas: ");
    scanf("%d", &col);
    printf("Numero de linhas: ");
    scanf("%d", &lin);


    Matriz *m = (Matriz*)malloc(sizeof(Matriz));
    if(m==NULL) return 0;

    m->linha = lin;
    m->coluna = col;
    
    Node *cabeca = criarNode(0);
    m->inicio = cabeca;

    Node *atual = cabeca;
    Node *prox = NULL;

    for(int i = 0; i < m->linha; i++){
        for(int j = 0; j < m->coluna; j++){
            Node *no = criarNode(0) 
            if (no == NULL) return;
            prox = no;
            no->coluna = j;
            no->linha = i;
            atual->dir = prox;
            prox->esq = atual;
            atual = no;
        }
    }

    atual = cabeca;  
    prox = atual;
    for(int i=0;i<m->coluna;i++){
        prox = prox->dir;
    }

    if(prox != NULL){
        while(prox != NULL){
            prox->cima = atual;
            atual->baixo = prox;
            prox=prox->dir;
            atual=atual->dir;
        }
        
        atual = cabeca;  
        prox = atual;
        for(int i=0;i<m->coluna;i++){
        prox = prox->dir;
    }
        for(int i=0;i<m->linha;i++){
            atual->esq = NULL;
            prox->dir = NULL;
            atual = atual->baixo;
        }
        
    }
    return m;
}    

void desalocarMatriz(Matriz *m){

    Node* no = m->inicio;

    for(int i = 0; i < m->linha; i++){
        for(int j = 0; j < m->coluna; j++){
            Node *aux = no;
            no = no->dir;
            free(aux);
        }
        no = no->baixo;
    }
    free(m);
}

void inserirValores(Matriz *m){
    
    Node* no = m->inicio;

    int num;

    printf("digite o numero que deseja adicionar: ");
    scanf("%d", &num);

    int col,lin;
    
    printf("Numero da coluna: ");
    scanf("%d", &col);
    printf("Numero da linha: ");
    scanf("%d", &lin);


    for(int i = 0; i < m->linha; i++){
        for(int j = 0; j < m->coluna; j++){
            if (no->coluna == col && no->linha == lin) {
                no->dados = num;
            }
            no = no->dir;
        }
        no = no->baixo;
    }
}

void imprimirMatriz(Matriz *m){

    Node* no = m->inicio;

    for(int i = 0; i < m->linha; i++){
        for(int j = 0; j < m->coluna; j++){
            printf("%d ", no->dados);
            no = no->dir;
        }
        no = no->baixo;
    }
}
    
void buscarValor(Matriz *m){
    
    Node* no = m->inicio;
    int valor;

    printf("digite o valor que deseja encontrar: ");
    scanf("%d", &valor);

    for(int i = 0; i < m->linha; i++){
        for(int j = 0; j < m->coluna; j++){
            if (no->dados == valor) {
                printf("Valor encontrado\n");
                printf("coluna: %d, linha: %d", no->coluna, no->linha);
                return;
            }
            no = no->dir;
        }
        no = no->baixo;
    }

    printf("valor nao encontrado");
    return;
}

void buscarPosicao(Matriz *m){
    
    Node* no = m->inicio;

    int col,lin;
    
    printf("Numero da coluna: ");
    scanf("%d", &col);
    printf("Numero da linha: ");
    scanf("%d", &lin);

    for(int i = 0; i < m->linha; i++){
        for(int j = 0; j < m->coluna; j++){
            if (no->coluna == col && no->linha == lin) {
                printf("Valor encontrado: %d\n", no->dados);
                return;
            }
            no = no->dir;
        }
        no = no->baixo;
    }

}

void imprimirVizinho(Matriz *m){
    Node *no = m->inicio;

    int col,lin;
    
    printf("Numero da coluna: ");
    scanf("%d", &col);
    printf("Numero da linha: ");
    scanf("%d", &lin);

    for(int i = 0; i < m->linha; i++){
        for(int j = 0; j < m->coluna; j++){
            if (no->coluna == col && no->linha == lin) {
                printf("O vizinho da esquerda e %d , Direita: %d , Baixo %d, Cima %d \n", no->esq->dados, no->dir->dados, no->baixo->dados, no->cima->dados);
                return;
            }
            no = no->dir;
        }
        no = no->baixo;
    }

}

void menu(){

    Matriz *m = criarMatriz();
    int opcao;

    do{
        printf("\n");
        printf("Digite o numero da operação que deseja efetuar:\n\n");
        printf("1 - Inserir valores inteiros\n");
        printf("2 - Consultar valores de posições específicas\n");
        printf("3 - Buscar um valor qualquer\n");
        printf("4 - Imprimir o valor dos 4 vizinhos\n");
        printf("5 - Sair\n");
        scanf("%d", &opcao);
        system("clear");

        if(opcao>5 || opcao<1){
            printf("a opção nao existe no formulario !");
        }
    
        switch (opcao)
        {
        case 1:
            inserirValores(m);
            break;

        case 2:
            buscarPosicao(m);
            break;

        case 3:
            buscarValor(m);
            break;

        case 4:
            imprimirVizinho(m);
            break;
        
        case 5:
            desalocarMatriz(m);
            printf("programa encerrado");
            break;

        default:
            break;
        }
    }while(opcao<5  || opcao>1);
    return;
    
}

int main(){
    menu();
    
    return 0;
}
    
    
    
    
    
    
    
    
    