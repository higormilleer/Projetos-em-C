typedef struct elemento{
    int numero;
    struct elemento *prox;
    struct elemento *ant;
}Node, *Lista;

Lista* criarLista();
void liberarLista(Lista *li);
void imprimirLista(Lista* li);
void inserir_inicio(Lista *li, int numero);
void inserir_final(Lista *li, int numero);
void remover_inicio(Lista* li);
void remover_final(Lista* li);

