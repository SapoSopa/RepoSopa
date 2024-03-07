// Aparentemente essa implementação está lenta demais, acredito que a melhor forma de trabalhar com esse Algoritmo seja com a biblioteca de C++;
#include <stdio.h>
#include <stdlib.h>
#include "../Graph/Graph List.c"// Estrutura para representar um grafo ponderado (usaremos uma lista de adjacência);
#include "../Tree/Heap Array-Based.c"// Estrutura para representar uma fila de prioridade (usaremos uma heap array-based);
// Um algoritmo para encontrar o menor caminho em um grafo ponderado entre um vértice inicial e todos os outros vértices;
// O algoritmo de Dijkstra é um algoritmo guloso que resolve o problema do caminho mais curto para um grafo dirigido ou não dirigido com arestas NÃO NEGATIVAS;
// O algoritmo mantém uma lista de vértices para os quais o menor caminho já é conhecido;
// O algoritmo continua a estender essa lista um vértice de cada vez até que ele contenha todos os vértices do grafo;

#define INFINITY 1000000 // Valor grande o suficiente para representar o infinito;

typedef struct heap{
    int V; // Número de vértices;
    int minDist; // Peso da aresta;
}HeapNode;

void Dijkstra (Graph *G, int s, int *D, int *P)
{
    int size = G->V;                                // Tamanho do grafo;
    HeapNode H[size + 1];                               // Mapear cada vértice para sua distância na heap;
    for (int i = 0; i < G->V; i++)
    {
        D[i] = INFINITY;                            // Inicializa o vetor de distâncias com infinito;
        P[i] = -1;                                  // Inicializa o vetor de predecessores com -1;
        H[i + 1].V = i;                             // Inicializa a fila de prioridade com os vértices do grafo;
        H[i + 1].minDist = INFINITY;                // Inicializa a fila de prioridade com as distâncias do grafo;
        setMark(G, i, 0);                           // Inicializa o vetor de marcação com 0 para não visitado;
    }

    D[s] = 0;                                       // A distância do vértice inicial para ele mesmo é 0;
    H[s + 1].minDist = 0;                           // Atualiza a distância do vértice inicial no array;
    heapifyBU(H, size);                             // Transforma a fila de prioridade em uma heap Mínima;

    while (size > 0)
    {
        int u = H[1].V;                             // Remove o vértice com a menor distância;
        deleteHBU(H, &size);
        setMark(G, u, 1);                           // Marca o vértice como visitado;

        for (Node *e = G->List[u]; e != NULL; e = e->next)
        {
            int v = e->v;                           // Vértice adjacente;
            if (!getMark(G, v) && D[u] + e->weight < D[v])
            {
                D[v] = D[u] + e->weight;            // Atualiza a distância;
                P[v] = u;                           // Atualiza o predecessor;
                int stop = 1;                       // Variável de controle para parar a busca;
                for (int i = 1; i <= size && stop; i++)
                {
                    if (H[i].V == v)
                    {
                        H[i].minDist = D[v];        // Atualiza a distância na heap;
                        stop = 0;                   // Para a busca;
                    }
                }
                heapifyBU(H, size);                 // Transforma a fila de prioridade em uma heap Mínima;
            }
        }   
    }
}