#include <stdio.h>

int main ()
{
    long long i, t, n, j, mc, jc;
    scanf("%lld", &t);
    for(i=1; i <= t; i++)
    {
        scanf("%lld", &n);
        long long a[n];
        mc = 0;
        jc = 0;
        for (j=0; j<n; j++)
        {
            scanf("%lld", &a[n]);
            mc += (a[n]/30+1)*10;
            jc += (a[n]/60+1)*15;
        }
        printf("Case %lld: ", i);
        if (mc < jc)
            printf("Mile %lld\n", mc);
        if (mc > jc)
            printf("Juice %lld\n", jc);
        if (mc == jc)
            printf("Mile Juice %lld\n", mc);
    }
    return 0;
}
