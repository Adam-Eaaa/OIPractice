// P3371
#include <bits/stdc++.h>
using namespace std;
bool book[100001];
int dis[100001]; // Shortest length.
int route[100001][100001];
int n, m, s; // Sum: Number of dots, number of routes (input lines), beginning dot.
int a, b, l; // One: Begin, end, length of route.
const int INF = INT_MAX;
int main()
{
    memset(route, INF, sizeof(route)); // Set every dot to infinity (INF).
    memset(book, false, sizeof(book)); // Set every dot to unvisited (false).
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> l;
        route[a][b] = min(route[a][b], l);
    }
    while (!book[s])
    {
        book[s] = true;
        for (int i = 0; i < n; i++)
        {
            dis[i] = min(dis[i], dis[s] + route[s][i]);
        }
        int min_ = INF;
        for (int i = 0; i < n; i++)
        {
            if ((!book[i]) && dis[i] < min_)
            {
                min_ = dis[i];
                s = i;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", dis[i]);
    }
    return 0;
}