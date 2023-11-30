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

Node *createNode (int value, Node *next);
Stack *createStack ();
void clear (Stack *stack);
void push (Stack *stack, int value);
int pop (Stack *stack);
int top (Stack *stack);
int size (Stack *stack);

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