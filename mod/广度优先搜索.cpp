#include <bits/stdc++.h>
using namespace std;

bool vis[10][10] = {};
int Map[10][10] = {};
int dirx[] = {0, 1, 0, -1};
int diry[] = {1, 0, -1, 0};
int border[2], start[2], finish[2];

struct node
{
    int x, y, s;
};

node null;

bool reachable(int x, int y)
{
    if (x < 0 || y < 0 || x >= border[0] || y >= border[1])
        return false;
    if (vis[x][y])
        return false;
    if (Map[x][y] == 1)
        return false;
    return true;
}

node bfs()
{
    queue<node> q;
    node curr, next;
    curr.x = start[0];
    curr.y = start[1];
    curr.s = 0;
    vis[curr.x][curr.y] = true;
    q.push(curr);
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        if (curr.x == finish[0] && curr.y == finish[1])
            return curr;
        int nx, ny;
        for (int i = 0; i < 4; i++)
        {
            nx = curr.x + dirx[i];
            ny = curr.y + diry[i];
            if (!reachable(nx, ny))
                continue;
            vis[nx][ny] = true;
            next = curr;
            next.x = nx;
            next.y = ny;
            next.s = curr.s + 1;
            q.push(next);
        }
    }
    return null;
}

int main()
{
    null.x = -1;
    null.y = -1;
    scanf("%d %d", &border[0], &border[1]);
    for (int i = 0; i < border[0]; i++)
        for (int j = 0; j < border[1]; j++)
            scanf("%d", &Map[i][j]);
    scanf("%d %d %d %d", &start[0], &start[1], &finish[0], &finish[1]);
    node ans = bfs();
    int x = 0, y = 0;
    if (ans.x == null.x)
        printf("N\n");
    else
    {
        printf("%d\n", ans.s);
    }
    return 0;
}