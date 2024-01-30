#include <stdio.h>
#include <stdlib.h>
//Componentes de uma árvore AVL;
//Essa árvore está organizada para implementação de um dicionário;
//O value e a key tipo int pode ser alterado para outro tipo;
//Nessa árvore, não haverá a implementação de folhas a parte dos nós;
//A árvore AVL é uma árvore binária de busca balanceada;

typedef struct Node{
    int key;
    int value;
    int height;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct AVL{
    int cnt;
    Node *root;
} AVL;

//Funções de manipulação da árvore;
//O value e a key tipo int pode ser alterado para outro tipo;

Node *createNode (int key, int value);              //cria uma folha;
AVL *createAVL ();                                  //cria uma árvore;
//
//Funções de percurso da árvore;
void preOrder (Node *n);                            //percurso pré-ordem;
void inOrder (Node *n);                             //percurso em-ordem;
void postOrder (Node *n);                           //percurso pós-ordem;
//
//
void clearAVL (AVL *t);                             //limpa a árvore da memória;
int find (AVL *t, int key);                         //retorna o elemento da árvore a partir da raiz;
int findHelper (Node *n, int key);                  //retorna o elemento da árvore a partir de um nó;
int max (int a, int b);                             //retorna o maior valor entre dois inteiros;
int height (Node *n);                               //retorna a altura da subárvore a partir do nó;
int h (Node *n);                                    //calcula a altura da subárvore a partir do nó;
int getBalance (Node *n);                           //retorna o fator de balanceamento do nó;
Node *rightRotate (Node *n);                        //rotaciona a subárvore a partir do nó para a direita;
Node *leftRotate (Node *n);                         //rotaciona a subárvore a partir do nó para a esquerda;
void insert (AVL *t, int key, int value);           //insere um elemento na árvore a partir da raiz;
Node *insertHelper (Node *n, int key, int value);   //insere um elemento na árvore a partir de um nó;
Node *getMin (Node *n);                             //retorna o menor elemento da subárvore a partir do nó;
Node *getMax (Node *n);                             //retorna o maior elemento da subárvore a partir do nó;
Node *deletemin (Node *n);                          //remove o menor elemento da subárvore a partir do nó;
Node *deletemax (Node *n);                          //remove o maior elemento da subárvore a partir do nó;
int remove (AVL *t, int key);                       //remove um elemento da árvore a partir da raiz;
Node *removeHelper (Node *n, int key);              //remove um elemento da árvore a partir de um nó;
int size (AVL *t);                                  //retorna o número de nós da árvore;

//Funções de manipulação da árvore;

Node *createNode (int key, int value)
{
    Node *n = (Node*)malloc(sizeof(Node));
    n->key = key;
    n->value = value;
    n->height = 1;
    n->left = NULL;
    n->right = NULL;
    return n;
}

AVL *createAVL ()
{
    AVL *t = (AVL*)malloc(sizeof(AVL));
    t->cnt = 0;
    t->root = NULL;
    return t;
}

//
void preOrder (Node *n)
{
    if (n != NULL)
    {
        printf("%d ", n->key);//Exemplo de alguma ação;
        preOrder(n->left);
        preOrder(n->right);
    }
}

void inOrder (Node *n)
{
    if (n != NULL)
    {
        inOrder(n->left);
        printf("%d ", n->key);//Exemplo de alguma ação;
        inOrder(n->right);
    }
}

void postOrder (Node *n)
{
    if (n != NULL)
    {
        postOrder(n->left);
        postOrder(n->right);
        free(n);//Exemplo de alguma ação;
    }
}
//

void clearAVL (AVL *t)
{
    if (t != NULL)
    {
        //A árvore será limpa da memória com um percurso pós-ordem;
        postOrder(t->root);
        free(t);
    }
}

int find (AVL *t, int key)
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

int height (Node *n)
{
    return n->height;
}

int h (Node *n)
{
    if (n == NULL)
    {
        return -1;
    }
    else
    {
        return n->height;
    }
}

int getBalance (Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    else
    {
        return h(n->left) - h(n->right);
    }
}

Node *rightRotate (Node *n)
{
    Node *l = n->left;
    Node *lr = l->right;

    l->right = n;
    n->left = lr;

    n->height = max(h(n->left), h(n->right)) + 1;
    l->height = max(h(l->left), h(l->right)) + 1;

    return l;
}

Node *leftRotate (Node *n)
{
    Node *r = n->right;
    Node *rl = r->left;

    r->left = n;
    n->right = rl;

    n->height = max(h(n->left), h(n->right)) + 1;
    r->height = max(h(r->left), h(r->right)) + 1;

    return r;
}

void insert (AVL *t, int key, int value)
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

    n->height = max(h(n->left), h(n->right)) + 1;
    int balance = getBalance(n);

    if (balance < -1 && key >= n->right->key)
    {
        return leftRotate(n);
    }
    else if (balance < -1 && key < n->right->key)
    {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }
    else if (balance > 1 && key < n->left->key)
    {
        return rightRotate(n);
    }
    else if (balance > 1 && key >= n->left->key)
    {
        n->left = leftRotate(n->left);
        return rightRotate(n);
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
    if (n == NULL)
    {
        return n;
    }
    else if (n->left != NULL)
    {
        n->left = deletemin(n->left);
    }
    else
    {
        Node *temp = n->right;
        free(n);
        n = temp;
    }
    n->height = max(h(n->left), h(n->right)) + 1;
    int balance = getBalance(n);
    if (balance < -1 && n->key >= n->right->key)
    {
        return leftRotate(n);
    }
    else if (balance < -1 && n->key < n->right->key)
    {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }
    else if (balance > 1 && n->key < n->left->key)
    {
        return rightRotate(n);
    }
    else if (balance > 1 && n->key >= n->left->key)
    {
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }
    return n;
}

Node *deletemax (Node *n)
{
    if (n == NULL)
    {
        return n;
    }
    else if (n->right != NULL)
    {
        n->right = deletemax(n->right);
    }
    else
    {
        Node *temp = n->left;
        free(n);
        n = temp;
    }
    n->height = max(h(n->left), h(n->right)) + 1;
    int balance = getBalance(n);
    if (balance < -1 && n->key >= n->right->key)
    {
        return leftRotate(n);
    }
    else if (balance < -1 && n->key < n->right->key)
    {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }
    else if (balance > 1 && n->key < n->left->key)
    {
        return rightRotate(n);
    }
    else if (balance > 1 && n->key >= n->left->key)
    {
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }
    return n;
}

int remove (AVL *t, int key)
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
        if (n->left == NULL && n->right == NULL)
        {
            free(n);
        }
        else if (n->left == NULL)
        {
            Node *temp = n->right;
            free(n);
            n = temp;
        }
        else if (n->right == NULL)
        {
            Node *temp = n->left;
            free(n);
            n = temp;
        }
        else
        {
            Node *temp = getMin(n->right);
            n->key = temp->key;
            n->value = temp->value;
            n->right = deletemin(n->right);
        }
    }
    n->height = max(h(n->left), h(n->right)) + 1;
    int balance = getBalance(n);
    if (balance < -1 && n->key >= n->right->key)
    {
        return leftRotate(n);
    }
    else if (balance < -1 && n->key < n->right->key)
    {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }
    else if (balance > 1 && n->key < n->left->key)
    {
        return rightRotate(n);
    }
    else if (balance > 1 && n->key >= n->left->key)
    {
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }
    return n;
}

int size (AVL *t)
{
    return t->cnt;
}