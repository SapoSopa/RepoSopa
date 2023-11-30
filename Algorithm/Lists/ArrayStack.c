#include <stdio.h>
#include <stdlib.h>
//Componentes de uma pilha;
//O array tipo int pode ser alterado para qualquer outro tipo;

typedef struct Stack{
    int *array;
    int size;
    int capacity;
    int top;
} Stack;

//Funções de manipulação de pilhas;
//O value tipo int, que depende do array int, pode ser alterado para qualquer outro tipo, desde que juntos;

Stack *createStack (int capacity);                  //cria uma pilha com capacidade inicial;
void clear (Stack *stack);                          //limpa a pilha da memória;
void resize (Stack *stack, int newcapacity);        //redimensiona a pilha para um novo valor;
void push (Stack *stack, int value);                //adiciona um elemento ao final da pilha e dobra o tamanho se necessário;
int pop (Stack *stack);                             //remove e retorna o elemento do final da pilha e divide o tamanho se possível;
int top (Stack *stack);                             //retorna o elemento do final da pilha;
int sizeStack (Stack *stack);                       //retorna o tamanho da pilha;

//Funções de manipulação de pilhas;

Stack *createStack (int capacity)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->array = (int*)malloc(sizeof(int)*capacity);
    stack->size = 0;
    stack->capacity = capacity;
    stack->top = -1;
    return stack;
}

void clear (Stack *stack)
{
    free(stack->array);
    free(stack);
}

void resize (Stack *stack, int newcapacity)
{
    int *newArray = realloc(stack->array, sizeof(int)*newcapacity);
    if (newArray != NULL)
    {
        stack->array = newArray;
        stack->capacity = newcapacity;
        free(newArray);
    }
    else
    {
        //Alguma mensagem de erro;
    }    
}

void push (Stack *stack, int value)
{
    if (stack->size == stack->capacity)
    {
        resize(stack, stack->capacity*2);
    }
    stack->top++;
    stack->array[stack->top] = value;
    stack->size++;
}

int pop (Stack *stack)
{
    if (stack->size == 0)
    {
        //Alguma mensagem de erro;
    }
    int value = stack->array[stack->top];
    stack->top--;
    stack->size--;
    if (stack->size <= stack->capacity/4)
    {
        resize(stack, stack->capacity/2);
    }
    return value;
}

int top (Stack *stack)
{
    if (stack->size == 0)
    {
        //Alguma mensagem de erro;
    }
    return stack->array[stack->top];
}

int sizeStack (Stack *stack)
{
    return stack->size;
}