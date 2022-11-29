#include <bits/stdc++.h>
using namespace std;

int n, a[1000001];

void qs(int s, int e)
{
    if (s >= e)
    {
        return;
    }
    if (e - s == 1)
    {
        if (a[e] < a[s])
            swap(a[e], a[s]);
        return;
    }
    int rel = a[s];
    int i = s, j = e;
    while(i != j)
    {
        while(a[j] >= rel && i < j)
            --j;
        while(a[i] <= rel && i < j)
            ++i;
        if (i < j)
            swap(a[i], a[j]);
    }
    swap(a[i], a[s]);
    qs(s, i - 1);
    qs(i + 1, e);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    qs(0, n - 1);
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    return 0;
}