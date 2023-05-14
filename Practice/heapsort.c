// Heap sort
#include <stdio.h>

#define swap(a,b) (a)=(a)+(b);(b)=(a)-(b);(a)=(a)-(b)

int heap[2001], data[1001], idx, idxData;

void heapify();

void heapSort();

int main()
{
    int i, s;
    scanf("%d", &s);
    idxData = s;
    idx = 0;
    for (i = 1; i <= s; i++)
    {
        scanf("%d", &data[i]);
    }
    heapify();
    heapSort();
    for (i = 1; i <= s; i++)
    {
        printf("%d ", heap[i]);
    }
    return 0;
}

void heapify()
{
    int cur;
    if (idxData == 0)
        return ;
    cur = ++idx;
    heap[cur] = data[idxData];
    --idxData;
    for ( ; cur > 1; cur /= 2)
    {
        if (heap[cur] > heap[cur / 2])
        {
            swap(heap[cur], heap[cur / 2]);
        }
    }
    heapify();
    return ;
}

void heapSort()
{
    int cur = 1;
    short swapped = 0;
    if (cur == idx)
        return ;
    swap(heap[cur], heap[idx]);
    --idx;
    while (cur * 2 <= idx)
    {
        swapped = 0;
        if (cur * 2 + 1 > idx)
        {
            if (heap[cur] < heap[cur * 2])
            {
                swap(heap[cur], heap[cur * 2]);
                cur = cur * 2;
            }
            break ;
        }
        if (heap[cur * 2] > heap[cur * 2 + 1])
        {
            if (heap[cur] < heap[cur * 2])
            {
                swap(heap[cur], heap[cur * 2]);
                cur = cur * 2;
                swapped = 1;
            }
        }
        else
        {
            if (heap[cur] < heap[cur * 2 + 1])
            {
                swap(heap[cur], heap[cur * 2 + 1]);
                cur = cur * 2 + 1;
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }
    heapSort();
    return ;
}