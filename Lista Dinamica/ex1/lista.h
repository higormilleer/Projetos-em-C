typedef struct aluno{
    int matricula;
    char nome[30];
} Aluno;

typedef struct elemento{
    struct aluno dados;
    struct elemento *prox;
} Node, *Lista;

Aluno consultaAl(Lista* li, int mat);
Aluno posicaoAL(Lista* li, int posicao);
Lista * criarLista();
void libera_lista(Lista *li);
int insereLista(Lista *li, Aluno al);
