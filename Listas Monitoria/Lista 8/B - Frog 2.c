#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int h[N+1];
    int mc[N+1];

    for (int i = 1; i <= N; ++i) {
        scanf("%d", &h[i]);
        mc[i] = INF;
    }

    mc[1] = 0;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = i + 1; j <= i + K && j <= N; ++j)
        {    
            if(mc[j] > mc[i] + abs(h[i] - h[j]))
            {
                mc[j] = mc[i] + abs(h[i] - h[j]);
            }
        }
    }

    printf("%d\n", mc[N]);

    return 0;
}