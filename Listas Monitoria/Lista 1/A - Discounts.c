#include <stdio.h>

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

int main()
{
    int n;
    scanf("%d", &n);
    long long int arr[n];
    long long int sum = 0;
    for (int i = 0; i<n; i++)
    {
        scanf("%lld", &arr[i]);
        sum += arr[i];
    }
    
    mergesort(arr, 0, n-1);
    
    int q;
    scanf("%d", &q);
    for (int i = 0; i<q; i++)
    {
        int x;
        scanf("%d", &x);
        printf("%lld\n", sum - arr[n-x]);
    }

    return 0;
}