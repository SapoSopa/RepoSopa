#include <stdio.h>
#include <stdlib.h>
//Componentes de um dicionário;
//O value e a key tipo int pode ser alterado para outro tipo;
//Nesse dicionário, cada array[i] é apenas um elemento, não uma lista;

typedef struct Node{
    int key;
    int value;
    int full;
} Node;

typedef struct Dictionary{
    int m;
    int cnt;
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
    d->array = (Node*)malloc(sizeof(Node)*m);
    for (int i = 0; i < m; i++)
    {
        d->array[i].full = 0;
    }
    return d;
}

int h (int key, int m)
{
    //A função hash pode ser alterada para qualquer função, mas ela deve ser retornada;
    //As entradas da função hash devem conter a key obrigatoriamente, mas o int m pode ser modificado;
    return /*função hash*/;
}

void clearDictionary (Dictionary *d)
{
    free(d->array);
    free(d);
}

void insert (Dictionary *d, int key, int value)
{
    int i = h(key, d->m);
    if (d->array[i].full == 0)
    {
        d->array[i].key = key;
        d->array[i].value = value;
        d->array[i].full = 1;
        d->cnt++;
    }
    else
    {
        //Alguma mensagem de lugar ocupado ou apenas não realizar nada, depende do objetivo;
    }
}

int remove (Dictionary *d, int key)
{
    int i = h(key, d->m);
    if (d->array[i].full == 1)
    {
        d->array[i].full = 0;
        d->cnt--;
        return d->array[i].value;
    }
    else
    {
        //Alguma mensagem de erro de operação;
    }
}

int find (Dictionary *d, int key)
{
    int i = h(key, d->m);
    if (d->array[i].full == 1)
    {
        return d->array[i].value;
    }
    else
    {
        //Alguma mensagem de erro de operação;
    }
}

int size (Dictionary *d)
{
    return d->cnt;
}