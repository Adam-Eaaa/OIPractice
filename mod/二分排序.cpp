// P1177
#include <bits/stdc++.h>
using namespace std;

int n, a[1000001];

void qs(int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int rel = a[(s + e) / 2];
    int i = s, j = e;
    do
    {
        while(a[j] > rel)
            --j;
        while(a[i] < rel)
            ++i;
        if (i <= j)
        {
            swap(a[i], a[j]);
            ++i;--j;
        }
    } while(i <= j);
    qs(s, j);
    qs(i, e);
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
    cout << endl;
    return 0;
}