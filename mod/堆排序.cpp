#include <bits/stdc++.h>
using namespace std;
int heap[1000], idx;

void push(int val)
{
    int curr, father;
    heap[++idx] = val;
    curr = idx;
    
    while (curr / 2 > 0)
    {
        father = curr / 2;
        if (heap[father] >= heap[curr])
            break;
        swap(heap[father], heap[curr]);
        curr = father;
    }
    
}

void del()
{
    int curr, child;
    swap(heap[idx--], heap[1]);
    curr = 1;

    while (curr * 2 <= idx)
    {
        child = curr * 2;
        if (child + 1 <= idx && heap[child] < heap[child + 1])
            child++;
        if (heap[child] > heap[curr])
            swap(heap[child], heap[curr]);
        else
            break;
        curr = child;
    }
}

int main(){
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        push(a);
    }
    for (int i = 0; i < n; i++)
    {
        del();
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", heap[i]);
    }
    cout << endl;
    return 0;
}