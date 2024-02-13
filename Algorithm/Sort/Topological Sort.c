#include <stdio.h>
#include <stdlib.h>
#include "../Graph/Graph List.c"

// Busca Topológica em Grafos Direcionados Acíclicos (Directed Acyclic Graph [DAG]);
// A busca topológica é uma busca em profundidade (DFS) que armazena os vértices visitados em uma pilha;
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