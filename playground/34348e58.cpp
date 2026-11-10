#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int d, x1, x2, e = 0;
	d = max(a.length(), b.length());
	string c(d + 1, '0');
	for (int i = 0; i <= d; i++)
	{
		if (i >= a.length())
			x1 = 0;
		else
			x1 = a[i] - '0';
		if (i >= b.length())
			x2 = 0;
		else
			x2 = b[i] - '0';
		if (x1 + x2 + e < 10)
		{
			c[i] = x1 + x2 + e + '0';
			e = 0;
		}
		if (x1 + x2 + e >= 10)
		{
			c[i] = x1 + x2 + e - 10 + '0';
			e = 1;
		}
	}
	reverse(c.begin(), c.end());
	if (c[0] == '0')
	{
		for (int i = 1; i <= d; i++)
		{
			cout << c[i];
		}
	}
	else
	{
		for (int i = 0; i <= d; i++)
		{
			cout << c[i];
		}
	}
	return 0;
}
