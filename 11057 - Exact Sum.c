#include <stdio.h>
#include <stdlib.h>
int main ()
{
    unsigned long long n, m, i, min=10000000000000000, j, l=3, k=5;

    while(scanf("%lld", &n) != EOF)
    {
        min=10000000000000000;
        unsigned long long a[n];
        for (i=0; i<n; i++)
            scanf("%lld", &a[i]);
        scanf("%lld", &m);

        for (i=0; i<n-1; i++)
            for (j=i+1; j<n; j++)
                if (a[i] + a[j] == m)
                    if (llabs(a[j] - a[i]) < min)
                    {
                        min = llabs(a[j] - a[i]);
                        l = a[i];
                        k = a[j];


                    }
        if (l > k)
        {
            l = l + k;
            k = l - k;
            l = l - k;

        }

        printf("Peter should buy books whose prices are %lld and %lld.\n\n", l, k);
    }
    return 0;
}
