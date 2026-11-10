#include <iostream>
#include <cmath>
using namespace std;

typedef long double ld;


ld x1, y1, r1, x2, y2, r2, x3, y3, A_1, A_2, D, k, q;

const ld eps = 1e-10;

ld A1, B1, C1, A2, B2, C2;

void inverse() {
    A_1 = x1 * x1 + y1 * y1 - r1 * r1;
    x1 /= A_1;
    y1 /= A_1;
    r1 /= (A_1 >= 0 ? A_1 : -A_1);
    A_2 = x2 * x2 + y2 * y2 - r2 * r2;
    x2 /= A_2;
    y2 /= A_2;
    r2 /= (A_2 >= 0 ? A_2 : -A_2);
}

int main(void) {
    int T;
    cin >> T;
    while (T--) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2 >> x3 >> y3;
        x1 -= x3;
        x2 -= x3;
        y1 -= y3;
        y2 -= y3;
        inverse();
        D = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        k = r1 - r2;
        q = D - k * k;
        if (D < eps || q < -eps) {
            cout << 0 << endl;
            continue;
        }
        if (q <= eps) {
            A1 = k * (x1 - x2);
            B1 = k * (y1 - y2);
            C1 = r1 * D - (A1 * x1 + B1 * y1);
            if (C1 <= eps) {
                cout << 0 << endl;
                continue;
            }
            cout << 1 << endl;
            cout << x3 - A1 / C1 / 2 << ' '
                << y3 - B1 / C1 / 2 << ' '
                << D / C1 / 2 << endl;
            continue;
        }
        if (q > eps) {
            ld s = sqrtl(q);
            ld dx = x1 - x2;
            ld dy = y1 - y2;
            int sub1 = 0, sub2 = 0;
            A1 = k * dx - s * dy;
            B1 = k * dy + s * dx;
            C1 = r1 * D - (A1 * x1 + B1 * y1);
            sub1 = static_cast<int>(C1 > eps);
            A2 = k * dx + s * dy;
            B2 = k * dy - s * dx;
            C2 = r1 * D - (A2 * x1 + B2 * y1);
            sub2 = static_cast<int>(C2 > eps);
            cout << sub1 + sub2 << endl;
            if (sub1) {
                cout << x3 - A1 / C1 / 2 << ' '
                    << y3 - B1 / C1 / 2 << ' '
                    << D / C1 / 2 << endl;
            }
            if (sub2) {
                cout << x3 - A2 / C2 / 2 << ' '
                    << y3 - B2 / C2 / 2 << ' '
                    << D / C2 / 2 << endl;
            }
        }
    }
    return 0;
}