#include <iostream>
#include <numeric>
using namespace std;

using ll = long long int;
const int MOD = 997, MAXN = 62;

// Pre process vars
ll inv[MAXN] = {0, 1, 499, 665, 748, 399, 831, 285, 374, 554, 698, 272, 914, 767, 641, 133, 187, 176, 277, 105, 349, 95, 136, 867, 457, 678, 882, 517, 819, 722, 565, 193, 592, 423, 88, 57, 637, 512, 551, 588, 673, 535, 546, 371, 68, 709, 932, 297, 727, 468, 339, 391, 441, 301, 757, 852, 908, 35, 361, 169, 781, 474},
    inv_factorial[MAXN] = {1, 1, 499, 831, 457, 889, 979, 852, 605, 178, 616, 56, 337, 256, 588, 438, 152, 830, 600, 189, 159, 150, 460, 20, 167, 565, 827, 843, 493, 17, 632, 342, 73, 969, 527, 129, 419, 173, 608, 578, 164, 4, 190, 700, 741, 947, 259, 154, 294, 6, 40, 685, 991, 188, 742, 86, 322, 303, 710, 350, 172, 771};
ll pow2[2000] = {};
ll g[MAXN][MAXN];
ll cnt[MAXN];
ll ans;

int N;

void preproc() {
    pow2[0] = 1;
    for (int i = 1; i < 2000; ++i) {
        pow2[i] = (pow2[i - 1] << 1) % MOD;
    }
    for (int i = 1; i < MAXN; ++i) {
        for (int j = 1; j < MAXN; ++j) {
            g[i][j] = gcd(i, j);
        }
    }
}

void dfs(int remain, int maxp, int m, ll D_inv) {
    if (remain == 0) {
        ans = (ans + pow2[m] * D_inv) % MOD;
        return;
    }
    for (int p = min(remain, maxp); p >= 1; --p) {
        int next_m = m + p / 2;

        for (int q = 1; q <= N; ++q) {
            next_m += cnt[q] * g[p][q];
        }

        ll next_D_inv = D_inv * inv[p] % MOD * inv[cnt[p] + 1] % MOD;

        ++cnt[p];
        dfs(remain - p, p, next_m, next_D_inv);
        --cnt[p];
    }
}

int main(void) {
    cin >> N;
    preproc();
    dfs(N, N, 0, 1);
    cout << ans;
    return 0;
}