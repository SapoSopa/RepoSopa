#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int valor;
    struct node *prox;
}Node;
typedef struct pilha{
    Node *topo;
    int tamanho;
}Pilha;

Node *criarNode(int valor);
Pilha *criarPilha();
void push(Pilha *p, int valor);
int pop(Pilha *p);

int main ()
{
    int v1, v2, l;
    char L[100];
    Pilha *p = criarPilha();
    scanf("%s", L);
    while(strcmp(L, "EOF"))
    {
        if (!(strcmp(L, "+")))
        {
            v2 = pop(&p);
            v1 = pop(&p);
            push(&p, v1 + v2);
        }
        else if (!(strcmp(L, "-")))
        {
            v2 = pop(&p);
            v1 = pop(&p);
            push(&p, v1 - v2);
        }
        else if (!(strcmp(L, "*")))
        {
            v2 = pop(&p);
            v1 = pop(&p);
            push(&p, v1 * v2);
        }
        else if (!(strcmp(L, "END")))
        {
            printf("%d\n", pop(&p));
        }
        else
        {
            l = atoi(L);
            push(&p, l);
        }
        scanf("%s", L);
    }

    return 0;
}

Node *criarNode(int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}
Pilha *criarPilha(){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    p->tamanho = 0;
    return p;
}
void push(Pilha *p, int valor){
    Node *novo = criarNode(valor);
    novo->prox = p->topo;
    p->topo = novo;
    p->tamanho++;
}
int pop(Pilha *p){
    if(p->topo == NULL){
        return -1;
    }
    Node *aux = p->topo;
    int valor = aux->valor;
    p->topo = aux->prox;
    free(aux);
    p->tamanho--;
    return valor;
}