#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    int height;
    int order;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct AVL
{
    Node *root;
} AVL;

Node *createNode (int key);
AVL *createAVL ();
int findHelper (Node *n, int key);
int find (AVL *t, int key);
int max (int a, int b);
int h (Node *n);
int getBalance (Node *n);
Node *rightRotate (Node *y);
Node *leftRotate (Node *x);
Node *fixorder (Node *n);
Node *insertHelper (Node *n, int key);
void insert (AVL *t, int key);

int main ()
{
    int n, x, key;
    scanf("%d", &n);
    AVL *t = createAVL();
    while (n--)
    {
        scanf("%d", &x);
        if (x == 1)
        {
            scanf("%d", &key);
            insert(t, key);
        }
        else
        {
            scanf("%d", &key);
            find(t, key) ? printf("%d\n", find(t, key)) : printf("Data tidak ada\n");
        }
    }

    return 0;
}

Node *createNode (int key)
{
    Node *n = (Node *) malloc(sizeof(Node));
    n->key = key;
    n->height = -1;
    n->order = 1;
    n->left = NULL;
    n->right = NULL;
    return n;
}

AVL *createAVL ()
{
    AVL *t = (AVL *) malloc(sizeof(AVL));
    t->root = NULL;
    return t;
}

int findHelper (Node *n, int key)
{
    if (n == NULL)
    {
        return 0;
    }
    else if (n->key == key)
    {
        return n->order;
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

int find (AVL *t, int key)
{
    return findHelper(t->root, key);
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

Node *rightRotate (Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(h(y->left), h(y->right)) + 1;
    x->height = max(h(x->left), h(x->right)) + 1;

    return x;
}

Node *leftRotate (Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(h(x->left), h(x->right)) + 1;
    y->height = max(h(y->left), h(y->right)) + 1;

    return y;
}

Node *fixorder (Node *n)
{
    if (n == NULL)
    {
        return NULL;
    }
    else
    {
        n->order++;
        n->right = fixorder(n->right);
        n->left = fixorder(n->left);
        return n;
    }
}

Node *insertHelper (Node *n, int key)
{
    if (n == NULL)
    {
        return createNode(key);
    }
    else if (key < n->key)
    {
        n->order++;
        n->right = fixorder(n->right);
        n->left = insertHelper(n->left, key);
        if (n->left->left == NULL && n->left->right == NULL)
        {
            n->left->order = n->order - 1;
        }
    }
    else if (key > n->key)
    {
        n->right = insertHelper(n->right, key);
        if (n->right->right == NULL && n->right->left == NULL)
        {
            n->right->order = n->order + 1;
        }
    }

    n->height = 1 + max(h(n->left), h(n->right));

    int balance = getBalance(n);

    if (balance > 1 && key < n->left->key)
    {
        return rightRotate(n);
    }
    else if (balance < -1 && key > n->right->key)
    {
        return leftRotate(n);
    }
    else if (balance > 1 && key > n->left->key)
    {
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }
    else if (balance < -1 && key < n->right->key)
    {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }

    return n;
}

void insert (AVL *t, int key)
{
    if (find(t, key) == 0)
    {
        t->root = insertHelper(t->root, key);
    }
}