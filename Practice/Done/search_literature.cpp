// P5318
#include <bits/stdc++.h>
using namespace std;

// Data storage and initialize
int n, m;
vector<int> map_[100001];
bool book[100001];
struct edge
{
    int u, v;
};
vector<edge> s;
bool cmp(edge x, edge y)
{
    if (x.v == y.v)
        return x.u < y.u;
    else
        return x.v < y.v;
}
void init()
{
    memset(book, false, sizeof(book));
}

// Data fetch
void input()
{
    int t1, t2;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> t1 >> t2;
        s.push_back((edge){t1, t2});
    }
    sort(s.begin(), s.end(), cmp);
    for (int i = 0; i < m; i++)
        map_[s[i].u].push_back(i);
}

// Depth first search
void dfs(int x)
{
    if (book[x])
        return;
    int point;
    book[x] = true;
    printf("%d ", x);
    for (int i = 0; i < map_[x].size(); i++)
    {
        point = s[map_[x][i]].v;
        dfs(point);
    }
}

// Breadth first search
void bfs(int x)
{
    queue<int> waiting;
    int cur, next;
    waiting.push(x);
    printf("%d ", x);
    book[x] = true;
    while (!waiting.empty())
    {
        cur = waiting.front();
        for (int i = 0; i < map_[cur].size(); i++)
        {
            next = s[map_[cur][i]].v;
            if (!book[next])
            {
                waiting.push(next);
                printf("%d ", next);
                book[next] = true;
            }
        }
        waiting.pop();
    }
}

// Main function
int main()
{
    input();
    init();
    dfs(1);
    cout << endl;
    init();
    bfs(1);
    system("pause");
    return 0;
}
