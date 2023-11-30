#include <stdio.h>
#include <stdlib.h>
//Componentes de uma lista;
//O array tipo int pode ser alterado para qualquer outro tipo;

typedef struct List{
    int *array;
    int size;
    int capacity;
    int curr;
} List;

//Funções de manipulação de listas;
//O value tipo int, que depende do array int, pode ser alterado para qualquer outro tipo, desde que juntos;

List *createList (int capacity);            //cria uma lista com capacidade inicial;
void clear (List *list);                    //limpa a lista da memória;
void resize (List *list, int newcapacity);  //redimensiona a lista para um novo valor;
void append (List *list, int value);        //adiciona um elemento ao final da lista e dobra o tamanho se necessário;
void insert (List *list, int value);        //adiciona um elemento na posição atual da lista e dobra o tamanho se necessário;
void prev (List *list);                     //move o cursor para a posição anterior da lista;
void next (List *list);                     //move o cursor para a posição seguinte da lista;
void moveToPos (List *list, int pos);       //move o cursor para uma posição específica da lista;
int currPos (List *list);                   //retorna a posição atual do cursor na lista;
int remove (List *list);                    //remove e retorna o elemento da posição atual da lista e divide o tamanho se possível;
int length (List *list);                    //retorna o tamanho da lista;
int getValue (List *list);                  //retorna o elemento da posição atual da lista;

//Funções de manipulação de listas;

List *createList (int capacity)
{
    List *list = (List*)malloc(sizeof(List));
    list->array = (int*)malloc(sizeof(int)*capacity);
    list->size = 0;
    list->capacity = capacity;
    list->curr = 0;
    return list;
}

void clear (List *list)
{
    free(list->array);
    free(list);
}

void resize (List *list, int newcapacity)
{
    int *newArray = realloc(list->array, sizeof(int)*newcapacity);
    if (newArray != NULL)
    {
        list->array = newArray;
        list->capacity = newcapacity;
        free(newArray);
    }
    else
    {
        //Alguma mensagem de erro;
    }    
}

void append (List *list, int value)
{
    if (list->size == list->capacity)
    {
        resize(list, list->capacity*2);
    }
    list->array[list->size++] = value;
}

void insert (List *list, int value)
{
    if (list->size == list->capacity)
    {
        resize(list, list->capacity*2);
    }
    for (int i = list->size; i > list->curr; i--)
    {
        list->array[i] = list->array[i-1];
    }
    list->array[list->curr] = value;
    list->size++;
}

void prev (List *list)
{
    if (list->curr != 0)
    {
        list->curr--;
    }
    else
    {
        //Alguma mensagem de erro;
    }
}

void next (List *list)
{
    if (list->curr != list->size)
    {
        list->curr++;
    }
    else
    {
        //Alguma mensagem de erro;
    }
}

void moveToPos (List *list, int pos)
{
    if (pos >= 0 && pos <= list->size)
    {
        list->curr = pos;
    }
    else
    {
        //Alguma mensagem de erro;
    }
}

int currPos (List *list)
{
    return list->curr;
}

int remove (List *list)
{
    if (list->size == 0)
    {
        //Alguma mensagem de erro;
    }
    int value = list->array[list->curr];
    for (int i = list->curr; i < list->size-1; i++)
    {
        list->array[i] = list->array[i+1];
    }
    list->size--;
    if (list->size <= list->capacity/4)
    {
        resize(list, list->capacity/2);
    }
    return value;
}

int length (List *list)                        
{
    return list->size;
}

int getValue (List *list)                      
{
    return list->array[list->curr];
}