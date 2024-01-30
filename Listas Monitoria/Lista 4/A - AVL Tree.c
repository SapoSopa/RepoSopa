#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int rank;
    int height;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct AVL {
    Node *root;
    int size;
} AVL;

Node *createNode(int key);
AVL *createAVL();
int max(int a, int b);
int height(Node *node);
int balance(Node *node);
Node *rightRotate(Node *n);
Node *leftRotate(Node *n);
Node *find(Node *node, int key);
Node *insertHelp(Node *node, int key);
void insert(AVL *avl, int key);
void attqueue(AVL *avl, int *queue, int *i);
int pos(int key, int *queue);

int main ()
{
    int Q, n, key;
    int added = 3;
    AVL *t = createAVL();
    scanf("%d", &Q);
    int queue[Q];
    while (Q--) 
    {
        scanf("%d", &n);
        if (n == 1) {
            scanf("%d", &key);
            insert(t, key);
            added = 1;
        } 
        else 
        {
            scanf("%d", &key);
            Node *f = find(t->root, key);
            if (f == NULL)
            {
                printf("Data tidak ada\n");
            }
            else
            {
                if (added == 1)
                {
                    int i = t->size;
                    attqueue(t, queue, &i);
                }
                int r = pos(key, queue);
                printf("%d\n", r);
                added = 2;
            }
        }
    }

    return 0;
}

Node *createNode(int key)
{
    Node *node = (Node *) malloc(sizeof(Node));
    node->key = key;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

AVL *createAVL()
{
    AVL *avl = (AVL *) malloc(sizeof(AVL));
    avl->root = NULL;
    avl->size = 0;
    return avl;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

int balance(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}

Node *rightRotate(Node *n)
{
    Node *l = n->left;
    Node *lr = l->right;
    
    l->right = n;
    n->left = lr;

    n->height = 1 + max(height(n->left), height(n->right));
    l->height = 1 + max(height(l->left), height(l->right));

    return l;
}

Node *leftRotate(Node *n)
{
    Node *r = n->right;
    Node *rl = r->left;

    r->left = n;
    n->right = rl;

    n->height = 1 + max(height(n->left), height(n->right));
    r->height = 1 + max(height(r->left), height(r->right));

    return r;
}

Node *find(Node *n, int key)
{
    if (n == NULL)
    {
        return NULL;
    }
    else if (key > n->key)
    {
        return find(n->right, key);
    }
    else if (key < n->key)
    {
        return find(n->left, key);
    }
    else
    {
        return n;
    }
}

Node *insertHelp(Node *node, int key)
{
    if (node == NULL)
    {
        return createNode(key);
    }
    if (key < node->key)
    {
        node->left = insertHelp(node->left, key);
    }
    else if (key >= node->key)
    {
        node->right = insertHelp(node->right, key);
    }

    node->height = 1 + max(height(node->left), height(node->right));
    int b = balance(node);
    
    if (b > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }
    if (b < -1 && key >= node->right->key)
    {
        return leftRotate(node);
    }
    if (b > 1 && key >= node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (b < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void insert(AVL *avl, int key)
{
    avl->root = insertHelp(avl->root, key);
    avl->size++;
}

void attqueue(AVL *avl, int *queue, int *i)
{
    if (avl->root == NULL)
    {
        return;
    }
    i--;
    attqueue(avl->root->left, queue, i);
    queue[*i] = avl->root->key;
    i++;
    attqueue(avl->root->right, queue, i);
}