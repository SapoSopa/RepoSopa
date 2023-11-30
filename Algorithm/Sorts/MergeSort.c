#include <stdio.h>
//Funções para o merge sort;

void merge(long long int arr[], int l, int r);          //função que faz o merge
void mergesort(long long int arr[], int l, int r);      //função que divide o array em subarrays

//Funções;

void merge(long long int arr[], int l, int r)
{
    int m = (l + r) / 2;
    int i = l;
    int j = m + 1;
    long long int temp[r+1];
    for (int n = 0; n<=r; n++)
    {
        temp[n] = arr[n];
    }

    for (int k = l; k<=r; k++)
    {
        if (i > m)
        {
            arr[k] = temp[j];
            j++;
        }
        else if (j > r)
        {
            arr[k] = temp[i];
            i++;
        }
        else if (temp[i] <= temp[j]) //definir maior ou menor para crescente ou decrescente
        {
            arr[k] = temp[i];
            i++;
        }
        else
        {
            arr[k] = temp[j];
            j++;
        }
    }
}

void mergesort(long long int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;

        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);

        merge(arr, l, r);
    }
}
