#include <iostream>
#include <vector>
#include <set>
using namespace std;

constexpr int LIM = static_cast<int>(2e5 + 10), MDEP = 19;

vector<int> graph[LIM];
int up[LIM][MDEP];
set<int> tp;
int n, k, q;

int main() {
    cin >> n >> k >> q;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    return 0;
}