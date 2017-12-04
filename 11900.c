#include <stdio.h>
int main ()
{
    int T, n, P, Q, i, j, w, sum, temp, temp1;

    scanf("%d", &T);

    for (i = 1; i <= T; i++)
    {
        temp = 0;
        temp1 = 0;
        sum = 0;
        scanf("%d %d %d", &n, &P, &Q);
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &w);
            sum += w;
                if (sum > Q)
                {
                    temp = j - 1;
                    break;
                }
                if (j > P)
                {
                    temp = j - 1;
                    break;
                }
        }
        if (j == n+1)
            temp = j - 1;
        printf("Case %d: %d\n", i, temp);
    }

    return 0;
}
