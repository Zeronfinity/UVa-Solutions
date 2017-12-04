#include <stdio.h>
#include <math.h>
int main()
{
    int t, cn = 0;
    double d, v, u, f, s;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf %lf %lf", &d, &v, &u);
        printf("Case %d: ", ++cn);
        if (v >= u || u == 0 || v==0)
            printf("can't determine\n");
        else
        {s = sqrt(u*u - v*v);
        s = d/s;
        f = d/u;
        printf("%0.3f\n", s-f);}
    }
    return 0;
}
