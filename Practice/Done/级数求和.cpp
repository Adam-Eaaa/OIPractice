#include <bits/stdc++.h>
using namespace std;
int main()
{
	int k, i = 1;
	double sum = 0;
	cin >> k;
	if (sum > k)
	{
		cout << 0;
		return 0;
	}
	while (true)
	{
		sum += (double)1 / i;
		if (sum > k)
		{
			cout << i;
			return 0;
		}
		i++;
	}
	return 0;
}