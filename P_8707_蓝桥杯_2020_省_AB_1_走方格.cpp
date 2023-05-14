#include <bits/stdc++.h>
using namespace std;
int route[35][35] = { };
int destX, destY;

void node(int x, int y)
{
    route[x][y] = route[x - 1][y] + route[x][y - 1];
    if (x % 2 == 0 && y % 2 == 0)
        route[x][y] = 0;
    if (y > destY)
        node(x + 1, 1);
    else if (x > destX)
        return ;
    else
        node(x, y + 1);
}

int main()
{
    route[1][1] = 1;
    cin >> destX >> destY;
    node(1, 2);
    printf("%d", route[destX][destY]);
    return 0;
}