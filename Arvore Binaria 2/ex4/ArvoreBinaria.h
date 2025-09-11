typedef struct NO
{
    int info;
    struct NO *esq;
    struct NO *dir;
} Node, *Arvore;

Arvore* criaArvBin();
void liberaNo(Node *no);
void liberaArvore(Arvore *raiz);
int insereArvore(Arvore *raiz, int valor);
void imprimirDec(Arvore *raiz);