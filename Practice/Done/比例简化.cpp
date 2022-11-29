// P2118
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int A, B, L;
    int a1, b1;
    int mina, minb;
    cin >> A >> B >> L;
    mina = 2147483647;
    minb = -1;
    for (a1 = L; a1 >= 1; a1--) {
        for (b1 = L; b1 >= 1; b1--) {
            if (a1 * B >= A * b1) {
                if (gcd(a1, b1) == 1) {
                    // Use cross-production instead of division
                    if (mina * b1 > minb * a1) {
                        mina = a1;
                        minb = b1;
                    }
                }
            }
        }
    }
    printf("%d %d", mina, minb);
    return 0;
}