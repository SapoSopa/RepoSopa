#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
    Node *tail;
    Node *curr;
    int size;
} List;

Node *createNode (char data, Node *next);
Node *createNodeHeader (Node *next);
List *createList ();
void insert (List *list, char data);
void moveToStart (List *list);
void moveToEnd (List *list);

int main()
{
    List *Text = createList();
    char c;
    while (scanf("%c", &c) != EOF)
    {
        if (c == '[')
        {
            moveToStart(Text);
        }
        else if (c == ']')
        {
            moveToEnd(Text);
        }
        else
        {
            insert(Text, c);
        }
    }

    moveToStart(Text);
    for (int i = 0; i < Text->size; i++)
    {
        Text->curr = Text->curr->next;
        printf("%c", Text->curr->data);
    }

    return 0;
}

Node *createNode (char data, Node *next)
{
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->next = next;
    return node;
}

Node *createNodeHeader (Node *next)
{
    return createNode('#', next);
}

List *createList ()
{
    List *list = (List *) malloc(sizeof(List));
    list->head = createNodeHeader(NULL);
    list->tail = list->head;
    list->curr = list->head;
    list->size = 0;
    return list;
}

void insert (List *list, char data)
{
    Node *node = createNode(data, list->curr->next);
    list->curr->next = node;
    if (list->curr == list->tail)
    {
        list->tail = node;
    }
    list->curr = node;
    list->size++;
}

void moveToStart (List *list)
{
    list->curr = list->head;
}

void moveToEnd (List *list)
{
    list->curr = list->tail;
}