typedef struct elemento{
    int numero;
    struct elemento *prox;
    struct elemento *ant;
}Node, *Lista;

Lista* criarLista();
void imprimirLista(Lista* li);
void insereLista(Lista* li, int numero);
void insereOrdenada(Lista *li, int numero);
