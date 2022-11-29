// P1865
#include <iostream>
#include <cmath>
using namespace std;

bool prime(int n) {
    if(n==1) return false;
    if(n==2) return true;
    if(n==3) return true;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int main() {
    long long l, r;
    int n, m, cnt = 0;
    int sum[1000001] = { };
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        sum[i] = sum[i-1] + prime(i);
    }
    for(int i=0; i<n; i++) {
        cin >> l >> r;
        cnt = 0;
        if(l < 1 || r > m) {
            cout << "Crossing the line" << endl;
            continue;
        }
        cout << sum[r] - sum[l-1] << endl;
    }
    return 0;
}