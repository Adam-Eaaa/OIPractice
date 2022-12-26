// P1143
#include <bits/stdc++.h>
using namespace std;

int ctoi(char c)
{
    if ('A' <= c && c <= 'F')
    {
        return 10 + c - 'A';
    }
    return c - '0';
}

string base_cvt(int a, int base)
{
    string res = "";
    int temp;
    while (a > 0)
    {
        temp = a % base;
        if (temp >= 10)
        {
            res = string() + char('A' + temp - 10) + res;
        }
        else
        {
            res = string() + char('0' + temp) + res;
        }
        a = a / base;
    }
    return res;
}

int main()
{
    string in;
    long long int out = 0;
    int in_base, out_base;
    cin >> in_base >> in >> out_base;
    for (int i = in.length() - 1; i >= 0; i--)
    {
        out += pow(in_base, (in.length() - i - 1)) * ctoi(in[i]);
    }
    cout << base_cvt(out, out_base);
    return 0;
}