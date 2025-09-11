typedef struct NO
{
    char info;
    struct NO *esq;
    struct NO *dir;
} Node, *Arvore;

Arvore* criaArvBin();
void liberaNo(Node *no);
void liberaArvore(Arvore *raiz);
int insereArvore(Arvore *raiz, char valor);
void preOrdemArvore(Arvore *raiz);
void ordemLetra(Arvore *raiz);