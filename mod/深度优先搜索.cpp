#include <bits/stdc++.h>
using namespace std;

int Map[10][10] = {};
bool vis[10][10] = {};
int least = INT_MAX;
int start[2], finish[2], border[2];
int dirx[] = {0, 1, 0, -1};
int diry[] = {1, 0, -1, 0};

bool verify(int x, int y)
{
    if (x < 0 || x >= border[0] || y < 0 || y >= border[1])
        return false;
    if (Map[x][y] == 1)
        return false;
    if (vis[x][y])
        return false;
    return true;
}

bool dfs(int x, int y, int s)
{
    bool res = false;
    if (x == finish[0] && y == finish[1])
    {
        if (least > s)
            least = s;
        return true;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!verify(x + dirx[i], y + diry[i]))
            continue;
        res = res || dfs(x + dirx[i], y + diry[i], s + 1);
    }
    return res;
}

int main()
{
    scanf("%d %d", &border[0], &border[1]);
    for (int i = 0; i < border[0]; i++)
        for (int j = 0; j < border[1]; j++)
            scanf("%d", &Map[i][j]);
    scanf("%d %d %d %d", &start[0], &start[1], &finish[0], &finish[1]);
    if (dfs(start[0], start[1], 0))
    {
        printf("%d\n", least);
    }
    else
    {
        printf("-1\n");
    }
    return 0;
}
