#include <iostream>
#include <vector>

using namespace std;

void funcSubs(vector<int> &v, int d, int &count, int &Somarestante, int initial)
{
    if (Somarestante < d)
    {
        return;
    }
    if (Somarestante == d)
    {
        count++;
        return;
    }
    for (int i = initial; i < v.size(); i++)
    {
        if (Somarestante == d)
        {
            count++;
        }
        else
        {
            Somarestante -= v[i];
            funcSubs(v, d, count, Somarestante, i + 1);
            Somarestante += v[i];
        }
    }
}

int main()
{
    int c, n, d;
    scanf("%d", &c);
    while (c--)
    {
        scanf("%d", &n);
        vector<int> v(n);
        int Somarestante = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &v[i]);
            Somarestante += v[i];
        }
        scanf("%d", &d);
        int count = 0;
        funcSubs(v, d, count, Somarestante, 0);
        printf("%d\n", count);
    }
    return 0;
}