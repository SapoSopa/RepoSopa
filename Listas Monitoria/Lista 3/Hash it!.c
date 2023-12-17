#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

typedef struct node {
    char key[16];
    int full;
} node;

typedef struct hash {
    int cnt;
    node *table[MAX];
} hash;

hash *createHash ();
int h (char *k);
int Hash (char *k);
void add (hash *H, char *k);
void del (hash *H, char *k);
void clear (hash *H);
void print (hash *H);

int main ()
{
    int t, n;
    char key[16], op[4];
    hash *H = createHash();
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        while (n--)
        {
            scanf(" %4[^:]:%s", op, key);
            if (strcmp(op, "ADD") == 0)
            {
                add(H, key);
            }
            else if(strcmp(op, "DEL") == 0)
            {
                del(H, key);
            }
        }
        print(H);
    }

    return 0;
}

hash *createHash ()
{
    hash *H = (hash *) malloc(sizeof(hash));
    int i;
    H->cnt = 0;
    for (i = 0; i < MAX; i++)
    {
        H->table[i] = (node *) malloc(sizeof(node));
        H->table[i]->full = 0;
    }
    return H;
}

int h (char *k)
{
    int i, sum = 0;
    for (i = 0; i < strlen(k); i++)
    {
        sum += (i+1)*k[i];
    }
    return 19*sum;
}

int Hash (char *k)
{
    return ((h(k))%MAX);
}

void add (hash *H, char *k)
{   
    if (H->cnt < MAX)
    {
        int i = Hash(k);
        int j = 0;
        int added = 0;
        while (H->table[i]->full == 1 && j <= 19 && added == 0)
        {
            if (strcmp(H->table[i]->key, k) == 0)
            {
                added = 1;
            }
            j++;
            i = ((i+j*j+23*j)%MAX);
        }
        if (added == 0)
        {
            strcpy(H->table[i]->key, k);
            H->table[i]->full = 1;
            H->cnt++;
        }
    }
}

void del (hash *H, char *k)
{
    int i = Hash(k);
    int j = 0;
    int deleted = 0;
    while (H->table[i]->full == 1 && j <= 19 && deleted == 0)
    {
        if (strcmp(H->table[i]->key, k) == 0)
        {
            H->table[i]->full = 0;
            H->cnt--;
            deleted = 1;
        }
        j++;
        i = ((i+j*j+23*j)%MAX);
    }
}

void print (hash *H)
{
    int i;
    printf("%d", H->cnt);
    for (i = 0; i < MAX && H->cnt > 0; i++)
    {
        if (H->table[i]->full == 1)
        {
            printf("\n%d:%s", i, H->table[i]->key);
            H->table[i]->full = 0;
            H->cnt--;
        }
    }
}