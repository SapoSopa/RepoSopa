#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int V;
    int E;
    int **Matrix;
    int *Mark;
} Graph;

Graph *create_graph(int V);
int first(Graph *G, int v);
int next(int v, int w, Graph *G);
void setEdge(Graph *G, int v, int w);
void setMark(Graph *G, int v, int val);
int getMark(Graph *G, int v);
void DFS(Graph *G, int v);

int main ()
{
    int c, v, a, i, j;
    scanf("%d", &c);
    while (c--)
    {
        int m = 0;
        scanf("%d", &v);
        Graph *G = create_graph(v);
        scanf("%d", &a);
        while (a--)
        {
            scanf("%d %d", &i, &j);
            setEdge(G, i, j);
        }
        for (int i = 0; i < G->V; i++)
        {
            setMark(G, i, 0);
        }
        for (int i = 0; i < G->V; i++)
        {
            if (getMark(G, i) == 0)
            {
                DFS(G, i);
                m++;
            }
        }
        for(int i = 0; i < G->V; i++)
        {
            free(G->Matrix[i]);
        }
        free(G->Matrix);
        free(G->Mark);
        free(G);
        printf("%d\n", m);
    }

    return 0;
}

Graph *create_graph(int V)
{
    Graph *G = (Graph *)malloc(sizeof(Graph));
    G->Matrix = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
    {
        G->Matrix[i] = (int *)malloc(V * sizeof(int));
    }
    G->E = 0;
    G->Mark = (int *)malloc(V * sizeof(int));
    G->V = V;
    return G;
}

int first(Graph *G, int v)
{
    for (int i = 0; i < G->V; i++)
    {
        if (G->Matrix[v][i] != 0)
        {
            return i;
        }
    }
    return G->V;
}

int next(int v, int w, Graph *G)
{
    for (int i = w + 1; i < G->V; i++)
    {
        if (G->Matrix[v][i] != 0)
        {
            return i;
        }
    }
    return G->V;
}

void setEdge(Graph *G, int v, int w)
{
    if (G->Matrix[v][w] == 0)
    {
        G->Matrix[v][w] = G->Matrix[w][v] = 1;
        G->E++;
    }
}

void setMark(Graph *G, int v, int val)
{
    G->Mark[v] = val;
}

int getMark(Graph *G, int v)
{
    return G->Mark[v];
}

void DFS(Graph *G, int v)
{
    setMark(G, v, 1);
    int w = first(G, v);
    while (w < G->V)
    {
        if (getMark(G, w) == 0)
        {
            DFS(G, w);
        }
        w = next(v, w, G);
    }
}