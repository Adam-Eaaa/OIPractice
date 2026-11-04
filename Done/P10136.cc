#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;

using ll_t = long long int;

ll_t N = 0, s = 0;
vector<ll_t> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        ll_t x;
        cin >> x;
        a.emplace_back(x);
    }
    sort(a.begin(), a.end());
    auto new_end = std::unique(a.begin(), a.end());
    a.erase(new_end, a.end());
    ll_t ub = a[0] / 4;
    set<ll_t> candidate;
    if (a.size() <= 3) {
        cout << (ub + 1) * ub / 2;
        return 0;
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 4 ; ++j) {
            ll_t cand = a[i] - a[j];
            cand = (cand >= 0? cand : -cand);
            for (ll_t k = 1; k * k <= cand && k <= ub; ++k) {
                if (cand % k == 0) {
                    candidate.insert(k);
                    if (cand / k <= ub)
                        candidate.insert(cand / k);
                }
            }
        }
    }
    for (const auto& k : candidate) {
        set<ll_t> verify;
        verify.clear();
        for (const auto& i : a) {
            verify.insert(i % k);
        }
        if (verify.size() <= 3)
            s += k;
    }
    cout << s;
    return 0;
}