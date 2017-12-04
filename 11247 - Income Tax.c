#include <stdio.h>
int main ()
{
    unsigned long long m, x, a;
    while(scanf("%lld %lld", &m, &x))
    {
        if (m==0 && x==0)
            break;
        if (x == 0 || m == 1 || x == 100)
        {
            printf("Not found\n");
            continue;
        }
        a = m-1;
        a *= 100;
        if (a%(100-x) == 0)
        {
            a = a/(100-x);
            a--;
        }
        else a /= (100-x);
        if (a<m)
            printf("Not found\n");
        else printf("%lld\n", a);
    }

    return 0;
}
