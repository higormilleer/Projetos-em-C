typedef struct aluno
{
    int matricula;
    char nome[30];
}Aluno;

typedef struct elemento
{
    struct aluno dados;
    struct elemento *prox;
}Node, *Lista;

void libera_lista(Lista* li);
Lista* criarLista();
int insereLista(Lista *li, Aluno al);
int imprimir_lista(Lista *li);
int percorra(Lista *li, int remover);
