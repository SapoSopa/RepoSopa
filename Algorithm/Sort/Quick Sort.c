#include <stdio.h>
//Funções para o quick sort;

int HoarePartition (int arr[], int l, int r);  //função que faz a partição
void quicksort (int arr[], int l, int r);      //função que divide o array em subarrays

//Funções;

int HoarePartition (int arr[], int l, int r)
{
    int p = arr[l];
    int i = l;
    int j = r+1;
    do
    {
        do
        {
            i++;
        }while(!(arr[i] >= p || i >= r));
        do
        {
            j--;
        }while(!(arr[j] <= p));
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }while(!(i >= j));
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;
    return j;
}

void quicksort (int arr[], int l, int r)
{
    if (l < r)
    {
                                            //É possível usar outros tipos de partição
        int S = HoarePartition(arr, l, r);  //existem métodos de achar um pivô melhor,
                                            //mas vamos estabelecer o primeiro elemento como pivô
        quicksort(arr, l, S);
        quicksort(arr, S+1, r);
    }
}