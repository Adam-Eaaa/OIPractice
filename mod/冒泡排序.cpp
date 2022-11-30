#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a[100] = { };
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = n; i > 1; i--)
    {
        for (int j = 1; j < i - 1; j++)
        {
            if (a[j - 1] > a[j])
            {
                swap(a[j - 1], a[j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    cout << endl;
}