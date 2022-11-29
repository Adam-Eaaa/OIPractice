// P1134
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    long long x, temp, cnt = 0, res = 1;
    cin >> x;
    for(long long i = 2; i <= x; i++) {
        temp = i;
        while(temp % 2 == 0) {
            cnt++;
            temp = temp / 2;
        }
        while(temp % 5 == 0) {
            cnt--;
            temp /= 5;
        }
        res  =  res * temp % 10;
    }
    for(long long i = 0; i < cnt; i++) {
        res = res * 2 % 10;
    }
    printf("%d", res%10);
    return 0;
}