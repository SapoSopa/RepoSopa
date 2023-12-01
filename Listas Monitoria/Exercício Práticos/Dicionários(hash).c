#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node {
    int key;
    int value;
    int full;
}node;

typedef struct Dictionary {
    int m;
    int cnt;
    int *perm;
    node *array;
}Dictionary;

Dictionary *createDictionary(int m);
void clearDictionary(Dictionary *d);
int h(int key, int m);
void add(Dictionary *d, int key, int value);
void find(Dictionary *d, int key);

int main()
{
    int m;
    scanf("%d", &m);
    while(m != 0)
    {
        Dictionary *d = createDictionary(m);
        int n;
        int key;
        int value;
        char operacao[5];
        for (int i = 0; i < d->m-1; i++)
        {
            scanf("%d", &d->perm[i]);
        }
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf(" %s", operacao);
            if (strcmp(operacao, "add") == 0)
            {
                scanf("%d %d", &key, &value);
                add(d, key, value);
            }
            else if (strcmp(operacao, "find") == 0)
            {
                scanf("%d", &key);
                find(d, key);
            }
        }
        clearDictionary(d);
        scanf("%d", &m);
    }

    return 0;
}

Dictionary *createDictionary(int m)
{
    Dictionary *d = (Dictionary*)malloc(sizeof(Dictionary));
    d->m = m;
    d->cnt = 0;
    d->perm = (int*)malloc(sizeof(int)*m-1);
    d->array = (node*)malloc(sizeof(node)*m);
    for (int i = 0; i < m; i++)
    {
        d->array[i].full = 0;
    }
    return d;
}

void clearDictionary(Dictionary *d)
{
    free(d->perm);
    free(d->array);
    free(d);
}

int h(int key, int m)
{
    int temp = (int)floor(((double)key)/((double)m));
    return (key - (temp*m));
}

void add(Dictionary *d, int key, int value)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int ok = 0;
    int hkey = h(key, d->m);
    while (i < d->m && ok == 0 && d->cnt < d->m)
    {
        if (d->array[hkey].full == 0)
        {
            d->array[hkey].key = key;
            d->array[hkey].value = value;
            d->array[hkey].full = 1;
            d->cnt++;
            ok = 1;
        }
        else
        {
            if (d->array[hkey].key == key)
            {
                ok = 1;
            }
            else
            {
                j = d->perm[k];
                k++;
                hkey = (h(key, d->m) + j)%(d->m);
            }
        }
        i++;
    }
}

void find(Dictionary *d, int key)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int ok = 0;
    int hkey = h(key, d->m);
    while (i < d->m && ok == 0)
    {
        if (d->array[hkey].full == 0)
        {
            ok = 1;
            printf("-1\n");
        }
        else
        {
            if (d->array[hkey].key == key)
            {
                printf("%d %d\n", hkey, d->array[hkey].value);
                ok = 1;
            }
            else
            {
                j = d->perm[k];
                k++;
                hkey = (h(key, d->m) + j)%(d->m);
            }
        }
        i++;
    }
    if (ok == 0)
    {
        printf("-1\n");
    }
}