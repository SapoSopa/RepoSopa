#include <stdio.h>
//Funções para a busca binária;
//O array int pode ser modificado para qualquer tipo de array, desde que a comparação seja feita corretamente

int binarySearch(int arr[], int l, int r, int x);       //função que faz a busca binária em um array ordenado

//Funções;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int m = (l + r) / 2;

        if (arr[m] == x)
        {
            return m;
        }
        else if (arr[m] > x)
        {
            return binarySearch(arr, l, m - 1, x);
        }
        else
        {
            return binarySearch(arr, m + 1, r, x);
        }
    }
    return -1;
}