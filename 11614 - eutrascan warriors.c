#include <stdio.h>
#include <math.h>
int main ()
{
    unsigned long long t, n;
    double p;
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        p = sqrt(2*n+0.25) - 0.5;
        p = floor(p);
        printf("%0.0lf\n", p);
    }
    return 0;
}
