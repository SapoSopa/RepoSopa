#include <iostream>
#include <vector>
#include <queue>
#include <climits>

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

int main()
{
    int N, n, m, S, T;
    scanf("%d", &N);
    int cnt = 1;
    while (N--)
    {
        scanf("%d %d %d %d", &n, &m, &S, &T);
        vector<pair<int,int>> adjGraph[n];
        vector<int> D(n);
        while (m--)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            adjGraph[u].push_back({v, w});
            adjGraph[v].push_back({u, w});
        }
        Dijkstra(adjGraph, S, D);
        if (D[T] == INF)
        {
            printf("Case #%d: unreachable\n", cnt++);
        }
        else
        {
            printf("Case #%d: %d\n", cnt++, D[T]);
        }
    }

    return 0;
}