//Implementação de Prim, não há tentativa em C;
// O algoritmo de Prim é um algoritmo guloso que resolve o problema da árvore geradora mínima para um grafo conexo, não dirigido e ponderado;
// O algoritmo mantém uma lista de vértices para os quais a árvore geradora mínima já é conhecida;
// O algoritmo continua a estender essa lista um vértice de cada vez até que ela contenha todos os vértices do grafo;

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

void primMST(vector<pair<int, int>> adj[], int V, vector<int>& D) 
{
    priority_queue<tuple<int, int, int>, vector <tuple<int, int, int>>, greater<tuple<int, int, int>>> H;
    //priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> H;
    for (int i = 0; i < V; i++) 
    {
        D[i] = INF;
    }
    
    vector<int> parent(V, -1);
    vector<bool> mark(V, false);

    H.push({0, 0, 0});
    //H.push({0, {0, 0}});
    D[0] = 0;

    while (!H.empty()) 
    {
        int u = get<1>(H.top());
        //int u = H.top().second.first;
        H.pop();

        if (mark[u]) continue;
        mark[u] = true;

        for (auto x : adj[u]) 
        {
            int v = x.first;
            int weight = x.second;

            if (!mark[v] && D[v] > weight) 
            {
                D[v] = weight;
                H.push({D[v], v, u});
                //H.push({D[v], {v, u}});
                parent[v] = u;
            }
        }
    }
}