#include <stdio.h>
#include <stdlib.h>
//Componentes de uma árvore binária de busca;
//Essa árvore está organizada para implementação de um dicionário;
//O value e a key tipo int pode ser alterado para outro tipo;
//Nessa árvore, não haverá a implementação de folhas a parte dos nós;

typedef struct Node{
    int key;
    int value;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct BST{
    int cnt;
    Node *root;
} BST;

//Funções de manipulação da árvore;
//O value e a key tipo int pode ser alterado para outro tipo;

Node *createNode (int key, int value);              //cria uma folha;
BST *createBST ();                                  //cria uma árvore;
//
//Funções de percurso da árvore;
void preOrder (Node *n);                            //percurso pré-ordem;
void inOrder (Node *n);                             //percurso em-ordem;
void postOrder (Node *n);                           //percurso pós-ordem;
//
//
void clearBST (BST *t);                             //limpa a árvore da memória;
int find (BST *t, int key);                         //retorna o elemento da árvore a partir da raiz;
int findHelper (Node *n, int key);                  //retorna o elemento da árvore a partir de um nó;
void insert (BST *t, int key, int value);           //insere um elemento na árvore a partir da raiz;
Node *insertHelper (Node *n, int key, int value);   //insere um elemento na árvore a partir de um nó;
Node *getMin (Node *n);                             //retorna o menor elemento da subárvore a partir do nó;
Node *getMax (Node *n);                             //retorna o maior elemento da subárvore a partir do nó;
Node *deletemin (Node *n);                          //remove o menor elemento da subárvore a partir do nó;
Node *deletemax (Node *n);                          //remove o maior elemento da subárvore a partir do nó;
int remove (BST *t, int key);                       //remove um elemento da árvore a partir da raiz;
Node *removeHelper (Node *n, int key);              //remove um elemento da árvore a partir de um nó;
int max (int a, int b);                             //retorna o maior valor entre dois inteiros;
int height (BST *t);                                //retorna a altura da árvore;
int h (Node *n);                                    //retorna a altura da subárvore a partir do nó;
int size (BST *t);                                  //retorna o número de nós da árvore;

//Funções de manipulação da árvore;

Node *createNode (int key, int value)
{
    Node *n = (Node*)malloc(sizeof(Node));
    n->key = key;
    n->value = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

BST *createBST ()
{
    BST *t = (BST*)malloc(sizeof(BST));
    t->cnt = 0;
    t->root = NULL;
    return t;
}

//
void preOrder (Node *n)
{
    if (n != NULL)
    {
        //Alguma ação;
        preOrder(n->left);
        preOrder(n->right);    
    }
}

void inOrder (Node *n)
{
    if (n != NULL)
    {
        inOrder(n->left);
        //Alguma ação;
        inOrder(n->right);
    }
}

void postOrder (Node *n)
{
    if (n != NULL)
    {
        postOrder(n->left);
        postOrder(n->right);
        free(n);//Exemplo de ação;
    }
}
//

void clearBST (BST *t)
{
    if (t != NULL)
    {
        //A árvore será limpa da memória com um percurso pós-ordem;
        postOrder(t->root);
        free(t);
    }
}

int find (BST *t, int key)
{
    return findHelper(t->root, key);
}

int findHelper (Node *n, int key)
{
    if (n == NULL)
    {
        return /*Mensagem de valor não encontrado*/;
    }
    else if (n->key == key)
    {
        return n->value;
    }
    else if (n->key > key)
    {
        return findHelper(n->left, key);
    }
    else
    {
        return findHelper(n->right, key);
    }
}

void insert (BST *t, int key, int value)
{
    t->root = insertHelper(t->root, key, value);
    t->cnt++;
}

Node *insertHelper (Node *n, int key, int value)
{
    if (n == NULL)
    {
        return createNode(key, value);
    }
    else if (n->key > key)
    {
        n->left = insertHelper(n->left, key, value);
    }
    else
    {
        n->right = insertHelper(n->right, key, value);
    }
    return n;
}

Node *getMin (Node *n)
{
    Node *node = n;
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

Node *getMax (Node *n)
{
    Node *node = n;
    while (node->right != NULL)
    {
        node = node->right;
    }
    return node;
}

Node *deletemin (Node *n)
{
    Node *parent = NULL;
    Node *temp = n;
    while (temp->left != NULL)
    {
        parent = temp;
        temp = temp->left;
    }
    if (parent == NULL)
    {
        n = n->right;
    }
    else
    {
        parent->left = temp->right;
    }
    free(temp);
    return n;
}

Node *deletemax (Node *n)
{
    Node *parent = NULL;
    Node *temp = n;
    while (temp->right != NULL)
    {
        parent = temp;
        temp = temp->right;
    }
    if (parent == NULL)
    {
        n = n->left;
    }
    else
    {
        parent->right = temp->left;
    }
    free(temp);
    return n;
}

int remove (BST *t, int key)
{
    int temp = find(t, key);
    if (temp != NULL)
    {
        t->root = removeHelper(t->root, key);
        t->cnt--;
    }
    return temp;
}

Node *removeHelper (Node *n, int key)
{
    if (n->key > key)
    {
        n->left = removeHelper(n->left, key);
    }
    else if (n->key < key)
    {
        n->right = removeHelper(n->right, key);
    }
    else
    {
        if (n->left == NULL)
        {
            Node *temp = n->right;
            free(n);
            return temp;
        }
        else if (n->right == NULL)
        {
            Node *temp = n->left;
            free(n);
            return temp;
        }
        else
        {
            Node *temp = getMin(n->right);
            n->key = temp->key;
            n->value = temp->value;
            n->right = deletemin(n->right);
        }
    }
    return n;
}

int max (int a, int b)
{
    if (a < b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int height (BST *t)
{
    return h(t->root);
}

int h (Node *n)
{
    if (n == NULL)
    {
        return -1;
    }
    else
    {
        int hl = h(n->left);
        int hr = h(n->right);
        return (max(hl, hr) + 1);
    }
}

int size (BST *t)
{
    return t->cnt;
}