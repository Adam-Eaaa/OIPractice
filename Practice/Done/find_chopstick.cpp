// P1469
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int res = 0, n, temp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        res ^= temp;
    }
    cout << res;
    system("pause");
    return 0;
}