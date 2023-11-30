#include <stdio.h>
#include <stdlib.h>

//Componentes de uma Fila (Queue);
//O value tipo int pode ser alterado para qualquer outro tipo;

typedef struct Node{
    int value;
    struct Node *next;
} Node;

typedef struct Queue{
    Node *first;
    Node *last;
    int size;
} Queue;

//Funções de manipulação de filas;
//O value tipo int pode ser alterado para qualquer outro tipo;

Node *createNode (int value, Node *next);
Node *createNodeHeader (Node *next);
Queue *createQueue ();
void clear (Queue *queue);
void enqueue (Queue *queue, int value);
int dequeue (Queue *queue);
int front (Queue *queue);
int size (Queue *queue);

//Funções de manipulação de filas;

Node *createNode (int value, Node *next)
{
    Node *node = (Node *) malloc(sizeof(Node));
    node->value = value;
    node->next = next;
    return node;
}

Node *createNodeHeader (Node *next)
{
    Node *node = (Node *) malloc(sizeof(Node));
    node->next = next;
    return node;
}

Queue *createQueue ()
{
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->first = createNodeHeader(NULL);
    queue->last = queue->first;
    queue->size = 0;
    return queue;
}

void clear (Queue *queue)
{
    Node *node = queue->first->next;
    Node *aux = NULL;
    while (node != NULL)
    {
        aux = node->next;
        free(node);
        node = aux;
    }
    free(aux);
    queue->first->next = NULL;
    queue->last = queue->first;
    queue->size = 0;
}

void enqueue (Queue *queue, int value)
{
    queue->last->next = createNode(value, NULL);
    queue->last = queue->last->next;
    queue->size++;
}

int dequeue (Queue *queue)
{
    if (queue->first->next == NULL)
    {
        //Alguma mensagem de erro;
        return -1;
    }
    Node *node = queue->first->next;
    int value = node->value;
    queue->first->next = node->next;
    free(node);
    queue->size--;
    return value;
}

int front (Queue *queue)
{
    if (queue->first->next == NULL)
    {
        //Alguma mensagem de erro;
        return -1;
    }
    return queue->first->next->value;
}

int size (Queue *queue)
{
    return queue->size;
}