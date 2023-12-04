#include <stdio.h>
#include <string.h>

char binarySearch(char estudante[][30], char nome[30], int i, int j)
{
    if (j >= i)
    {
        int m = (i + j)/2;
        if (strcmp(estudante[m], nome) == 0)
        {
            printf("+\n");
            return 0;
        }
        else if (strcmp(estudante[m], nome) > 0)
        {
            return binarySearch(estudante, nome, i, m - 1);
        }
        else
        {
            return binarySearch(estudante, nome, m + 1, j);
        }
    }
    else
    {
        printf("-\n");
        return -1;
    }
}

int main()
{
    int e;
    scanf("%d", &e);
    char estudante[e][30];
    for(int i = 0; i < e; i++)
    {
        scanf("%s", estudante[i]);
    }
    int q;
    scanf("%d", &q);
    char nome[q][30];
    for(int i = 0; i < q; i++)
    {
        scanf("%s", nome[i]);
    }

    for(int i = 0; i < q; i++)
    {
        binarySearch(estudante, nome[i], 0, e);
    }

    return 0;
}

