// P4715
// Be aware that the tree is stored with index counted from 1
// or it will be difficult to calculate the children's index
#include <bits/stdc++.h>
using namespace std;

struct team
{
    int ability;
    int number;
};

team getmax(team a, team b)
{
    return a.ability > b.ability ? a : b;
}

team getmin(team a, team b)
{
    return a.ability < b.ability ? a : b;
}

int main()
{
    int n;
    team tree[512];
    cin >> n;
    n = pow(2, n);
    for (int i = n; i < n * 2; i++)
    {
        cin >> tree[i].ability;
        tree[i].number = i - n + 1;
    }
    for (int i = n - 1; i > 0; i--)
    {
        tree[i] = getmax(tree[i * 2], tree[i * 2 + 1]);
    }
    printf("%d", getmin(tree[2], tree[3]).number);
    system("pause");
    return 0;
}