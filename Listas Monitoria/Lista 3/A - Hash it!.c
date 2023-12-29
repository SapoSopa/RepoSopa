#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char key[16];
    int full;
} node;

int h (char *k);
int Hash (char *k);
int find (node *H, char *k);
void add (node *H, char *k, int *cnt);
void del (node *H, char *k, int *cnt);

int main ()
{
    int t;
    int n;
    char key[16], op[4];
    node H[101];
    scanf ("%d", &t);
    while (t--)
    {
        int cnt = 0;
        for (int i = 0; i < 101; i++)
        {
            H[i].full = 0;
        }
        scanf ("%d", &n);
        while (n--)
        {
            scanf (" %4[^:]:%s", op, key);
            if (strcmp (op, "ADD") == 0)
            {
                add (H, key, &cnt);
            }
            else if (strcmp (op, "DEL") == 0)
            {
                del (H, key, &cnt);
            }
        }
        printf ("%d\n", cnt);
        for (int i = 0; i < 101; i++)
        {
            if (H[i].full == 1)
            {
                printf ("%d:%s\n", i, H[i].key);
            }
        }
    }

    return 0;
}

int h (char *k)
{
    int sum = 0;
    for (int i = 0; k[i] != '\0'; i++)
    {
        sum += k[i] * (i + 1);
    }
    return sum * 19;
}

int Hash (char *k)
{
    return h (k) % 101;
}

int find (node *H, char *k)
{
    int i = Hash (k);
    int j = 0;
    int found = 0;
    while (found == 0 && j < 20)
    {
        if (H[i].full == 1 && strcmp (H[i].key, k) == 0)
        {
            found = 1;
        }
        else
        {
            j++;
            i = (((Hash (k))+j*(j+23)) % 101);
        }
    }
    if (found == 1)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

void add (node *H, char *k, int *cnt)
{
    if (*cnt < 102 && find (H, k) == -1)
    {
        int i = Hash (k);
        int j = 0;
        while (H[i].full == 1 && j < 19)
        {
            j++;
            i = (((Hash (k))+j*(j+23)) % 101);
        }
        if (H[i].full == 0)
        {
            strcpy (H[i].key, k);
            H[i].full = 1;
            (*cnt)++;
        }
    }
}

void del (node *H, char *k, int *cnt)
{
    int i = find (H, k);
    if (i != -1)
    {
        H[i].full = 0;
        (*cnt)--;
    }
}