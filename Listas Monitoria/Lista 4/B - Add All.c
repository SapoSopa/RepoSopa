#include <stdio.h>

int main ()
{
    int n, sum;
    while (scanf("%d", &n), n)
    {
        int a[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        
        printf("%d\n", sum);
    }

    return 0;
}