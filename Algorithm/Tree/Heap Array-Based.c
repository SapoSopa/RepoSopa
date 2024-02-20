#include <stdio.h>
//Componentes de uma Heap Array-Based;
//Essa árvore está implementada através de um vetor;
//O value será armazenado e a key será o índice do vetor;

//Funções de manipulação da heap;
//O value será do tipo int, mas pode ser alterado para outro tipo;
//Nessa implementação, já se é conhecido o tamanho máximo do vetor, portanto, não será necessário realocar memória ou realizar o processo de inserção de novos elementos;
//Para iniciar a Heap nessa implementação, é necessário apenas: int heap[size + 1];

//Size é o tamanho máximo real da Heap, mas por fins práticos, começaremos a preencher ela do índice 1;
//Funções de manipulação da heap array-based bottom-up;

void heapifyBU (int heap[], int size);                          //transforma um vetor em uma Heap;
void deleteHBU (int heap[], int *size);                         //remove o maior elemento, se for uma Max, ou o menor elemento, se for uma Min, da Heap;

//Funções de manipulação da heap;

void heapifyBU (int heap[], int size)                           //heap em Min;
{                                                               
    for (int i = size / 2; i > 0; i--)
    {
        int j;
        int k = i;
        int v = heap[k];
        int heapfy = 0;
        while (heapfy == 0 && 2 * k <= size)
        {
            j = 2 * k;
            if (j < size)
            {
                if (heap[j] > heap[j + 1])                      //heap em Max (heap[j] < heap[j + 1]);
                {
                    j++;
                }
            }
            if (v <= heap[j])                                   //heap em Max (v >= heap[j]);
            {
                heapfy = 1;
            } else {
                heap[k] = heap[j];
                k = j;
            }
        }
        heap[k] = v;
    }
}

void deleteHBU (int heap[], int *size)                          
{
    int v = heap[1];
    heap[1] = heap[*size];
    heap[*size] = v;
    (*size)--;
    heapify(heap, *size);
    //Fazer algo com o valor retirado;
    //"printf("%d\n", v);" por exemplo;
}

//Funções de manipulação da heap array-based top-down;

void heapifyTD (int heap[], int size);                          //transforma um vetor em uma Heap;
void insertHTD (int heap[], int *size, int value);              //insere um elemento na Heap;
void deleteHTD (int heap[], int *size);                         //remove o maior elemento, se for uma Max, ou o menor elemento, se for uma Min, da Heap;

//Funções de manipulação da heap;

void heapifyTD (int heap[], int size)                           //heap em Min;
{
    for (int i = 2; i <= size; i++)
    {
        int k = i;
        while (k > 1 && heap[k] > heap[k / 2])                  //heap em Max (heap[k] < heap[k / 2]);
        {
            int temp = heap[k];
            heap[k] = heap[k / 2];
            heap[k / 2] = temp;
            k = k / 2;
        }
    }
}

void insertHTD (int heap[], int *size, int value)               //como o valor de size é necessário, nesse método é mais comum uma struct heap para passar o array e o tamanho size;
{
    (*size)++;
    heap[*size] = value;                                        //assumimos que saibamos o total máximo de elementos da Heap;
    heapify(heap, *size);
}

void deleteHTD (int heap[], int *size)                          //como o valor de size é necessário, nesse método é mais comum uma struct heap para passar o array e o tamanho size;
{
    int v = heap[1];
    heap[1] = heap[*size];
    heap[*size] = v;
    (*size)--;
    heapify(heap, *size);
    //Fazer algo com o valor retirado;
    //"printf("%d\n", v);" por exemplo;
}