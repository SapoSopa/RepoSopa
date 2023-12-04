#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nome[30];
    int pontos;
} Lista;

void merge(Lista lista[], Lista aux[], int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        aux[i] = lista[i];
    }
    int m = (l + r) / 2;
    int i = l;
    int j = m + 1;
    for (int k = l; k <= r; k++)
    {
        if (i > m)
        {
            lista[k] = aux[j++];
        }
        else if (j > r)
        {
            lista[k] = aux[i++];
        }
        else if (aux[i].pontos <= aux[j].pontos)
        {
            lista[k] = aux[i++];
        }
        else
        {
            lista[k] = aux[j++];
        }
    }
}

void mergesort(Lista lista[], Lista aux[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergesort(lista, aux, l, m);
        mergesort(lista, aux, m + 1, r);
        merge(lista, aux, l, r);
    }
}

int main()
{
    int c;
    scanf("%d", &c);
    Lista lista[c];
    Lista aux[c];
    for (int i = 0; i < c; i++)
    {
        scanf("%s %d", lista[i].nome, &lista[i].pontos);
    }

    mergesort(lista, aux, 0, c - 1);

    for (int i = 0; i < c; i++)
    {
        printf("%s %d\n", lista[i].nome, lista[i].pontos);
    }

    return 0;
}