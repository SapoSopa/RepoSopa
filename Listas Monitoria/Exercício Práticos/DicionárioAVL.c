#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

Node *createNode (int key);
int h (Node *n);
int max (int a, int b);
int getBalance (Node *n);
Node *rightRotate (Node *n);
Node *leftRotate (Node *n);
Node *insert (Node *n, int key);
void preOrder (Node *n);
void clear (Node *n);

int main()
{
    int c, n, key;
    Node *root = NULL;
    scanf("%d", &c);
    while (c--)
    {
        scanf("%d", &n);
        while (n--)
        {
            scanf("%d", &key);
            root = insert(root, key);
        }
        preOrder(root);
        printf("END\n");
        clear(root);
        root = NULL;
    }

    return 0;
}

Node *createNode (int key)
{
    Node *n = (Node *) malloc(sizeof(Node));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}

int h (Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    else
    {
        return n->height;
    }
}

int max (int a, int b)
{
    return (a > b) ? a : b;
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

Node *insert (Node *n, int key)
{
    if (n == NULL)
    {
        return createNode(key);
    }
    if (key < n->key)
    {
        n->left = insert(n->left, key);
    }
    else if (key > n->key)
    {
        n->right = insert(n->right, key);
    }
    else
    {
        return n;
    }
    
    n->height = 1 + max(h(n->left), h(n->right));
    
    int balance = getBalance(n);
    
    if (balance > 1 && key < n->left->key)
    {
        return rightRotate(n);
    }
    if (balance < -1 && key > n->right->key)
    {
        return leftRotate(n);
    }
    if (balance > 1 && key > n->left->key)
    {
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }
    if (balance < -1 && key < n->right->key)
    {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }
    
    return n;
}

void preOrder (Node *n)
{
    if (n != NULL)
    {
        printf("%d\n", n->key);
        preOrder(n->left);
        preOrder(n->right);
    }
}

void clear (Node *n)
{
    if (n != NULL)
    {
        clear(n->left);
        clear(n->right);
        free(n);
    }
}