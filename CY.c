#include <stdio.h>

int main()
{
    int n, a[200050], max = -100000;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i - 1] > 0)
            a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        max = max > a[i] ? max : a[i];
    }
    printf("%d", max); 
    return 0;
}