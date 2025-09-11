/*9) Considere a implementação de listas encadeadas. Escreva um
procedimento Troca(TipoLista* pLista, TipoCelula* p) que, dado um
apontador para uma célula qualquer (p), troca de posição essa célula
com a sua célula seguinte da lista, como mostrado na figura abaixo.
(Obs. Não vale trocar apenas o campo item! Você deverá fazer a
manipulação dos apontadores para trocar as duas células de posição).
Não esqueça de tratar os casos especiais.*/
#include <stdio.h>
#include <stdlib.h>

  typedef struct aluno{
    int matricula;
    char nome[30];
} Aluno;

typedef struct elemento{
    struct aluno dados;
    struct elemento *prox;
} Node, *Lista;

Lista * criarLista()
{
    Lista *li = (Lista*)malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    
    return li;
}

void liberarLista(Lista *li)
{
    if(li != NULL)
    {
        Node *no;
        while((*li) != NULL)
        {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int insereLista(Lista *li, Aluno al)
{
    if(li == NULL)
        return 0;
        
    Node *no;
    no = (Node*)malloc(sizeof(Node));
    if(no == NULL)
        return 0;
    
    no->dados = al;
    no->prox = NULL;
    
    if((*li) == NULL)
    {
        *li = no;
    }
    else
    {
        Node *aux;
        aux = *li;
        
        while(aux->prox != NULL)
        
        aux = aux->prox;
        aux->prox = no;
    }
    return 1;
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Node* no = *li;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("-------------------------------\n");

        no = no->prox;
    }
}

int troca(Lista* li, Node* p){
    if(li == NULL || p == NULL)
        return 0;
    
    if(*li == p){//o codigo funciona verificando se o elemento eh a cabeca da lista (primeiro) entao faz a cabeça agora apontar para o segundo elemento e corrige as apontacoes, 
        *li = p->prox;
        p->prox = (*li)->prox;
        (*li)->prox = p;
        
        return 1;
    }
    Node *no, *ant;
    no = *li;
    
    while(no != p && no != NULL){//caso nao seja o primeiro, eh feito um loop while para encontra-lo, criando um no atual e anteriar para percorrer o loop,
        ant = no;
        no = no->prox;
    }
    if(no->prox == NULL){//verifica tambem se e o ultimo, para mostrar no prompt uma mensagem de erro pelo fato de ser o ultimo elemento da lista e nao ter um proximo para ser trocado,
        printf("esse elemento ja e o ultimo da lista\n\n");
        return 1;
    }
    if(no == p){//verifica se esta no meio, e entao eh feito a correcao das apontacoes do no anterior, do no escolhido, e do no seguinte,
        no = no->prox;
        p->prox = no->prox;
        no->prox = p;
        ant->prox = no;
        return 1;
    }
    return 0;
}
 
int main(){
        
        Aluno al[5] = {{24, "higor"},{14, "geremias"},{33, "robertao"},{44, "sauel"},{20, "duda"}};

    Lista *li = criarLista();

    for(int i=0;i<5;i++){
        insereLista(li, al[i]);
    }
    
    imprime_lista(li);
    
    printf("\n\n trocando primeiro\n\n\n");
    
    troca(li, (*li));
    
    imprime_lista(li);
    
    printf("\n\n trocando meio\n\n\n");

    troca(li, (*li)->prox);
    
    imprime_lista(li);
    
    printf("\n\n trocando ultimo\n\n\n");

    troca(li, (*li)->prox->prox->prox->prox);
    
    imprime_lista(li);
    
    liberarLista(li);
    
    return 0;
     
    } 
    
    //o codigo funciona verificando se o elemento eh a cabeca da lista (primeiro) entao faz
    //a cabeça agora apontar para o segundo elemento e corrige as apontacoes, 
    //caso nao seja o primeiro, eh feito um loop while para encontra-lo, criando um no atual e anteriar para
    //percorrer o loop, verifica tambem se e o ultimo,
    //para mostrar no prompt uma mensagem de erro pelo fato de
    //ser o ultimo elemento da lista e nao ter um proximo para ser trocado,
    //verifica se esta no meio, e entao eh feito a correcao das apontacoes do no anterior,
    //do no escolhido, e do no seguinte,

 
