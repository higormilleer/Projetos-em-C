typedef struct elemento{
    int numero;
    struct elemento *prox;
}Node, *Lista;

Lista* criarLista();
void libera_lista(Lista* li);
void imprimirLista(Lista *li);
void inserirLista(Lista *li, int numero);
int remove_lista(Lista* li);
