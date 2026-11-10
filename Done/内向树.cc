#include <iostream>
#include <stack>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> cord;

const int dx[5] = {0, 0, 0, -1, 1};
const int dy[5] = {0, -1, 1, 0, 0};

short dir[2001][2001];
int in_degree[2001][2001];
bool processed[2001][2001];
int val[2001][2001];

queue<cord> starting_points;
stack<cord> unprocessed_orphans;

int m, n;

int main(void) {
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> dir[i][j];
            
            int nx = i + dx[dir[i][j]],
                ny = j + dy[dir[i][j]];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                ++in_degree[nx][ny];
        }
    }

    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (in_degree[i][j] == 0)
                starting_points.emplace(i, j);
        }
    }

    while (!starting_points.empty()) {
        cord next = starting_points.front();
        unprocessed_orphans.emplace(next);
        int x = next.first, y = next.second;
        processed[x][y] = true;
        int nx = x + dx[dir[x][y]], 
            ny = y + dy[dir[x][y]];
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if(--in_degree[nx][ny] == 0) 
                starting_points.emplace(nx, ny);
        }
        starting_points.pop();
    }

    int maximum = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (processed[i][j])
                continue;
            int x = i, y = j, nodes = 0;
            do {
                ++nodes;
                int nx = x + dx[dir[x][y]];
                y += dy[dir[x][y]];
                x = nx;
            }
            while(x != i || y != j);

            if (maximum < nodes)
                maximum = nodes;

            x = i; 
            y = j;
            do {
                val[x][y] = nodes;
                processed[x][y] = true;
                int nx = x + dx[dir[x][y]];
                y += dy[dir[x][y]];
                x = nx;
            }
            while(x != i || y != j);
        }
    }

    while (!unprocessed_orphans.empty()) {
        cord next = unprocessed_orphans.top();
        int x = next.first, y = next.second;
        int nx = x + dx[dir[x][y]], ny = y + dy[dir[x][y]];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
            val[x][y] = 1;
        }
        else {
            val[x][y] = val[nx][ny] + 1;
        }

        if (val[x][y] > maximum)
            maximum = val[x][y];

        unprocessed_orphans.pop();
    }

    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (maximum == val[i][j])
                cout << j << ' ' << i << '\n';
        }
    }
    return 0;
}