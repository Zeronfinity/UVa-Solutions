#include <stdio.h>
int main ()
{
    long long n, l, i, j, c;

    scanf("%lld", &n);

    while (n--)
    {
        c = 0;
        scanf("%lld", &l);

        long long a[l];

        for (i=0; i<l; i++)
            scanf("%lld", &a[i]);

        for (i=0; i<l-1; i++)
            for (j=i+1; j<l; j++)
                if (a[i] > a[j])
                {
                    a[i] = a[i] + a[j];
                    a[j] = a[i] - a[j];
                    a[i] = a[i] - a[j];
                    c++;
                }

        for (i=0; i<l; i++)
            printf("%lld ", a[i]);

        printf("Optimal train swapping takes %lld swaps.\n", c);
    }

    return 0;
}
