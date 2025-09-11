typedef struct elemento
{
    int numero;
    struct elemento *prox;
    struct elemento *ant;
}Node, *Lista;

Lista* criarLista();
void imprimirLista(Lista *li);
void liberarLista(Lista *li);
void inserir_lista_inicio(Lista *li, int numero);
void inserir_lista_final(Lista *li, int numero);
void remover_inicio(Lista *li);
void remover_final(Lista *li);
void remover_numero(Lista *li, int numero);
