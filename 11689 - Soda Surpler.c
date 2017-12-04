#include <stdio.h>
int main ()
{
    int t, e, f, i, c, r;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d %d %d", &e, &f, &c);

        e += f;
        r = e/c;
        for (; e>=c;)
        {
            e = e/c + e%c;
            r += e/c;
        }

        printf("%d\n", r);
    }
    return 0;
}
