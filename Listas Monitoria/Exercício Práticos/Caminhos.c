//refazer em C++
#include <stdio.h>
#include <stdlib.h>

#define INF 2000010

typedef struct heap{
    int v;
    int dist;
} heap;

typedef struct Node{
    int v;
    int weight;
    struct Node *next;
} Node;

typedef struct Graph
{
    Node **List;
    int V;
    int *mark;
} Graph;

Node *createNode(int v, int w);
Graph *createGraph(Graph *G, int v);
void setMark(Graph *G, int v, int val);
void insertEdge(Graph *G, int v1, int v2, int w);
void heapifyBU(heap H[], int size);
void deleteHBU(heap H[], int *size);
void Dijkstra(Graph *G, int s, int d[], heap H[]);

int main()
{
    int c, v, a, i, j, w, s;
    scanf("%d", &c);
    for (int k = 1; k <= c; k++)
    {
        scanf("%d %d", &v, &a);
        Graph *G = createGraph(G, v);
        int D[v];
        heap H[v + 1];
        for (int x = 0; x < v; x++)
        {
            D[x] = INF;
            H[x+1].v = x;
            H[x].dist = INF;
        }
        while (a--)
        {
            scanf("%d %d %d", &i, &j, &w);
            insertEdge(G, i, j, w);
        }
        scanf("%d", &s);
        Dijkstra(G, s, D, H);
        printf("Caso %d\n", k);
        for (int x = 0; x < v; x++)
        {
            if (D[x] == INF)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", D[x]);
            }
        }
    }
    return 0;
}

Node *createNode(int v, int w)
{
    Node *N = (Node*)malloc(sizeof(Node));
    N->v = v;
    N->weight = w;
    N->next = NULL;
    return N;
}

Graph *createGraph(Graph *G, int v)
{
    G = (Graph*)malloc(sizeof(Graph));
    G->List = (Node**)malloc(v * sizeof(Node*));
    G->V = v;
    G->mark = (int*)malloc(v * sizeof(int));
    for (int i = 0; i < v; i++)
    {
        G->List[i] = NULL;
        G->mark[i] = 0;
    }
    return G;
}

void insertEdge(Graph *G, int v1, int v2, int w)
{
    Node *N = G->List[v1];
    Node *Nv = createNode(v2, w);
    if (N == NULL)
    {
        G->List[v1] = Nv;
    }
    else
    {
        while (N->next != NULL)
        {
            N = N->next;
        }
        N->next = Nv;
    }
}

void heapifyBU(heap H[], int size)
{
    for (int i = size / 2; i > 0; i--)
    {
        int j;
        int k = i;
        heap v = H[k];
        int heapfy = 0;
        while (heapfy == 0 && 2 * k <= size)
        {
            j = 2 * k;
            if (j < size)
            {
                if (H[j].dist > H[j + 1].dist)
                {
                    j++;
                }
            }
            if (v.dist <= H[j].dist)
            {
                heapfy = 1;
            }
            else
            {
                H[k] = H[j];
                k = j;
            }
        }
        H[k] = v;
    }
}

void deleteHBU(heap H[], int *size)
{
    heap v = H[1];
    H[1] = H[*size];
    H[*size] = v;
    (*size)--;
    heapifyBU(H, *size);
}

void Dijkstra(Graph *G, int s, int d[], heap H[])
{
    int size = G->V;
    d[s] = 0;
    H[s + 1].dist = 0;
    heapifyBU(H, size);
    while (size > 0)
    {
        int u = H[1].v;
        deleteHBU(H, &size);
        G->mark[u] = 1;
        Node *N = G->List[u];
        while (N != NULL)
        {
            int v = N->v;
            if (!G->mark[v] && d[u] + N->weight < d[v])
            {
                d[v] = d[u] + N->weight;
                for (int i = 1; i <= size; i++)
                {
                    if (H[i].v == v)
                    {
                        H[i].dist = d[v];
                    }
                }
                heapifyBU(H, size);
            }
            N = N->next;
        }
    }
}