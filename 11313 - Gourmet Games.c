#include <stdio.h>
int main ()
{
    int t, n, m, i, c;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d %d", &n, &m);

        n -= m;
        m -= 1;

        for (c=1; n > 0;c++)
             n -= m;
        if (n<0)
            printf("cannot do this\n");
        else printf("%d\n", c);
    }
    return 0;
}
