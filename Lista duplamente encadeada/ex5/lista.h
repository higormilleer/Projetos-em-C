typedef struct fila
{
    int info;
    struct fila *prox;
} Fila;

typedef struct nodesc
{
    Fila *ini;
    Fila *fim;
} *noDesc;

int inicializa_noDesc(noDesc *no);
int enfileirar(noDesc *no, int elem);
int desenfileirar(noDesc *no, int *elem);
void imprimirNoDesc(noDesc *no);
int liberarNoDesc(noDesc *no);
