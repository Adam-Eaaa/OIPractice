// P4913
// Be especially awared that the root of a tree should be stored
// with index `1`
#include <bits/stdc++.h>
using namespace std;
#define LIMIT 1000010

struct node
{
    int left;
    int right;
};
node tree[LIMIT];
int n;

int dfs(int cur, int depth)
{
    if (cur == 0)
    {
        return depth;
    }
    int l, r;
    l = dfs(tree[cur].left, depth + 1);
    r = dfs(tree[cur].right, depth + 1);
    return max(l, r);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> tree[i].left >> tree[i].right;
    }
    printf("%d", dfs(1, 0));
    return 0;
}
