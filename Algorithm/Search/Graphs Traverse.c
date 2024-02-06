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
// Funciona como uma pilha, caso tente armazenar os vértices visitados;

void DFS(Graph *G, int v)
{
    // Alguma coisa antes de visitar o vértice (preVisit(G, v));
    setMark(G, v, 1);                           // Marca o vértice como visitado;
    int w = first(G, v);                        // Pega o primeiro vértice adjacente;
    while (w < G->V)
    {
        if (!getMark(G, w))
        {
            DFS(G, w);                          // Chama a função recursivamente para visitar o vértice;
        }
        w = next(G, v, w);                      // Pega o próximo vértice adjacente;
    }
    // Alguma coisa depois de visitar o vértice (posVisit(G, v));
}
//// Exemplo de uso;
////// Busca Topológica;
#include "../List/Array Stack.c" // As funções de "../List/Linked List Stack.c" também funciona nessa Busca;
// Executar o graphTraverse para limpar os marcadores;
void toposort(Graph *G, int v, Stack *s)
{
    setMark(G, v, 1);                           // Marca o vértice como visitado;
    int w = first(G, v);                        // Pega o primeiro vértice adjacente;
    while (w < G->V)
    {
        if (!getMark(G, w))
        {
            toposort(G, w, s);                  // Chama a função recursivamente para visitar o vértice;
        }
        w = next(G, v, w);                      // Pega o próximo vértice adjacente;
    }
    push(s, v);                                 // Adiciona o vértice na pilha;
}

// Busca em Largura (Breadth-First Search [BFS]);
// Funciona como uma fila, caso tente armazenar os vértices visitados;
#include "../List/Array Queue.c" // As funções de "../List/Linked List Queue.c" também funciona nessa Busca;

void BFS(Graph *G, int v)
{
    Queue *Q = createQueue(G->V);               // Cria a fila com o tamanho do número de vértices;
    enqueue(Q, v);                              // Adiciona o vértice na fila;
    setMark(G, v, 1);                           // Marca o vértice como visitado;
    while (sizeQueue(Q) > 0)
    {
        int v = dequeue(Q);                     // Remove o vértice da fila;
        // Alguma coisa antes de visitar o vértice (preVisit(G, v));
        int w = first(G, v);                    // Pega o primeiro vértice adjacente;
        while (w < G->V)
        {
            if (!getMark(G, w))
            {
                setMark(G, w, 1);               // Marca o vértice como visitado;
                enqueue(Q, w);                  // Adiciona o vértice na fila;
            }
            w = next(G, v, w);                  // Pega o próximo vértice adjacente;
        }
        // Alguma coisa depois de visitar o vértice (posVisit(G, v));
    }
}
// Exemplo de uso;
//// Busca de Menor Caminho em Grafos Não-Ponderados;
//// Acrescentar ao grafo um "int *pred" para armazenar o um dos predecessores do vértice;
// Executar o graphTraverse para limpar os marcadores;
void setRoute(int *pred, int start, int end)
{
    if (start == end || end == -1)
    {
        printf("%d ", start);                   // Alguma operação no vértice;
    }
    else
    {
        setRoute(pred, start, pred[end]);       // Chama a função recursivamente para visitar o vértice;
        printf("%d ", end);                     // Alguma operação no vértice;
    }
}

void MenorCaminho(Graph *G, int v, int *pred)   //Define-se o começo como vértice 0 e o fim como vértice G->V - 1;
{
    Queue *Q = createQueue(G->V);               // Cria a fila com o tamanho do número de vértices;
    enqueue(Q, v);                              // Adiciona o vértice na fila;
    setMark(G, v, 1);                           // Marca o vértice como visitado;
    while (sizeQueue(Q) > 0)
    {
        int v = dequeue(Q);                     // Remove o vértice da fila;
        int w = first(G, v);                    // Pega o primeiro vértice adjacente;
        while (w < G->V)
        {
            if (!getMark(G, w))
            {
                setMark(G, w, 1);               // Marca o vértice como visitado;
                pred[w] = v;                    // Armazena o predecessor do vértice;
                enqueue(Q, w);                  // Adiciona o vértice na fila;
            }
            w = next(G, v, w);                  // Pega o próximo vértice adjacente;
        }
    }
    setRoute(pred, 0, G->V - 1);                // Usa o caminho, nesse caso, imprimindo no terminal;
}
