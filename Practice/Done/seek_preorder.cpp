// P1030
#include <bits/stdc++.h>
using namespace std;
string mid, post;
void div(int l_mid, int r_mid, int l_post, int r_post)
{
    if (l_mid > r_mid)
        return;
    printf("%c", post[r_post]);
    int cur = l_mid;
    while (mid[cur] != post[r_post])
        cur++;
    int size = cur - l_mid;
    div(l_mid, cur - 1, l_post, l_post + size - 1);
    div(cur + 1, r_mid, l_post + size, r_post - 1);
}
int main()
{
    cin >> mid >> post;
    div(0, mid.length() - 1, 0, mid.length() - 1);
    return 0;
}