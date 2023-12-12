#include <stdio.h>
#include <stdlib.h>
//Componentes de um dicionário;
//O value e a key tipo int pode ser alterado para outro tipo;
//Nesse dicionário, cada array[i] é apenas um elemento, não uma lista;
//Será usado o método de hashing fechado, com tratamento de colisão por sondagem pseudo-aleatória;
//O int perm é um array de permutação que é usado para gerar uma permutação "aleatória" de 0 a m-1 e é previamente definido;
//Qualquer outro método de hashing fechado será necessário apenas modificar como se preenche o perm;

typedef struct Node{
    int key;
    int value;
    int full;
} Node;

typedef struct Dictionary{
    int m;
    int cnt;
    int *perm;
    Node *array;
} Dictionary;

//Funções de manipulação de dicionários;
//O value e a key tipo int pode ser alterado para outro tipo;
//O tamanho do dicionário é definido na criação do mesmo;

Dictionary *createDictionary (int m);               //cria um dicionário com m posições;
int h (int key, int m);                             //função hash, seu tipo depende do tipo do value;
void clearDictionary (Dictionary *d);               //limpa o dicionário da memória;
void insert (Dictionary *d, int key, int value);    //insere um elemento no dicionário;
int remove (Dictionary *d, int key);                //remove um elemento do dicionário;
int find (Dictionary *d, int key);                  //retorna o elemento do dicionário;
int size (Dictionary *d);                           //retorna o tamanho do dicionário;

//Funções de manipulação de dicionários;

Dictionary *createDictionary (int m)
{
    Dictionary *d = (Dictionary*)malloc(sizeof(Dictionary));
    d->m = m;
    d->cnt = 0;
    d->perm = (int*)malloc(sizeof(int)*(m-1));      //O array de permutação será preenchido na main;
    d->array = (Node*)malloc(sizeof(Node)*m);
    for (int i = 0; i < m; i++)
    {
        d->array[i].full = 0;
    }
    return d;
}

int h (int key, int m)
{
    //A função hash pode ser alterada para qualquer função;
    return /*função hash*/;
}

void clearDictionary (Dictionary *d)
{
    free(d->perm);
    free(d->array);
    free(d);
}

void insert (Dictionary *d, int key, int value)
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

int remove (Dictionary *d, int key)
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
            //Alguma mensagem de erro;
        }
        else
        {
            if (d->array[hkey].key == key)
            {
                d->array[hkey].full = 0;
                d->cnt--;
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
    return d->array[hkey].value;
}

int find (Dictionary *d, int key)
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
            return /*Alguma mensagem de erro*/;
        }
        else
        {
            if (d->array[hkey].key == key)
            {
                ok = 1;
                return d->array[hkey].value;
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

int size (Dictionary *d)
{
    return d->cnt;
}