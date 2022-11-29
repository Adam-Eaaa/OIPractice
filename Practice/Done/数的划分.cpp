// P1025
#include <bits/stdc++.h>
using namespace std;

int n, k;
int cnt = 0;

void dfs(int curr, int sum, int last) {
    if (n - sum < last) {
        return ;
    }
    if (curr == k - 1) {
        if (n - sum >= last) {
            ++cnt;
        }
        return ;
    }
    for (int i = last; i <= n - sum; i++) {
        dfs(curr + 1, sum + i, i);
    }
    return;
}

int main() {
    cin >> n >> k;
    dfs(0, 0, 1);
    printf("%d", cnt);
    return 0;
}