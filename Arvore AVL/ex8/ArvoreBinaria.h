typedef struct bin
{
    int info;
    struct bin *esq;
    struct bin *dir;
} No, *ArvBin;

ArvBin* criaArvBin();
void liberaNo(No *no);
void liberaArvBin(ArvBin *raiz);
int insereArvBin(ArvBin *raiz, int valor);
void preOrdemArvBin(ArvBin *raiz);

