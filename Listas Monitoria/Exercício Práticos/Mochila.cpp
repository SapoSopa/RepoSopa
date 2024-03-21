#include <iostream>
#include <vector>

using namespace std;

int Mochilinha(int n, int W, vector<int>& peso, vector<int>& valor, vector<vector<int>>& Mochila)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                Mochila[i][j] = 0;
            }
            else if (peso[i-1] <= j)
            {
                Mochila[i][j] = max(valor[i-1] + Mochila[i - 1][j - peso[i-1]], Mochila[i - 1][j]);
            }
            else
            {
                Mochila[i][j] = Mochila[i - 1][j];
            }
        }        
    }
    return Mochila[n][W];
}

int main()
{
    int c, W, n, w, v;
    scanf("%d",&c);
    while (c--)
    {
        scanf("%d", &W);
        scanf("%d", &n);
        vector<vector<int>> Mochila(n+1, vector<int>(W+1));
        vector<int> peso(n), valor(n);

        for(int i=0; i<n; i++)
        {
            scanf("%d %d", &w, &v);
            peso[i] = w;
            valor[i] = v;            
        }
        int melhor = 0;
        melhor = Mochilinha(n, W, peso, valor, Mochila);
        printf("%d\n", melhor);
    }

    return 0;
}