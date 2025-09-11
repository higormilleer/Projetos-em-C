typedef struct aluno
{
    int matricula;
    char nome[30];
}Aluno;

typedef struct elemento
{
    int numero;
    struct elemento *prox;
}Node, *Lista;

void libera_lista(Lista* li);
Lista* criarLista();
int insereLista(Lista *li, int numero);
void imprimir(Lista* li);
void concatenar(Lista *l1, Lista *l2);
