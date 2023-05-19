#include <bits/stdc++.h>
using namespace std;

const int route[][2] = {
    {0, 0},
    {1, 2},
    {2, 1},
    {1, -2},
    {2, -1},
    {-1, 2},
    {-2, 1},
    {-1, -2},
    {-2, -1}};

int n, m;               // Size of the map.
long long cnt[25][25] = {};   // Count the routes to idx.
bool wall[25][25] = {}; // Mark places that can be reached by horses as 'true'

int main()
{
    int hx, hy; // Coordinate of horse.
    cin >> n >> m;
    cin >> hx >> hy;
    ++n;
    ++m;
    ++hx;
    ++hy;
    for (int i = 0; i <= 8; i++)
    {
        wall[hx + route[i][0]][hy + route[i][1]] = true;
    }
    cnt[1][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (wall[i][j])
            {
                continue;
            }
            cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1];
        }
    }
    printf("%lld", cnt[n][m]);
    return 0;
}
