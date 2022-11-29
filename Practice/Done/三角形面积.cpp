// P5708

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	double a, b, c, p, area;
	cin >> a >> b >> c;
	p = 0.5 * (a + b + c);
	area = sqrt(p * (p - a) * (p - b) * (p - c));
	cout << fixed << setprecision(1) << area << endl;
	return 0;
}