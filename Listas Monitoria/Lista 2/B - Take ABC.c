#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *prev;    
    char value;
    struct node *next;
} Node;

typedef struct list {
    Node *head;
    Node *tail;
    Node *curr;
    int size;
} List;

Node *createNode (char value, Node *next, Node *prev);
List *createList ();
void append (List *list, char value);
void removeIt (List *list);
void printList (List *list);

int main () {
    char c;
    List *list = createList();
    while (scanf("%c", &c) != EOF)
    {
        if (c == 'C')
        {
            if (list->curr->value == 'B' && list->curr->prev->value == 'A')
            {
                removeIt(list);
                removeIt(list);
            }
            else
            {
                append(list, c);
            }
        }
        else
        {
            append(list, c);
        }
    }
    printList(list);

    return 0;
}


Node *createNode (char value, Node *next, Node *prev)
{
    Node *node = (Node *) malloc(sizeof(Node));
    node->value = value;
    node->next = next;
    node->prev = prev;
    return node;
}

List *createList ()
{
    List *list = (List *) malloc(sizeof(List));
    list->head = createNode(' ', NULL, NULL);
    list->tail = list->head;
    list->curr = list->head;
    list->size = 0;
    return list;
}

void append (List *list, char value)
{
    list->tail->next = createNode(value, NULL, list->tail);
    list->tail = list->tail->next;
    list->curr = list->tail;
    list->size++;
}

void removeIt (List *list)
{
    if (list->curr->prev == NULL)
    {
        //Algum comentário indicando erro;
        return -1;
    }
    Node *temp = list->tail;
    list->tail = temp->prev;
    list->tail->next = temp->next;
    list->curr = list->tail;
    free(temp);
    list->size--;
}

void printList (List *list)
{
    list->curr = list->head->next;
    while (list->curr != NULL)
    {
        printf("%c", list->curr->value);
        list->curr = list->curr->next;
    }
}