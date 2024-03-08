//Implementação de Dijkstra em C++, tente usar mais essa, pois provavelmente será mais concisa, rápida e correta;
// Um algoritmo para encontrar o menor caminho em um grafo ponderado entre um vértice inicial e todos os outros vértices;
// O algoritmo de Dijkstra é um algoritmo guloso que resolve o problema do caminho mais curto para um grafo dirigido ou não dirigido com arestas NÃO NEGATIVAS;
// O algoritmo mantém uma lista de vértices para os quais o menor caminho já é conhecido;
// O algoritmo continua a estender essa lista um vértice de cada vez até que ele contenha todos os vértices do grafo;

#include <iostream>
#include <vector>           //Serve para usar o vetor que será usado para armazenar as distâncias;
#include <queue>            //Serve para usar a fila de prioridade que será usada para a implementação do algoritmo;
#include <climits>          //Serve para te fornecer o Infinito que você precisa para inicializar as distâncias;

using namespace std;

#define INF INT_MAX

void Dijkstra(vector<pair<int,int>> adjGraph[], int s, vector<int>& D)
{
    vector<bool> mark(D.size(), false);
    for (int i = 0; i < D.size(); i++)
    {
        D[i] = INF;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> H;
    D[s] = 0;
    H.push({0, s});
    
    while (!H.empty()) 
    {
        int u = H.top().second;
        H.pop();
        if (mark[u]) continue;
        mark[u] = true;

        for (auto x : adjGraph[u]) {
            int v = x.first;
            int weight = x.second;

            if (!mark[v] && D[v] > D[u] + weight) {
                D[v] = D[u] + weight;
                H.push({D[v], v});
            }
        }
    }
}