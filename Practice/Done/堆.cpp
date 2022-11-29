// P3378
#include <bits/stdc++.h>
using namespace std;
long long heap[1100000], size;

void in(int val)
{
    long long curr, father;
    heap[++size] = val;
    curr = size;
    while (curr)
    {
        father = curr >> 1;
        if (heap[curr] < heap[father])
            swap(heap[curr], heap[father]);
        else
            break;
        curr = father;
    }
    return;
}

void del()
{
    long long curr, child;
    curr = 1;
    swap(heap[size], heap[1]);
    size--;
    while (curr * 2 <= size)
    {
        child = curr << 1;
        if (child + 1 <= size && heap[child + 1] < heap[child])
            child++;
        if (heap[child] < heap[curr])
            swap(heap[curr], heap[child]);
        else
            break;
        curr = child;
    }
    return;
}

int get()
{
    return heap[1];
}

int main()
{
    long long n, op, val;
    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> val;
            in(val);
        }
        else if (op == 2)
        {
            cout << get() << endl;
        }
        else if (op == 3)
        {
            del();
        }
    }
    return 0;
}