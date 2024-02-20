#include <stdio.h>
#include <stdlib.h>
//Componentes de uma Heap Binary Tree;
//Essa árvore está implementada através de estruturas Node;
//O dado a ser armazenado será o value e ele também irá valor como a key;

//Funções de manipulação da heap;
//O value será do tipo int, mas pode ser alterado para outro tipo;
//Nessa implementação, não se é necessário saber o tamanho máximo da Heap, pois ela irá crescer dinamicamente;

//As estruturas são o padrão das funções de manipulação da Heap; 
typedef struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Heap
{
    Node *root;
    Node *lastP;                                    //Pai do último nó adicionado na Heap, para facilitar a inserção de novos elementos na Heap em top-down;
    int size;
} Heap;

//Funções de manipulação da heap binary tree bottom-up;

void heapifyBU(Node *node);                         //transforma uma árvore, já existente, em uma Heap a partir do nó;
void heapifyUser(Heap *heap);                       //transforma uma árvore, já existente, em uma Heap;
void deleteHBU(Heap *heap);                         //remove o maior elemento, se for uma Max, ou o menor elemento, se for uma Min, da Heap;

//Funções de manipulação da heap;

void heapifyBU(Node *node)                          //implementação de uma heap em Min;
{
    if (node->left->left != NULL || node->left->right != NULL)
    {
        heapifyBU(node->left);
    }
    if (node->right->left != NULL || node->right->right != NULL)
    {
        heapifyBU(node->right);
    }
    if (node->left != NULL)
    {
        if (node->left->value < node->value)       //heap em Max (node->left->value > node->value);
        {
            int aux = node->value;
            node->value = node->left->value;
            node->left->value = aux;
        }
    }
    if (node->right != NULL)
    {
        if (node->right->value < node->value)      //heap em Max (node->right->value > node->value);
        {
            int aux = node->value;
            node->value = node->right->value;
            node->right->value = aux;
        }
    }
}

void heapifyUser(Heap *heap)
{
    if (heap->root->left != NULL || heap->root->right != NULL)
    {
        heapifyBU(heap->root);
    }
}

void deleteHBU(Heap *heap)
{
    int v = heap->root->value;
    Node *aux = heap->root;
    while (aux->right != NULL || aux->left != NULL)
    {
        if (aux->right != NULL)
        {
            aux = aux->right;
        }
        if (aux->left != NULL)
        {
            aux = aux->left;
        }
    }
    heap->root->value = aux->value;
    aux = NULL;
    heap->size--;
    //Fazer algo com o valor retirado;
    //"printf("%d\n", v);" por exemplo;
}

//Funções de manipulação da heap binary tree top-down;

Node *createNode(int value);                        //cria um nó;
Heap *createHeap(int value);                        //cria uma Heap;
void heapifyTD(Node *node);                         //transforma uma árvore, já existente, em uma Heap a partir do nó;
void insertHTD(Heap *heap, int value);              //insere um elemento na Heap;
void deleteHTD(Heap *heap);                         //remove o maior elemento, se for uma Max, ou o menor elemento, se for uma Min, da Heap;

//Funções de manipulação da heap;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Heap *createHeap(int value)
{
    Heap *newHeap = (Heap *)malloc(sizeof(Heap));
    newHeap->root = createNode(value);
    newHeap->lastP = newHeap->root;
    newHeap->size = 0;
    return newHeap;
}

void heapifyTD(Node *node)                          //implementação de uma heap em Min;
{
    if (node->left != NULL)
    {
        if (node->left->value < node->value)        //heap em Max (node->left->value > node->value);
        {
            int aux = node->value;
            node->value = node->left->value;
            node->left->value = aux;
        }
    }
    if (node->right != NULL)
    {
        if (node->right->value < node->value)       //heap em Max (node->right->value > node->value);
        {
            int aux = node->value;
            node->value = node->right->value;
            node->right->value = aux;
        }
    }
}

void insertHTD(Heap *heap, int value)
{
    if (heap->lastP->left == NULL)
    {
        heap->lastP->left = createNode(value);
        heap->size++;
    }
    else if (heap->lastP->right == NULL)
    {
        heap->lastP->right = createNode(value);
        heap->size++;
    }
    else
    {
        Node *aux = heap->root;
        while (aux->left != heap->lastP )
    }
}