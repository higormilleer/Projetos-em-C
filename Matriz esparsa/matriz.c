#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

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
    cabeca->linha=0;
    cabeca->coluna=0;
    m->inicio = cabeca;

    Node *atual = cabeca;
    Node *prox = NULL;

    for(int i = 0; i < m->linha; i++){
        for(int j = 0; j < m->coluna; j++){
            if(i==0 && j==0) continue;
            Node *no = criarNode(0);
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

    while(prox != NULL){
        prox->cima = atual;
        atual->baixo = prox;
        prox=prox->dir;
        atual=atual->dir;
    }
    
    atual = cabeca;
    for(int i=0;i<m->linha;i++){
        prox = atual;
        for(int j = 0; j<m->coluna;j++){
            if(j==0){
                prox->esq = NULL;
            }
            if(j==(m->coluna)-1){
                prox->dir = NULL;
            }
            prox = prox->dir;
        }
        atual = atual->baixo;
    }
        
    
    return m;
}    

void desalocarMatriz(Matriz *m){

    Node* no = m->inicio;
    
    for(int i = 0; i < m->linha; i++){
        Node* atual = no;
        no = no->baixo;
        for(int j = 0; j < m->coluna; j++){
            Node *aux = atual;
            atual = atual->dir;
            free(aux);
        }
    }
    free(m);
}

void inserirValores(Matriz *m){
    if(m==NULL ||m->inicio == NULL) return;
    
    Node* no = m->inicio;
    
    int num;

    printf("digite o numero que deseja adicionar: ");
    scanf("%d", &num);

    int col,lin;
    do{ 
        printf("Numero da coluna: ");
        scanf("%d", &col);
        printf("Numero da linha: ");
        scanf("%d", &lin);
        if(col >= m->coluna || lin >= m->linha){
            printf("o numero da coluna ou linha, ultrapassa o tamanho da matriz\n\n");
        }
    }while(col >= m->coluna || lin >= m->linha);

    for(int i = 0; i < m->linha; i++){
        Node *atual = no;
        for(int j = 0; j < m->coluna; j++){
            if (atual->coluna == col && atual->linha == lin) {
                printf("Numero %d inserido com sucesso \n", num);
                atual->dados = num;
                return;
            }
            atual = atual->dir;
        }
        no = no->baixo;
    }
}

void imprimirMatriz(Matriz *m){

    Node* no = m->inicio;
    
    for(int i = 0; i < m->linha; i++){
        Node *atual = no;
        for(int j = 0; j < m->coluna; j++){
            printf("%d ", atual->dados);
            atual = atual->dir;
        }
        printf("\n");
        no = no->baixo;
    }
    return;
}
    
Node* buscarValor(Matriz *m){
    
    Node* no = m->inicio;
    
    int valor;

    printf("digite o valor que deseja encontrar: ");
    scanf("%d", &valor);

    for(int i = 0; i < m->linha; i++){
        Node *atual = no;
        for(int j = 0; j < m->coluna; j++){
            if (atual->dados == valor) {
                printf("Valor encontrado\n");
                printf("coluna: %d, linha: %d \n", atual->coluna, atual->linha);
                return atual;
            }
            atual = atual->dir;
        }
        no = no->baixo;
    }

    return NULL;
    
}

Node *buscarPosicao(Matriz *m, int col, int lin){
    
    Node* no = m->inicio;

    for(int i = 0; i < m->linha; i++){
        Node* atual = no;
        for(int j = 0; j < m->coluna; j++){
            if (atual->coluna == col && atual->linha == lin) {
                printf("Valor encontrado: %d\n", atual->dados);
                return atual;
            }
            atual = atual->dir;
        }
        no = no->baixo;
    }
    return NULL;
}

void matrizTransposta(Matriz* m) {
    
    Node* no = m->inicio;
    Node* atual = no;
    int** aux = (int**)malloc(m->coluna * sizeof(int*));
    if(aux==NULL) return;
    
    for(int i = 0;i<m->linha;i++){
        aux[i] = (int*)malloc(m->linha * sizeof(int));
    }
    
    for (int i = 0; i < m->linha; i++) {
        atual = no;
        for (int j = 0; j < m->coluna; j++) {
            aux[j][i]=atual->dados;
            atual = atual->dir;
        }
        no = no->baixo; 
    }
    
    no = m->inicio;
    for (int i = 0; i < m->linha; i++) {
        atual = no;
        for (int j = 0; j < m->coluna; j++) {
            atual->dados = aux[i][j];
            atual = atual->dir;
        }
        no = no->baixo; 
    }
    
    for(int i =0;i<m->linha;i++){
        free(aux[i]);
    }
    free(aux);
    
}

void imprimirVizinho(Matriz *m) {
    int col,lin;
    do{ 
        printf("Numero da coluna: ");
        scanf("%d", &col);
        printf("Numero da linha: ");
        scanf("%d", &lin);
        if(col >= m->coluna || lin >= m->linha){
            printf("o numero da coluna ou linha, ultrapassa o tamanho da matriz\n\n");
        }
    }while(col >= m->coluna || lin >= m->linha);

    Node *no = buscarPosicao(m, col, lin);
    if(no==NULL){
        printf("Nao foi possivel encontrar o no na posicao (%d, %d)\n", col, lin);
        return;
    }

    if (no->esq != NULL) {
        printf("Vizinho da esquerda: %d\n", no->esq->dados);
    } else {
        printf("Nao ha vizinho a esquerda.\n");
    }
    if (no->dir != NULL) {
        printf("Vizinho da direita: %d\n", no->dir->dados);
    } else {
        printf("Nao ha vizinho a direita.\n");
    }
    if (no->cima != NULL) {
        printf("Vizinho de cima: %d\n", no->cima->dados);
    } else {
           printf("Nao ha vizinho acima.\n");
    }
    if (no->baixo != NULL) {
        printf("Vizinho de baixo: %d\n", no->baixo->dados);
    } else {
        printf("Nao ha vizinho abaixo.\n");
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
        printf("5 - Imprimir Matriz \n");
        printf("6 - Transposicao de Matriz\n");
        printf("7 - Desalocar memoria(Encerrar o programa)\n");
        scanf("%d", &opcao);
        system("clear");
        if(opcao>6 || opcao<1){
            printf("a opção nao existe no formulario! \n");
        }
    
        switch (opcao)
        {
        case 1:
            inserirValores(m);
            break;

        case 2:
            int col,lin;
            do{ 
                printf("Numero da coluna: ");
                scanf("%d", &col);
                printf("Numero da linha: ");
                scanf("%d", &lin);
                if(col >= m->coluna || lin >= m->linha){
                    printf("o numero da coluna ou linha, ultrapassa o tamanho da matriz\n\n");
                }
            }while(col >= m->coluna || lin >= m->linha);
            
            buscarPosicao(m,col,lin);
            break;

        case 3:
            buscarValor(m);
            break;

        case 4:
            imprimirVizinho(m);
            break;
        
        case 5:
            imprimirMatriz(m);
            break;
            
        case 6:
            matrizTransposta(m);
            break;
            
        case 7:
            desalocarMatriz(m);
            printf("Matriz descolada com sucesso \n");
            printf("Programa encerrado");
            return;
            break;
        
        default:
            break;
        }
        
    }while(opcao<5 || opcao>=1);
    return;
}

