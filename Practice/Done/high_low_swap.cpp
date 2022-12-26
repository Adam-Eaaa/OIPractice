// P1100
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll i;
    cin >> i;
    cout << ((i & 0x0000ffff) << 16 | (i & 0xffff0000) >> 16) << endl;
    getchar();
    getchar();
    return 0;
}