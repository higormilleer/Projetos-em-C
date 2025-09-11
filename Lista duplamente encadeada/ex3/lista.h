typedef struct elemento{
    int numero;
    struct elemento *prox;
    struct elemento *ant;
}Node, *Lista;

Lista* criarLista();
void liberarLista(Lista *li);
void imprimirLista(Lista* li);
void inserirLista(Lista* li, int numero);
int conta_lista_nota(Lista* li, int numero);
