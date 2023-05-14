#include <iostream>
#include <queue>
using namespace std;

int n;
int level[220], cur, dest;
bool visited[220] = { };
int steps = 0;
bool able = true;
queue<int> q;

bool reachable(int l)
{
    if (l <= 0)
    {
        return false;
    }
    if (l > n)
    {
        return false;
    }
    if (visited[l])
    {
        return false;
    }
    return true;
}

void bfs()
{
    bool last = false;
    q.push(cur);
    q.push(-300);
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur == -300)
        {
            ++steps;
            q.push(-300);
            if (last)
            {
                return;
            }
            last = true;
            continue;
        }
        last = false;
        if (!reachable(cur))
        {
            continue;
        }
        if (cur == dest)
        {
            return;
        }
        visited[cur] = true;
        q.push(cur + level[cur]);
        q.push(cur - level[cur]);
    }
    able = false;
    return;
}

int main()
{
    int a, b;
    cin >> n >> a >> b;
    cur = a;
    dest = b;
    for (int i = 1; i <= n; i++)
    {
        cin >> level[i];
        visited[i] = false;
    }
    bfs();
    if (able)
    {
        printf("%d", steps);
    }
    else
    {
        printf("-1");
    }
    return 0;
}
