#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
} Node;

typedef struct tree
{
    Node *root;
} Tree;

Node *createnode (int value);
Tree *createtree ();
void insert (Tree *t, int value);
Node *insertHelper (Node *n, int value);
void preOrderPrint (Node *n);
void inOrderPrint (Node *n);
void postOrderPrint (Node *n);

int main()
{
    int n, p;
    Tree *t = createtree();
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p);
        insert(t, p);
    }
    printf ("Pre order :");
    preOrderPrint(t->root);
    printf("\n");
    printf ("In order  :");
    inOrderPrint(t->root);
    printf("\n");
    printf ("Post order:");
    postOrderPrint(t->root);
    
    return 0;
}

Node *createnode (int value)
{
    Node *n = malloc(sizeof(Node));
    n->value = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Tree *createtree ()
{
    Tree *t = malloc(sizeof(Tree));
    t->root = NULL;
    return t;
}

void insert (Tree *t, int value)
{
    t->root = insertHelper(t->root, value);
}

Node *insertHelper (Node *n, int value)
{
    if (n == NULL)
    {
        return createnode(value);
    }
    else if (n->value > value)
    {
        n->left = insertHelper(n->left, value);
    }
    else
    {
        n->right = insertHelper(n->right, value);
    }
    return n;
}

void preOrderPrint (Node *n)
{
    if (n != NULL)
    {
        printf(" %d", n->value);
        preOrderPrint(n->left);
        preOrderPrint(n->right);
    }
}

void inOrderPrint (Node *n)
{
    if (n != NULL)
    {
        inOrderPrint(n->left);
        printf(" %d", n->value);
        inOrderPrint(n->right);
    }
}

void postOrderPrint (Node *n)
{
    if (n != NULL)
    {
        postOrderPrint(n->left);
        postOrderPrint(n->right);
        printf(" %d", n->value);
    }
}