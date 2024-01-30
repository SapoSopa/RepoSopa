#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int height;
    int cntL;
    int cntR;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct AVL {
    int cntNode;
    Node *root;
} AVL;

Node *CreateNode(int key)
{
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->key = key;
    newNode->height = 0;
    newNode->cntL = 0;
    newNode->cntR = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

AVL *CreateAVL()
{
    AVL *newAVL = (AVL *)malloc(sizeof(AVL));
    newAVL->root = NULL;
    newAVL->cntNode = 0;
    return newAVL;
}

int Height(Node *node)
{
    if (node == NULL)
    {
        return -1;
    }
    return node->height;
}

int Max(int a, int b)
{
    return (a >= b) ? a : b;
}

int Balance(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return Height(node->left) - Height(node->right);
}

Node *RotateLeft(Node *node)
{
    Node *r = node->right;
    Node *rl = r->left;
    r->left = node;
    node->right = rl;
    
    if (rl != NULL)
    {
        node->cntR = rl->cntL + rl->cntR + 1;
    } else {
        node->cntR = 0;
    }

    if (node != NULL)
    {
        r->cntL = node->cntL + node->cntR + 1;
    } else {
        r->cntL = 0;
    }

    node->height = 1 + Max(Height(node->left), Height(node->right));
    r->height = 1 + Max(Height(r->left), Height(r->right));
    return r;
}

Node *RotateRight(Node *node)
{
    Node *l = node->left;
    Node *lr = l->right;
    l->right = node;
    node->left = lr;

    if (lr != NULL)
    {
        node->cntL = lr->cntL + lr->cntR + 1;
    } else {
        node->cntL = 0;
    }

    if (node != NULL)
    {
        l->cntR = node->cntL + node->cntR + 1;
    } else {
        l->cntR = 0;
    }

    node->height = 1 + Max(Height(node->left), Height(node->right));
    l->height = 1 + Max(Height(l->left), Height(l->right));
    return l;
}

Node *InsertNode(Node *node, int key)
{
    if (node == NULL)
    {
        return node = CreateNode(key);
    }

    if (key < node->key)
    {
        node->left = InsertNode(node->left, key);
        node->cntL++;
    } else {
        node->right = InsertNode(node->right, key);
        node->cntR++;
    }

    node->height = 1 + Max(Height(node->left), Height(node->right));
    int balance = Balance(node);

    if (balance > 1 && key < node->left->key)
    {
        return RotateRight(node);
    }
    else if (balance < -1 && key >= node->right->key)
    {
        return RotateLeft(node);
    }
    else if (balance > 1 && key >= node->left->key)
    {
        node->left = RotateLeft(node->left);
        return RotateRight(node);
    }
    else if (balance < -1 && key < node->right->key)
    {
        node->right = RotateRight(node->right);
        return RotateLeft(node);
    }
    return node;
}

void Insert(AVL *avl, int key)
{
    avl->root = InsertNode(avl->root, key);
    avl->cntNode++;
}

int FindNode(Node *node, int key, int i)
{
    if (node == NULL)
    {
        return -1;
    }

    if (key < node->key)
    {
        return FindNode(node->left, key, i);
    }
    else if (key > node->key)
    {
        if (node->left != NULL)
        {
            i += node->left->cntL + node->left->cntR + 2;
        } else {
            i++;
        }
        return FindNode(node->right, key, i);
    }
    else
    {
        return i + node->cntL + 1;
    }
}

int Find(AVL *avl, int key)
{
    return FindNode(avl->root, key, 0);
}

int main()
{
    AVL *avl = CreateAVL();
    int Q, x, key, i;

    scanf("%d", &Q);

    while (Q--)
    {
        scanf("%d %d", &x, &key);
        if (x == 1)
        {
            Insert(avl, key);
        } else {
            i = Find(avl, key);
            if (i == -1)
            {
                printf("Data tidak ada\n");
            } else {
                printf("%d\n", i);
            }
        }
    }    

    return 0;
}