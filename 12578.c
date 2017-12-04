#include <stdio.h>
#include <math.h>
int main ()
{
    int t, i;
    double l;
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        scanf("%lf", &l);
        printf("%0.2lf %0.2lf\n", (acos(-1)*l*l/25), (l*l*3/5 - acos(-1)*l*l/25));
    }
    return 0;
}
