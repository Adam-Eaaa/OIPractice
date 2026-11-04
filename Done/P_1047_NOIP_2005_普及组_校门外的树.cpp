#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool trees[10050] = { };
    int l, m, a, b;
    int x = 0;
    cin >> l >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        for (int j = a; j <= b; j++)
        {
            trees[j] = true;
        }
    }
    for (int i = 0; i <= l; i++)
    {
        if (trees[i])
        {
            x += 1;
        }
    }
    printf("%d", l - x + 1);
    return 0;
}