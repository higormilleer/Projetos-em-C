typedef struct elemento
{
    int numero;
    struct elemento *prox;
}Node, *Lista;

void libera_lista(Lista* li);
Lista* criarLista();
void imprimirLista(Lista* li);
void inserirLista(Lista *li, int numero);
void ordenadaLista(Lista* l1, Lista* l2);
