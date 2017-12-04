#include <stdio.h>
int main ()
{
    long long i, n, j, f, sz, an, fr, prem;
    scanf("%lld", &n);
    for (i = 0; i < n; i++)
    {
        prem = 0;
        scanf("%lld", &f);
        for (j = 0; j < f; j++)
        {
            scanf("%lld %lld %lld", &sz, &an, &fr);
            prem += sz*fr;
        }
        printf("%lld\n", prem);
    }
    return 0;
}
