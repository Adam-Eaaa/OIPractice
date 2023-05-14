#include <iostream>
#include <algorithm>
using namespace std;

struct Match
{
    int a, b;
};

bool compare(Match a, Match b)
{
    return a.b < b.b;
}

int main()
{
    int n, cur = 0, cnt = 0;
    Match match[100010];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> match[i].a >> match[i].b;
    }
    sort(match + 1, match + n + 1, compare);
    for (int i = 1; i <= n; i++)
    {
        if (match[i].a >= cur)
        {
            cur = match[i].b;
            ++cnt;
        }
    }
    printf("%d", cnt);
    return 0;
}