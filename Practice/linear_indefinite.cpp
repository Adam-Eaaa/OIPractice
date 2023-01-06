// 5656
#include <bits/stdc++.h>
using namespace std;

// Basic functions
bool mod(int a, int b)
{
    return a % b ? false: true;
}
int gcd(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }
    return gcd(b, a % b);
}

int main()
{
    unsigned int T, a, b, c;
    unsigned int x_max_x, x_max_y, x_min_x, x_min_y;
    unsigned int xr, yr, sr;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> a >> b >> c;
        if (!mod(c, gcd(a, b)))
        {
            printf("-1");
            continue;
        }
    }
    system("pause");
    return 0;
}