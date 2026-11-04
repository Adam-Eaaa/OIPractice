#include <stdio.h>
#include <stdlib.h>
#define input(a) scanf("%d", &a)
#define output(a) printf("%d", a)
#define max(a,b) (a)>(b)?(a):(b)
int res[1030][1030];

int main()
{
    int r, i, j, compMax = 0;
    input(r);
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= i; j++)
        {
            input(res[i][j]);
            res[i][j] += max(res[i - 1][j - 1], res[i - 1][j]);
            compMax = max(compMax, res[i][j]);
        }
    }
    output(compMax);
    return 0;
}