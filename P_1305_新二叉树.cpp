#include <bits/stdc++.h>
using namespace std;
int n, t;
string tree = "", temp = "";

int main()
{
    cin >> n >> tree;
    for (int i = 1; i < n; i++)
    {
        cin >> temp;
        t = tree.find(temp[0]);
        tree.erase(t, 1);
        tree.insert(t, temp);
    }
    for (int i = 0; i < tree.length(); i++)
    {
        if (tree[i] && tree[i] != '*')
        {
            cout << tree[i];
        }
    }
    return 0;
}
