// P1579
#include <bits/stdc++.h>
using namespace std;

bool prime(short a){
	for (int i = 2; i <= sqrt(a); i++) {
		if (a % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	short a, b, c, s;
	cin >> s;
	for (a = 2; a <= s / 3; a++) {
		if (prime(a)) {
			for (b = a; b <= s / 3; b++) {
				if (prime(b)) {
					c = s - a - b;
					if (prime(c)) {
						cout << a << ' ' << b << ' ' << c;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}