#include <stdio.h>
#include <stdlib.h>

// Utilizaremos como base o algoritmo de Grafo como Lista de Adjacência da pasta Algorithm/Graph;
#include "../Graph/Graph List.c" // As funções de "../Graph/Graph Matrix.c" também funciona nessa Busca;

void graphTraverse(Graph *G)                    // Algoritmo genérico de busca;
{
    int i;
    for (i = 0; i < G->V; i++)
    {
        setMark(G, i, 0);                       // Inicializa o vetor de marcação como 0 para não visitado ainda;
    }
    for (i = 0; i < G->V; i++)
    {
        if (!getMark(G, i))
        {
            // Tipo de busca;
        }
    }
}

// Algortimos de Busca;

// Busca em Profundidade (Depth-First Search [DFS]);

void DFS(Graph *G, int v)
{
    // Alguma coisa antes de começar a visitar o vértice (preVisit(G, v));
    setMark(G, v, 1);                           // Marca o vértice como visitado;
    int w = first(G, v);                        // Pega o primeiro vértice adjacente;
    while (wgetMark
}