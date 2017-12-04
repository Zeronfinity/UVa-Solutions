#include <stdio.h>
#include <math.h>

int main()
{
    int t, a, b, i;
    double n, m;
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        scanf("%lf %lf", &n, &m);
        a = floor(n/3);
        b = floor(m/3);
        printf("%d\n", a*b);
    }
    return 0;
}
