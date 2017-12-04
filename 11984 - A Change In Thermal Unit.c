#include <stdio.h>
int main ()
{
    int t, i;
    double f, c;
    scanf("%d", &t);
    for (i = 1; i <= t; i++)
    {
        scanf("%lf %lf", &c, &f);
        printf("Case %d: %0.2lf\n", i, c + 5*f/9);
    }
}
