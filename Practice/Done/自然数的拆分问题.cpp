// P2404
#include <bits/stdc++.h>
using namespace std;

int n, a[9];

void print(int b)
{
    for (int i = 0; i < b; i++)
    {
        if (i == 0)
        {
            printf("%d", a[i]);
        }
        else
        {
            printf("+%d", a[i]);
        }
    }
    printf("\n");
    return;
}

void dfs(int x, int y, int z)
{ 
    if (x == n)
        return; 

    if (y == n)
    {
        print(z);
        return;
    }
    for (int i = x; i <= n - y; i++)
    {
        a[z] = i;             
        dfs(i, y + i, z + 1); 
    }
}

int main()
{
    while (~scanf("%d", &n))
    {
        dfs(1, 0, 0);
    }
    return 0;
}