#include <iostream>
using namespace std;
int main()
{
    int a[10], n = 0, m;
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < 10; i++)
    {
        if (a[i] <= m + 30)
            n++;
    }
    cout << n;
    return 0;
}