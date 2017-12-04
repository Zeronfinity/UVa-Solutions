#include <stdio.h>
#include <math.h>

int main ()
{
    long long t, s, cse, cs, fs, csq, fsq, c, r;

    double sq;

    while (1)
    {
        scanf("%lld", &s);

        if (s == 0)
            break;

        sq = sqrt( (double) s);

        csq = ceil(sq);
        fsq = floor(sq);
        cs = csq*csq;
        fs = fsq*fsq;
        if (csq == fsq)
        {
            if (s%2 == 0)
            {
                c = sq;
                r = 1;
            }
            else
            {
                c = 1;
                r = sq;
            }
        }
        else if (cs+fs+1 == 2*s)
        {
            c = csq;
            r = csq;
        }
        else if (2*s > (cs+fs+1))
        {
            if (cs%2 == 0)
            {
                c = csq;
                r = cs - s + 1;
            }
            else
            {
                r = csq;
                c = cs - s +1;
            }
        }
        else if (2*s < (cs+fs+1))
        {
            if (cs%2 == 0)
            {
                c = s - fs;
                r = csq;
            }
            else
            {
                r = s - fs;
                c = csq;
            }
        }

        printf("%lld %lld\n", c, r);
    }

    return 0;
}
