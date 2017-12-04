#include <stdio.h>

int main()
{
    int a, b, c, d, s;

    while (1)
    {
        s = 3*360;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if (a == 0 && b == 0 && c == 0 && d == 0)
            break;
        if (a < b)
            s += (40 + a - b)*9;
        else s += (a - b)*9;
        if (b > c)
            s += (40 + c - b)*9;
        else s += (c - b)*9;
        if (c < d)
            s += (40 + c - d)*9;
        else s += (c - d)*9;
        printf("%d\n", s);
    }
    return 0;
}
