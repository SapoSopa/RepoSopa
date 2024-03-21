#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Mochilinha(int n, int W, int* peso, int* valor, int** Mochila);

int main()
{
    int S, N, w, v;
    scanf("%d %d", &S, &N);
    int** Mochila = (int**)malloc((N+1) * sizeof(int*));
    for(int i = 0; i <= N; i++)
    {
        Mochila[i] = (int*)malloc((S+1) * sizeof(int));
    }
    int* peso = (int*)malloc(N * sizeof(int));
    int* valor = (int*)malloc(N * sizeof(int));
    for(int i=0; i < N; i++)
    {
        scanf("%d %d", &w, &v);
        peso[i] = w;
        valor[i] = v;            
    }
    int melhor = 0;
    melhor = Mochilinha(N, S, peso, valor, Mochila);
    printf("%d\n", melhor);
   
    free(peso);
    free(valor);
    for(int i = 0; i <= N; i++)
    {
        free(Mochila[i]);
    }
    free(Mochila);

    return 0;
}

int Mochilinha(int n, int W, int* peso, int* valor, int** Mochila)
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
                Mochila[i][j] = fmax(valor[i-1] + Mochila[i - 1][j - peso[i-1]], Mochila[i - 1][j]);
            }
            else
            {
                Mochila[i][j] = Mochila[i - 1][j];
            }
        }        
    }
    
    return Mochila[n][W];
}