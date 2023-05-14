#include <iostream>
using namespace std;

int main()
{
    int n, a[100010] = { };
    int m, s, e;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i-1];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> e;
        cout << a[e] - a[s - 1] << endl;
    }
    return 0;
}