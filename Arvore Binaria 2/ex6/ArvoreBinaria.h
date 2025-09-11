typedef struct NO
{
    int info;
    struct NO *esq;
    struct NO *dir;
} Node, *Arvore;

Arvore* criaArvBin();
void liberaNo(Node *no);
void liberaArvore(Arvore *raiz);
Node* removeAtual(Node *atual);
int insereArvore(Arvore *raiz, int valor);
void preOrdemArvore(Arvore *raiz);
void removePar(Arvore *raiz ,Node *cabeca);