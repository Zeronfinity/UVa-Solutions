#include <stdio.h>
int main ()
{
    int T, i, n, j, max;
    scanf("%d", &T);
    for (i = 1; i <= T; i++)
    {
        max = 0;
        scanf("%d", &n);
        int c[n];
        for (j = 0; j < n; j++)
        {
            scanf("%d", &c[j]);
            if (c[j] > max)
                max = c[j];
        }
        printf("Case %d: %d\n", i, max);
    }
}
