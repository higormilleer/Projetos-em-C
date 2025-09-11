typedef struct elemento
{
    float numero;
    struct elemento *prox;
}Node, *Lista;

void libera_lista(Lista* li);
Lista* criarLista();
void imprimirLista(Lista *li);
int inserirLista(Lista *li, float numero);
