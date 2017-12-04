#include <stdio.h>
int main ()
{
    unsigned long long r, n, i, a;

    for (i=1; i <= 10002 ; i++)
    {
        scanf("%lld %lld", &r, &n);
        if (n==0 && r==0)
            break;
        if (n!=0)
            a=r/n;
        if (r%n == 0)
            a--;
        printf("Case %lld: ", i);
        if (a > 26)
            printf("impossible\n");
        else if (n==0)
            printf("impossible\n");
        else printf("%lld\n", a);
    }
    return 0;
}
