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

Node *criarNode(int val);
Matriz *criarMatriz();
void desalocarMatriz(Matriz *m);
void inserirValores(Matriz *m);
void imprimirMatriz(Matriz *m);
Node* buscarValor(Matriz *m);
Node *buscarPosicao(Matriz *m, int col, int lin);
void imprimirVizinho(Matriz *m);
void menu();