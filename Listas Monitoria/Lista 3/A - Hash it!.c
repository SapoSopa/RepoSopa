#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char key[16];
    int full;
} node;

typedef struct hash {
    int cnt;
    node *table[101];
} hash;

hash *createHash ();
int h (char *k);
int Hash (char *k);
int find (hash *H, char *k);
void add (hash *H, char *k);
void del (hash *H, char *k);
void print (hash *H);

int main ()
{
    int t;
    int n;
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
    for (i = 0; i < 101; i++)
    {
        H->table[i] = (node *) malloc(sizeof(node));
        H->table[i]->full = 0;
    }
    return H;
}

int h (char *k)
{
    int i;
    int sum = 0;
    for (i = 0; i < strlen(k); i++)
    {
        sum += (i+1)*k[i];
    }
    return 19*sum;
}

int Hash (char *k)
{
    return ((h(k))%101);
}

int find (hash *H, char *k)
{
    int i = Hash(k);
    int j = 0;
    while (j <= 19)
    {
        if (strcmp(H->table[i]->key, k) == 0)
        {
            return 0;
        }
        j++;
        i = ((Hash(k)+j*j+23*j)%101);
    }
    return 1;
}

void add (hash *H, char *k)
{   
    if (H->cnt <= 101 && find(H, k))
    {
        int i = Hash(k);
        int j = 0;
        while (H->table[i]->full == 1 && j <= 19)
        {
            j++;
            i = ((Hash(k)+j*j+23*j)%101);
        }
        strcpy(H->table[i]->key, k);
        H->table[i]->full = 1;
        H->cnt++;
    }
}

void del (hash *H, char *k)
{
    if (H->cnt > 0)
    {
        int i = Hash(k);
        int j = 0;
        int deleted = 0;
        while (j <= 19 && deleted == 0)
        {
            if (strcmp(H->table[i]->key, k) == 0)
            {
                H->table[i]->full = 0;
                H->cnt--;
                deleted = 1;
            }
            j++;
            i = ((Hash(k)+j*j+23*j)%101);
        }
    
    }
}

void print (hash *H)
{
    int i;
    printf("%d\n", H->cnt);
    for (i = 0; i < 101 && H->cnt > 0; i++)
    {
        if (H->table[i]->full == 1)
        {
            printf("%d:%s\n", i, H->table[i]->key);
            H->table[i]->full = 0;
            H->cnt--;
        }
    }
}