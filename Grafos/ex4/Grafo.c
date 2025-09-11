#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h" //inclui os Protótipos

//Definição do tipo Grafo
struct grafo{
    int eh_ponderado;
    int nro_vertices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
};

/*Na funcao cria_Grafo(), ele passa como paremtro as informacoes que desejamos inserir, ele aloca um grafo gr, no if ele faz o tratamento para ver se deu certo
a alocacao, pos isso, ele passa os as variaveis que esta presente na struct para o grafo gr(nro_vertices, grau_,ax,eh_ponderado), e aloca zerando os numeros de vertices.
Depois, ele aloca dinamicamente os numeros de arestas e passa os valores com o for, de acordo com o nro de vertices desejado.
Apos isso, ele entra no if perguntando se o grafo e ponderado, ou seja, ele tem pesos nas arestas, caso ele for, entra em outro for apos a alocacao de gr->pesos, para colocar
dentro dele os pesos das aretas
*/
Grafo* cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado){
    Grafo *gr;
    gr = (Grafo*) malloc(sizeof(struct grafo));
    if(gr != NULL){
        int i;
        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = (eh_ponderado != 0)?1:0;
        gr->grau = (int*) calloc(nro_vertices,sizeof(int));

        gr->arestas = (int**) malloc(nro_vertices * sizeof(int*));
        for(i=0; i<nro_vertices; i++)
            gr->arestas[i] = (int*) malloc(grau_max * sizeof(int));

        if(gr->eh_ponderado){
            gr->pesos = (float**) malloc(nro_vertices * sizeof(float*));
            for(i=0; i<nro_vertices; i++)
                gr->pesos[i] = (float*) malloc(grau_max * sizeof(float));
        }

    }
    return gr;
}

/*Na funcao de libera_Grafo(), ele comeca fazendo o tratamento para ver se o grafo nao e nulo, no comeco ele da free nas arestas utilizando o for para acessar todas
as arestas, e depois de dar free posicao por posicao, ele da free no gr->arestas que sobrou.
Ele faz a mesma coisa com os pesos da arestas, da um free de acordo com as posicoes que as mesmas ocupam e pos isso da free no gr->pesos que esta alocado.
quando sai dos dois if, ele entra no free->grau para liberar a tabela de grau que foi criada, e depois sobra apenas o grafo vazio, onde tambem
e dado free para finalmente conseguir liberar ele como um todo*/

void libera_Grafo(Grafo* gr){
    if(gr != NULL){
        int i;
        for(i=0; i<gr->nro_vertices; i++)
            free(gr->arestas[i]);
        free(gr->arestas);

        if(gr->eh_ponderado){
            for(i=0; i<gr->nro_vertices; i++)
                free(gr->pesos[i]);
            free(gr->pesos);
        }
        free(gr->grau);
        free(gr);
    }
}

/*Na funcao insereAresta(), ele passa como paremetro o grafo, a origem(de onde vai partir  o vertice), o destino(para onde vai o vertice), se e digrafo(caso ele for unidirecional)
e o peso dos vertices. Comeca fazendo o tratamento, pois nao pode ser uma origem menor que 0 e maior que o numero de vertices existentes, mesma coisa para o destino.
No "gr->arestas[orig][gr->grau[orig]] = dest;" ele acessa a 'tabela' de arestas na posicao origem e pega o numero de arestas que a posicao origem tem e coloca o destino na mesma tabela
mencionada anteriormente, pois o numero de ligacoes seria por exemplo 3, e quando vai colocar na tabela, ele comeca do 0,1,2 assim achando a posicao que esta vazia que seria o 3.
Agora, caso ele for ponderado,ele utiliza da mesma logica para colocar o peso na 'tabela' de pesos,e depois soma um no grau(gr->grau[orig]++), depois acessa o ultimo if 
perguntando se nao e digrafo, caso nao seja, ele vai chamar novamente o insereAresta trocando, agora colocando o destino como origem e vice versa, porem passando
que e digrafo, para quando realizar novamente esta funcao, nao entrar no ultimo if, assim colocando as arestas conectadas em ambos.*/

int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;

    gr->arestas[orig][gr->grau[orig]] = dest;
    if(gr->eh_ponderado)
        gr->pesos[orig][gr->grau[orig]] = peso;
    gr->grau[orig]++;

    if(eh_digrafo == 0)
        insereAresta(gr,dest,orig,1,peso);
    return 1;
}

/*Na funcao removeAresta(), ele passa como paremetro o grafo, a origem(de onde vamos retirar o vertice), o destino(para onde vamos retirar o vertice), se e digrafo(caso ele for unidirecional)
e o peso dos vertices. Comeca fazendo o tratamento, pois nao pode ser uma origem menor que 0 e maior que o numero de vertices existentes, mesma coisa para o destino.
No while, e utilizado para descobrir qual aresta esta conectado na origem e no destino. Caso nao encontrar, ou seja, o i for igual ao grau de origem,
ele retorna 0;
Ele decrementa 1 no grau de origem( gr->grau[orig]--), depois, ele substitui a aresta removida pela última aresta na lista do vértice de origem, caso 
ele for ponderado, tambem remove o peso que esta ligado a ele. Caso o grafo nao seja digrafo, a funcao e chamada novamente de maneira recursiva para
retirar o a ligacao do destino para a origem, da mesma maneira que utilizamos para a insercao, trocando a origem com o destino e vice e versa, 
e passando que ele e digrafo para nao entrar novamente neste if.*/

int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;

    int i = 0;
    while(i<gr->grau[orig] && gr->arestas[orig][i] != dest)
        i++;
    if(i == gr->grau[orig])//elemento nao encontrado
        return 0;
    gr->grau[orig]--;
    gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];
    if(gr->eh_ponderado)
        gr->pesos[orig][i] = gr->pesos[orig][gr->grau[orig]];
    if(eh_digrafo == 0)
        removeAresta(gr,dest,orig,1);
    return 1;
}

void imprime_Grafo(Grafo *gr){
    if(gr == NULL)
        return;

    int i, j;
    for(i=0; i < gr->nro_vertices; i++){
        printf("%d: ", i);
        for(j=0; j < gr->grau[i]; j++){
            if(gr->eh_ponderado)
                printf("%d(%.2f), ", gr->arestas[i][j], gr->pesos[i][j]);
            else
                printf("%d, ", gr->arestas[i][j]);
        }
        printf("\n");
    }
}




