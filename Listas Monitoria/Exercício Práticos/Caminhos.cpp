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
    int c, v, a, i, j, w, s;
    scanf("%d", &c);
    for (int k = 1; k <= c; k++)
    {
        scanf("%d %d", &v, &a);
        vector<pair<int,int>> G[v];
        vector<int> D(v);
        while (a--)
        {
            scanf("%d %d %d", &i, &j, &w);
            G[i].push_back({i, w});
            G[j].push_back({j, w});
        }
        scanf("%d", &s);
        Dijkstra(G, s, D);
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