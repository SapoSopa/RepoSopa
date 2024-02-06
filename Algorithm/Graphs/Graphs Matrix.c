#include <stdio.h>
#include <stdlib.h>
// Componentes de um grafo;
// Um grafo pode ser representado como uma Matriz de Adjacência ou uma Lista de Adjacência;
// A Matriz de Adjacência é uma matriz VxV, onde V é o número de vértices do grafo;
// A Lista de Adjacência é um array de listas, cujo armazena os vértices adjacentes;
// A representação de um grafo como uma Matriz de Adjacência é mais eficiente para grafos densos;
// A representação de um grafo como uma Lista de Adjacência é mais eficiente para grafos esparsos;

// Estrutura de um grafo como uma Matriz de Adjacência sem ponderação;

typedef struct Graph {
    int **Matrix;                               // Matriz de Adjacência;
    int E;                                      // Número de Arestas;
    int V;                                      // Número de Vértices;
    int *Mark;                                  // Marcadores auxiliares;
} Graph;

// Funções de manipulação de um grafo como uma Matriz de Adjacência;

Graph *create_graph(int V);                     // Cria um grafo com V vértices;
int n_vertices(Graph *G);                       // Retorna o número de vértices do grafo;
int n_edges(Graph *G);                          // Retorna o número de arestas do grafo;
int first(Graph *G, int v);                     // Retorna o primeiro vértice adjacente a v;
int next(Graph *G, int v, int w);               // Retorna o próximo vértice adjacente a v;
void setEdge(Graph *G, int v1, int v2, int w);  // Adiciona uma aresta entre v1 e v2 com peso w;
void delEdge(Graph *G, int v1, int v2);         // Remove a aresta entre v1 e v2;
int isEdge(Graph *G, int v1, int v2);           // Verifica se existe uma aresta entre v1 e v2;
void setMark(Graph *G, int v, int val);         // Marca o vértice v com o valor val;
int getMark(Graph *G, int v);                   // Retorna o valor marcado do vértice v;

// Funções de manipulação de um grafo como uma Matriz de Adjacência;

Graph *create_graph(int V)
{
    Graph *G = (Graph *)malloc(sizeof(Graph));
    G->Matrix = (int **)malloc(V * sizeof(int *));
    G->E = 0;
    G->Mark = (int *)malloc(V * sizeof(int));
    return G;
}

int n_vertices(Graph *G)
{
    return G->V;
}

int n_edges(Graph *G)
{
    return G->E;
}

int first(Graph *G, int v)
{
    for (int i = 0; i < G->V; i++)
    {
        if (G->Matrix[v][i] != 0)                // Assumimos o valor 0 como ausência de aresta entre 2 vértices;
        {
            return i;
        }
    }
    return G->V;
}

int next(Graph *G, int v, int w)
{
    for (int i = w + 1; i < G->V; i++)
    {
        if (G->Matrix[v][i] != 0)               // Assumimos o valor 0 como ausência de aresta entre 2 vértices;
        {
            return i;
        }
    }
    return G->V;
}

void setEdge(Graph *G, int v1, int v2, int w)
{
    if (w = 0)                                  // Assumimos o valor 0 como ausência de aresta entre 2 vértices;
    {
        // Algum erro;
    }
    if (G->Matrix[v1][v2] == 0)                 // Assumimos o valor 0 como ausência de aresta entre 2 vértices;
    {
        G->E++;
    }
    G->Matrix[v1][v2] = w;
}

void delEdge(Graph *G, int v1, int v2)
{
    if (G->Matrix[v1][v2] != 0)                 // Assumimos o valor 0 como ausência de aresta entre 2 vértices;
    {
        G->E--;
    }
    G->Matrix[v1][v2] = 0;
}

int isEdge(Graph *G, int v1, int v2)
{
    if (G->Matrix[v1][v2] != 0)                 // Assumimos o valor 0 como ausência de aresta entre 2 vértices;
    {
        return 1;
    }
    return 0;
}

void setMark(Graph *G, int v, int val)
{
    G->Mark[v] = val;
}

int getMark(Graph *G, int v)
{
    return G->Mark[v];
}