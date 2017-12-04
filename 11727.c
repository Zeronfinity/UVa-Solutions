#include <stdio.h>
int main ()
{
    int T, a, b, c, i, x;
    scanf("%d", &T);
    for (i=1; i<=T; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (a > b && a < c)
            x = a;
        if (a > c && a < b)
            x = a;
        if (b > a && b < c)
            x = b;
        if (b > c && b < a)
            x = b;
        if (c > b && c < a)
            x = c;
        if (c > a && c < b)
            x = c;
        printf("Case %d: %d\n", i, x);
    }
return 0;
}
