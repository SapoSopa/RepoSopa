#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

void primMST(vector<pair<int, int>> adj[], int V, vector<int>& D) 
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> H;
    for (int i = 0; i < V; i++) 
    {
        D[i] = INF;
    }
    
    vector<int> parent(V, -1);
    vector<bool> mark(V, false);

    H.push({0, {0, 0}});
    D[0] = 0;

    while (!H.empty())
    {
        int u = H.top().second.first;
        H.pop();

        mark[u] = true;

        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;

            if (!mark[v] && D[v] > weight)
            {
                D[v] = weight;
                H.push({D[v], {v, u}});
                parent[v] = u;
            }
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    while (n || m)
    {
        vector<pair<int, int>> G[n];
        vector<int> D(n);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        primMST(G, n, D);
        int all = 0;
        for (int i = 0; i < n; i++)
        {
            if (D[i] > all)
            {
                all = D[i];
            }
        }
        if (all == INF)
        {
            printf("IMPOSSIBLE\n");
        }
        else
        {
            printf("%d\n", all);
        }
        scanf("%d %d", &n, &m);
    }

    return 0;
}