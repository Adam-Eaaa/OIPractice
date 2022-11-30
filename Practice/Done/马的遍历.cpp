// P1443
#include <bits/stdc++.h>
using namespace std;

int board[500][500] = {};
bool vis[500][500] = {};
int start[2], border[2];
short dx[] = {2, 1, -2, -1, 2, 1, -2, -1};
short dy[] = {1, 2, -1, -2, -1, -2, 1, 2};
struct node
{
    int x, y;
};

node def;

void bfs();
bool verify(node);

int main()
{
    cin >> border[0] >> border[1];
    cin >> start[0] >> start[1];
    start[0]--;
    start[1]--;
    bfs();
    for (int i = 0; i < border[0]; i++)
    {
        for (int j = 0; j < border[1]; j++)
        {
            printf("%-5d", board[i][j]);
        }
        cout << endl;
    }
    return 0;
}

void bfs()
{
    def.x = -1;
    def.y = -1;
    memset(board, -1, sizeof(board));
    int s = 0;
    node curr, next;
    queue<node> q;
    curr.x = start[0];
    curr.y = start[1];
    q.push(curr);
    q.push(def);
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        if (curr.x == -1)
        {
            if (q.empty())
                return;
            q.push(def);
            s++;
            continue;
        }
        if (!verify(curr))
            continue;
        vis[curr.x][curr.y] = true;
        board[curr.x][curr.y] = s;
        for (int i = 0; i < 8; i++)
        {
            next.x = curr.x + dx[i];
            next.y = curr.y + dy[i];
            if (!verify(next))
            {
                continue;
            }
            q.push(next);
        }
    }
}

bool verify(node n)
{
    if (n.x < 0 || n.y < 0 || n.x >= border[0] || n.y >= border[1])
        return false;
    if (vis[n.x][n.y])
        return false;
    return true;
}