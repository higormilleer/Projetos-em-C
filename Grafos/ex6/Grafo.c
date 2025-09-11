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

int POP_MIN(int* Q, float *key, int numVertices) {
    int minIdx = -1;
    float minKey = 100000000000000;

    //varre os vertices para achar o menor peso
    for(int i = 0; i < numVertices; i++) {
        if(Q[i] != -1 && key[i] < minKey) {
            minKey = key[i];
            minIdx = i;
        }
    }

    if(minIdx != -1)
        Q[minIdx] = -1; // Marca o vértice como visto

    return minIdx;
}

int* PRIM(Grafo *gr, int verticeInicial) {
    if(gr == NULL || gr->eh_ponderado == 0)
        return NULL;

    float* key = (float*)malloc(gr->nro_vertices * sizeof(float));
    if(key == NULL)
        return NULL;

    int* pi = (int*)malloc(gr->nro_vertices * sizeof(int));
    if(pi == NULL) {
        free(key);
        return NULL;
    }

    int* Q = (int*)malloc(gr->nro_vertices * sizeof(int));
    if(Q == NULL) {
        free(key);
        free(pi);
        return NULL;
    }

    // Inicializa as chaves, predecessores e a fila
    for(int i = 0; i < gr->nro_vertices; i++) {
        key[i] = 100000000000000; 
        pi[i] = -1;
        Q[i] = i;
    }

    key[verticeInicial] = 0;

    while(1) {
        //j seria o valor minimo encontrado apos chamar a funcao de POP_MIN
        int j = POP_MIN(Q, key, gr->nro_vertices);
        if(j == -1) 
            break;

        // Atualiza os proximos dos vertices, trabalhando como uma 'Lista'
        for(int i = 0; i < gr->grau[j]; i++) {
            int k = gr->arestas[j][i];
            float peso = gr->pesos[j][i];

            if(Q[k] != -1 && peso < key[k]) {
                pi[k] = j;
                key[k] = peso;
            }
        }
    }

    free(key);
    free(Q);
    return pi; 
}

void imprimirPRIM(int* pi, int numVertices) {
    for(int i = 0; i < numVertices; i++)
        printf("[%d: (%d)] ", i, pi[i]);
    printf("\n");
}

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




