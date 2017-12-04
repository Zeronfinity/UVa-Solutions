#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long pwr(long long f)
{
    long long i, z=1;
    for (i=1; i<=f; i++)
        z = z*2;
    return z;
}

int main ()
{
    unsigned long long a, b, c[100], d[100], e[100], f, g, x, y, z, i;
    while(scanf("%lld %lld", &a, &b)!=EOF)
    {
        for (i=0; i<100; i++)
        {
            c[i] = 0;
            d[i] = 0;
            e[i] = 0;
        }
        x=0;
        f=0;
        g=0;
        while (a!=0)
        {
            c[x]=a%2;
            a=a/2;
            x++;
        }
        y=0;
        while (b!=0)
        {
            d[y]=(b%2);
            b=b/2;
            y++;
        }
        z = 0;
        while(z<x || z<y)
        {
            e[z] = c[z]+d[z];
            if (e[z]>1)
                e[z] = 0;
            z++;
        }
        f=0;
        while(f!=z)
        {
            g = g + pwr(f)*e[f];
            f++;
        }
        printf("%lld\n", g);
    }
    return 0;
}
