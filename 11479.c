#include <stdio.h>
int main()
{
    int i, T;
    long a, b, c;
    scanf("%d", &T);
    for (i = 1; i <= T;  i++)
    {
        scanf("%ld %ld %ld", &a, &b, &c);
        if ((a >= b+c) || (b >= c+a) || (c >= a+b) || a <= 0 || b <= 0 || c <= 0)
        {
            printf("Case %d: Invalid\n", i);
            continue;
        }
        if (a == b && b == c)
        {
            printf("Case %d: Equilateral\n", i);
            continue;
        }
        if (a == b || b == c || c == a)
        {
            printf("Case %d: Isosceles\n", i);
            continue;
        }
        printf("Case %d: Scalene\n", i);
    }
    return 0;
}
