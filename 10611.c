#include <stdio.h>
int main()
{
    int n, q, i, str, end, mid;

    scanf("%d", &n);

    long long g[n];

    for (i=0; i < n; i++)
        scanf("%lld", &g[i]);

    long long l;

    for (i=0; i < q; i++)
    {
        str = 0, end = n-1;

        scanf("%lld", l);

        while (str <= end)
        {
            mid = (str+end)/2;
            if (l == g[mid])
                str =

            else if (l < g[mid])

        }

    }

    return 0;
}
