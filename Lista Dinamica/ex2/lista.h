typedef struct aluno{
    int matricula;
    char nome[30];
} Aluno;

typedef struct elemento{
    struct aluno dados;
    struct elemento *prox;
} Node, *Lista;

void libera_lista(Lista* li);
int remove_lista(Lista* li, int dado);
int comparacao(Lista *l1, Lista *l2);
Lista * criarLista();
void liberarLista(Lista *li);
int insereLista(Lista *li, Aluno al);
int imprimir_lista(Lista *li);

