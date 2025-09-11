typedef struct NO
{
    char info;
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
int calcularResultado(Arvore *raiz);
void imprimeInfixa(Arvore *raiz);
void imprimePrefixa(Arvore *raiz);
void imprimePosfixa(Arvore *raiz);
Arvore* criaArvoreCalculo();