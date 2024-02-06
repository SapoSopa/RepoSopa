#include <stdio.h>
#include <stdlib.h>
//Componentes de uma Pilha (Stack);
//O value tipo int pode ser alterado para qualquer outro tipo;

typedef struct Node{
    int value;
    struct Node *next;
} Node;

typedef struct Stack{
    Node *top;
    int size;
} Stack;

//Funções de manipulação de pilhas;
//O value tipo int pode ser alterado para qualquer outro tipo;

Node *createNode (int value, Node *next);           //Cria um nó com um valor e um ponteiro para o próximo nó;
Stack *createStack ();                              //Cria uma pilha;
void clear (Stack *stack);                          //Limpa a pilha da memória;
void push (Stack *stack, int value);                //Insere um elemento no topo da pilha;
int pop (Stack *stack);                             //Remove e retorna o elemento do topo da pilha;
int top (Stack *stack);                             //Retorna o elemento do topo da pilha;
int size (Stack *stack);                            //Retorna o tamanho da pilha;

//Funções de manipulação de pilhas;

Node *createNode (int value, Node *next)
{
    Node *node = (Node *) malloc(sizeof(Node));
    node->value = value;
    node->next = next;
    return node;
}

Stack *createStack ()
{
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void clear (Stack *stack)
{
    Node *node = NULL;
    while (stack->top != NULL)
    {
        node = stack->top;
        stack->top = stack->top->next;
        free(node);
    }
    stack->size = 0;
}

void push (Stack *stack, int value)
{
    stack->top = createNode(value, stack->top);
    stack->size++;
}

int pop (Stack *stack)
{
    if (stack->top == NULL)
    {
        //Algum comentário indicando erro;
        return -1;
    }
    Node *node = stack->top;
    int value = node->value;
    stack->top = stack->top->next;
    free(node);
    stack->size--;
    return value;
}

int top (Stack *stack)
{
    if (stack->top == NULL)
    {
        //Algum comentário indicando erro;
        return -1;
    }
    return stack->top->value;
}

int size (Stack *stack)
{
    return stack->size;
}