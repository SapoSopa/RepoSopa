#include <stdio.h>
#include <stdlib.h>
//Componentes de uma lista;
//O tipo int pode ser alterado para qualquer outro tipo;

typedef struct Node{            //A estrutura do nó pode ser alterada para registrar também
    int value;                  //um ponteiro para o elemento anterior, o que facilitaria a
    struct Node *next;          //busca, ao implementar de uma lista duplamente encadeada.
} Node;

typedef struct List{
    Node *head;
    Node *tail;
    Node *curr;
    int size;
} List;

//Funções de manipulação de listas;
//O tipo int pode ser alterado para qualquer outro tipo;

Node *createNode (int value, Node *next);
Node *createNodeHeader (Node *next);
List *createList ();
void clear (List *list);
void insert (List *list, int value);
void append (List *list, int value);
int remove (List *list);
void moveToStart (List *list);
void moveToEnd (List *list);
void prev (List *list);
void next (List *list);
int length (List *list);
int currPos (List *list);
void moveToPos (List *list, int pos);
int getValue (List *list);

//Funções de manipulação de listas;

Node *createNode (int value, Node *next)            //Caso haja um node->prev, ele deve ser inserido
{                                                   //como parâmetro da função similar o node->next;
    Node *node = (Node*)malloc(sizeof(Node));   
    node->value = value;
    node->next = next;
    return node;
}

Node *createNodeHeader (Node *next)                 
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->next = next;
    return node;
}

List *createList ()
{
    List *list = (List*)malloc(sizeof(List));
    list->head = createNodeHeader(NULL);
    list->tail = list->head;
    list->curr = list->head;
    list->size = 0;
    return list;
}

void clear (List *list)
{
    list->curr = list->head;
    while (list->head != NULL)
    {
        list->curr = list->head;
        list->head = list->head->next;
        free(list->curr);
    }
    free(list);
}

void insert (List *list, int value)
{
    Node *node = createNode(value, list->curr->next);
    list->curr->next = node;
    if (list->curr == list->tail)
    {
        list->tail = node;
    }
    list->size++;
}

void append (List *list, int value)
{
    list->tail->next = createNode(value, NULL);
    list->tail = list->tail->next;
    list->size++;
}

int remove (List *list)
{
    if (list->curr->next == NULL)
    {
        return 0;
    }
    Node *temp = list->curr->next;
    list->curr->next = temp->next;
    if (temp == list->tail)
    {
        list->tail = list->curr;
    }
    free(temp);
    list->size--;
    return list->curr->next->value;
}

void moveToStart (List *list)
{
    list->curr = list->head;
}

void moveToEnd (List *list)
{
    list->curr = list->tail;
}

void prev (List *list)                          //Caso haja um node->prev, essa função se torna-se
{                                               //mais simples, apenas verificar se não está no head
    if (list->curr != list->head)               //e colocar o curr como curr->prev;
    {
        Node *temp = list->head;
        while (temp->next != list->curr)
        {
            temp = temp->next;
        }
        list->curr = temp;
        free(temp);
    }
}

void next (List *list)
{
    if (list->curr != list->tail)
    {
        list->curr = list->curr->next;
    }
}

int length (List *list)
{
    return list->size;
}

int currPos (List *list)                        //Caso haja um node->prev, ele pode ser utilizado
{                                               //contando a distância dele a head ou a tail;
    Node *temp = list->head;
    int i = 0;
    while (temp != list->curr)
    {
        temp = temp->next;
        i++;
    }
    free(temp);
    return i;
}

void moveToPos (List *list, int pos)
{
    if (pos >= 0 && pos <= list->size)
    {
        list->curr = list->head;
        for (int i = 0; i < pos; i++)
        {
            list->curr = list->curr->next;
        }
    }
}

int getValue (List *list)
{
    if (list->curr->next == NULL)
    {
        return 0;
    }
    return list->curr->next->value;
}