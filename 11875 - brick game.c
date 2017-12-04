#include <stdio.h>
int main ()
{
    int i, t, n, c, sum, j;
    scanf("%d", &t);
    for (c=1; c<=t; c++)
    {
        sum = 0;
        scanf("%d", &n);
        int a[n];
        for (i = 0; i<n; i++)
            scanf("%d", &a[i]);

        for (i=0; i<n-1; i++)
            for (j=i+1; j<n; j++)
                if (a[i] < a[j])
                {
                    a[i] = a[i] + a[j];
                    a[j] = a[i] - a[j];
                    a[i] = a[i] - a[j];
                }

        printf("Case %d: %d\n", c, a[(n-1)/2]);
    }

    return 0;
}
