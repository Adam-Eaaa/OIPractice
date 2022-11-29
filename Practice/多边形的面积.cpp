// P1183
#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int n, border, dot[4], init[2], s = 0;
    cin >> n;
    cin >> dot[2] >> dot[3];
    init[0] = dot[2];
    init[1] = dot[3];
    for (int i = 1; i < n/2; i++)
    {
        cin >> dot[0] >> dot[1];
        border = abs(dot[0] - dot[2] + dot[1] - dot[3]);
        cin >> dot[2] >> dot[3];
        s += border * (dot[2] - dot[0] + dot[3] - dot[1]);
    }
    cin >> dot[0] >> dot[1];
    s += (dot[0] + dot[1] - dot[2] - dot[3]) *
        (init[0] + init[1] - dot[0] - dot[1]);
    cout << s;
    return 0;
}
