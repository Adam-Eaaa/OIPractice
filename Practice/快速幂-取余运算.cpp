// P1226
#include <bits/stdc++.h>
using namespace std;
long long a, b, p, r = 1;
long long tmp;

void pwr()
{
    
}

int main()
{
    cin >> a >> b >> p;
    tmp = b;
    pwr();
    b = tmp;
    printf("%lld^%lld mod %lld=%lld\n", a, b, p, r%p);
    return 0;
}