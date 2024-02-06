#include <stdio.h>
#include <stdlib.h>
// Componentes de um grafo;
// Um grafo pode ser representado como uma Matriz de Adjacência ou uma Lista de Adjacência;
// A Matriz de Adjacência é uma matriz VxV, onde V é o número de vértices do grafo;
// A Lista de Adjacência é um array de listas, cujo armazena os vértices adjacentes;
// A representação de um grafo como uma Matriz de Adjacência é mais eficiente para grafos densos;
// A representação de um grafo como uma Lista de Adjacência é mais eficiente para grafos esparsos;

// Estrutura de um grafo como uma Lista de Adjacência sem ponderação;

typedef struct Node
{
    int v;                                      // Vértice;
    int mark;                                   // Marcador auxiliar;
    struct Node *next;                          // Próximo vértice adjacente;
} Node;

typedef struct Graph
{
    Node **List;                                // Lista de Adjacência;
    int V;                                      // Número de Vértices;
    int E;                                      // Número de Arestas;
} Graph;

// Funções de manipulação de um grafo como uma Lista de Adjacência;

// Assumiremos que os valores dos vértices serão o mesmo do índice do array;

Node *create_node(int v);                       // Cria um nó com o vértice v;
Graph *create_graph(int mV);                     // Cria um grafo com V vértices;
int n_vertices(Graph *G);                       // Retorna o número de vértices do grafo;
int n_edges(Graph *G);                          // Retorna o número de arestas do grafo;
int first(Graph *G, int v);                     // Retorna o primeiro vértice adjacente a v;
int next(Graph *G, int v, int w);               // Retorna o próximo vértice adjacente a v;
void setEdge(Graph *G, int v1, int v2);         // Adiciona uma aresta entre v1 e v2;
void delEdge(Graph *G, int v1, int v2);         // Remove a aresta entre v1 e v2;
int isEdge(Graph *G, int v1, int v2);           // Verifica se existe uma aresta entre v1 e v2;
void setMark(Graph *G, int v, int val);         // Marca o vértice v com o valor val;
int getMark(Graph *G, int v);                   // Retorna o valor marcado do vértice v;

// Funções de manipulação de um grafo como uma Lista de Adjacência;

Node *create_node(int v)
{
    Node *N = (Node *)malloc(sizeof(Node));
    N->v = v;
    N->mark = 0;
    N->next = NULL;
    return N;
}

Graph *create_graph(int V)
{
    Graph *G = (Graph *)malloc(sizeof(Graph));
    G->List = (Node **)malloc(V * sizeof(Node *));
    G->V = V;
    G->E = 0;
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
    if (G->List[v] != NULL && v < G->V)
    {
        return G->List[v]->v;
    }
    return G->V;                       // Retorna o número de vértices total;
}

int next(Graph *G, int v, int w)
{
    if (v < G->V && w < G->V)
    {
        Node *N = G->List[v];
        while (N != NULL)
        {
            if (N->v == w && N->next != NULL)
            {
                return N->next->v;
            }
            N = N->next;
        }
    }
    return G->V;                       // Retorna o número de vértices total;
}

void setEdge(Graph *G, int v1, int v2)
{
    if (v1 < G->V && v2 < G->V && v1 != v2)
    {
        Node *N = G->List[v1];
        Node *Nv = create_node(v2);
        int notInList = 1;
        while (notInList && N != NULL)
        {
            if (Nv->v == N->next->v)
            {
                notInList = 0;
            }
            else if (Nv->v < N->next->v || N->next == NULL)
            {
                Nv->next = N->next;
                N->next = Nv;
                notInList = 0;
                G->E++;
            }
            else
            {
                N = N->next;
            }
        }
    }
    else
    {
        // Fazer algo quanto a isso, se necessário;
    }
}

void delEdge(Graph *G, int v1, int v2)
{
    Node *N = G->List[v1];
    if (N != NULL)
    {
        int E = G->E;
        while (N->next != NULL && E == G->E)
        {
            if (N->next->v == v2)
            {
                Node *Nv = N->next;
                N->next = N->next->next;
                free(Nv);
                G->E--;
            }
            N = N->next;
        }
    }
}

int isEdge(Graph *G, int v1, int v2)
{
    Node *N = G->List[v1];
    while (N != NULL)
    {
        if (N->v == v2)
        {
            return 1;
        }
        N = N->next;
    }
    return 0;
}

void setMark(Graph *G, int v, int val)
{
    if (v < G->V)
    {
        G->List[v]->mark = val;
    }
}

int getMark(Graph *G, int v)
{
    if (v < G->V)
    {
        return G->List[v]->mark;
    }
    return /*Alguma mensagem de erro*/;
}