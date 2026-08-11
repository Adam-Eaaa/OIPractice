#include <iostream>
#include <string>
using namespace std;

const string OUTPUT="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
typedef long long ll_t;

string out (ll_t num, ll_t mod) {
    if (num == 0) 
        return "";
    ll_t div = 0, res = 0;
    if (num > 0) {
        div = num / mod;
        res = num - div * mod;
    }
    else {
        div = (-num) / (-mod);
        if (div * mod != num) {
            div += 1;
        }
        res = num - mod * div;
    }
    string result = out(div, mod);
    return result + OUTPUT[res];
}

int main () {
    ll_t num, mod;
    cin >> num >> mod;
    printf("%lld=", num);
    cout << out(num, mod);
    printf("(base%lld)", mod);
    return 0;
}