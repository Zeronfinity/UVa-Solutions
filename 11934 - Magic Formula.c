#include <stdio.h>
int main ()
{
    long long a, b, c, d, l, n, r, i;

    while (1)
    {
        r = 0;
        scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &l);

        if (a == 0 && b==0 && c==0 && d==0 && l==0)
            break;

        for (i=0; i<=l; i++)
            if ((a*i*i+b*i+c)%d==0)
                r++;

        printf("%lld\n", r);
    }
    return 0;
}
