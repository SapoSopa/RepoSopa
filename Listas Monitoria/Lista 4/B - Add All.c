#include <stdio.h>

void heapify (int heap[], int size);
void AddAll (int heap[], int *size);

int main ()
{
    int N, x;
    while (scanf("%d", &N) && N)
    {
        int heap[N + 1];
        int size = N;
        int cost = 0;
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &x);
            heap[i] = x;
        }
        heapify(heap, size);
        while (size > 1)
        {
            AddAll(heap, &size);
            cost += heap[1];
            heapify(heap, size);
        }
        printf("%d\n", cost);
    }

    return 0;
}

void heapify (int heap[], int size)
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
                if (heap[j] > heap[j + 1])
                {
                    j++;
                }
            }
            if (v <= heap[j])
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

void AddAll (int heap[], int *size)
{
    int v = heap[1];
    heap[1] = heap[*size];
    heap[*size] = v;
    (*size)--;
    heapify(heap, *size);
    heap[1] += v;
}