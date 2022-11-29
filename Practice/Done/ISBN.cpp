// P1055
#include <bits/stdc++.h>
using namespace std;
int main() {
	string isbn;
	short digit[10] = {};
	int j = 0;
	cin >> isbn;
	for (int i = 0; i < 13; i++) {
		if (isbn[i] == '-') continue;
		if (isbn[i] == 'X') digit[j] = 10;
		else digit[j] = isbn[i] - int('0');
		j++;
	}
	j = 0;
	for (int i = 0; i < 9; i++) {
		j += digit[i] * (i + 1);
	}
	j %= 11;
	if (j == digit[9]) {
		cout << "Right";
		return 0;
	}
	isbn.erase(12);
	if (j == 10) cout << isbn << 'X';
	else cout << isbn << j;
	return 0;
}