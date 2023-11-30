#include <stdio.h>
#include <stdlib.h>
//Componentes de uma fila;
//O array tipo int pode ser alterado para qualquer outro tipo;

typedef struct Queue{
    int *array;
    int size;
    int capacity;
    int front;
    int rear;
} Queue;

//Funções de manipulação de filas;
//O value tipo int, que depende do array int, pode ser alterado para qualquer outro tipo, desde que juntos;
//Apesar de ser um array, ele simula uma fila circular;

Queue *createQueue (int capacity);                  //cria uma fila com capacidade inicial;
void clear (Queue *queue);                          //limpa a fila da memória;
void resize (Queue *queue, int newcapacity);        //redimensiona a fila para um novo valor;
void enqueue (Queue *queue, int value);             //adiciona um elemento ao final da fila e dobra o tamanho se necessário;
int dequeue (Queue *queue);                         //remove e retorna o elemento do início da fila e divide o tamanho se possível;
int front (Queue *queue);                           //retorna o elemento do início da fila;
int rear (Queue *queue);                            //retorna o elemento do final da fila;
int sizeQueue (Queue *queue);                       //retorna o tamanho da fila;

//Funções de manipulação de filas;

Queue *createQueue (int capacity)
{
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->array = (int*)malloc(sizeof(int)*capacity);
    queue->size = 0;
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

void clear (Queue *queue)
{
    free(queue->array);
    free(queue);
}

void resize (Queue *queue, int newcapacity)
{
    int *newArray = realloc(queue->array, sizeof(int)*newcapacity);
    if (newArray != NULL)
    {
        queue->array = newArray;
        queue->capacity = newcapacity;
        free(newArray);
    }
    else
    {
        //Alguma mensagem de erro;
    }    
}

void enqueue (Queue *queue, int value)
{
    if (queue->size == queue->capacity)
    {
        resize(queue, queue->capacity*2);
    }
    queue->array[queue->rear] = value;
    queue->rear = (queue->rear+1)%queue->capacity;
    queue->size++;
}

int dequeue (Queue *queue)
{
    if (queue->size == 0)
    {
        //Alguma mensagem de erro;
    }
    int value = queue->array[queue->front];
    queue->front = (queue->front+1)%queue->capacity;
    queue->size--;
    return value;
}

int front (Queue *queue)
{
    if (queue->size == 0)
    {
        //Alguma mensagem de erro;
    }
    return queue->array[queue->front];
}

int rear (Queue *queue)
{
    if (queue->size == 0)
    {
        //Alguma mensagem de erro;
    }
    return queue->array[queue->rear-1];
}

int sizeQueue (Queue *queue)
{
    return queue->size;
}