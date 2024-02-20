#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> adj[10001];
int in_degree[10001];
int n, m, x, y;
vector<int> path;
set<int> ss;
int cnt = 0;

void bfs_topo()
{
	while(!ss.empty())
	{
		cnt++;
		int u = *ss.begin();
		ss.erase(ss.begin());
		path.push_back(u);
		for(int i = 0; i < adj[u].size(); i++)
		{
			in_degree[adj[u][i]]--;
			if(!in_degree[adj[u][i]])
			{
				ss.insert(adj[u][i]);
			}
		}
	}
}

int main()
{
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		cin >> y;
		adj[x].push_back(y);
	    in_degree[y]++;
	}
	for(int i = 1; i <= n; i++)
	{
		if(!in_degree[i])
		{
			ss.insert(i);
		}
	}
	bfs_topo();
	
	if(cnt != n)
	{
		printf("Sandro fails.");
	}
	else
	{
	    for(int i = 0; i < path.size(); i++)
	    {
		    printf("%d ",path[i]);
	    }
	}
	
   	return 0;
}