// P6056
#include <bits/stdc++.h>
using namespace std;

int main() {
	int С, И, Р = 0, days;
	double beta, gamma;
	int tmp1, tmp2;
	cin >> С >> И >> days >> beta >> gamma;
	for (long long i = 0; i < days; i++) {
		tmp1 = ceil(beta * С * И);
		tmp2 = ceil(gamma * И);
		С -= tmp1;
		Р += tmp2;
		И = И - tmp2 + tmp1;
		if (С < 0) { И += С; С = 0; }
		if (И < 0) { И = 0; Р += И; }
	}
	cout << С << ' ' << И  << ' ' << Р;
	return 0;
}