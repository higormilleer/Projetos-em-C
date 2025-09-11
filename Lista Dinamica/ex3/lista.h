typedef struct elemento
{
    int numero;
    struct elemento *prox;
}Node, *Lista;

Lista* criarPilha();
void inserirLista(Lista* li, int numero, int posicao);
void libera_lista(Lista* li);
void imprimir(Lista *li);