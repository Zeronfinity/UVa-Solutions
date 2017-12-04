#include <stdio.h>
int main ()
{
    unsigned long long l, h, v, i, j, c, m, mc=0, d, d1;

    while(scanf("%lld %lld", &l, &h))
    {
        mc = 0;
        if (l == 0 && h==0)
            break;
        if (l > h)
        {
            l = l+h;
            h = l-h;
            l = l-h;
        }
        d = h-l+1;

        for (i=l; i<=h; i++)
        {
            c=1;
            for (j=i; ; c++)
            {
                if (j%2==0)
                    j/=2;
                else j=3*j+1;
                if (j==1)
                    break;
            }
            if (c>mc)
            {
                m = i;
                mc = c;
            }
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", l, h, m, mc);
    }

    return 0;
}
