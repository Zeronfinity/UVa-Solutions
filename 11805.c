#include <stdio.h>
int main ()
{
    int n, k, p, i, t, r;

    scanf("%d", &t);

    for (i=1; i<=t; i++)
    {
        scanf("%d %d %d", &n, &k, &p);

        r = (k+p)%n;

        if (r==0)
            r = n;
        printf("Case %d: %d\n", i, r);
    }

    return 0;
}
