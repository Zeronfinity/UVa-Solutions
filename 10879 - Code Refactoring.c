#include <stdio.h>
int main ()
{
    long long n, i, k, a, b, c, d;
    scanf("%lld", &n);
    for (i=1; i<= n; i++)
    {
        scanf("%lld", &k);

        for (a = 2; a*a <= k; a++)
            if (k%a == 0)
            {
                b = k/a;
                break;
            }
        for (c = a+1; c*c <= k; c++)
            if (k%c == 0)
            {
                d = k/c;
                break;
            }

        printf("Case #%lld: %lld = %lld * %lld = %lld * %lld\n", i, k, a, b, c, d);
    }

    return 0;
}
