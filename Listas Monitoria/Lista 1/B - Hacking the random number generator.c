#include <stdio.h>

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
        int S = HoarePartition(arr, l, r);
        quicksort(arr, l, S);
        quicksort(arr, S+1, r);
    }
}

int main()
{
    int n, k, count = 0;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, n-1);

    for (int i = 0; i<n-1; i++)
    {
        int j = i;
        do
        {
            j++;
            if (arr[i]+k == arr[j])
            {
                count++;
            }
        } while (arr[i]+k > arr[j] && j < n);
    }
    printf("%d", count);

    return 0;
}