#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    int i = 0, j = 0;
    int x = 0;
    cin >> a >> b;
    while (j < b.length())
    {
        while (i < a.length())
        {
            if (a[i] == b[j])
            {
                x++;
                break;
            }
            i++;
        }
        j++;
    }
    cout << x;
    return 0;
}
