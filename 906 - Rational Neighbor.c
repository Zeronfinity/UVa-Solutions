#include <stdio.h>
#include <math.h>

int main ()
{
    double a, b, n, c, d, flag;
    while(scanf("%lf %lf %lf", &a, &b, &n)!= EOF)
    {
        flag = 0;
        d = floor(b/(a+b*n));
        for (; ; d++)
        {
            c = ceil(a*d/b);
            while (c*b <= (a*d+n*d*b))
            {
                if ((c*b == a*d))
                {
                    c++;
                    continue;
                }
                else
                {
                    printf("%0.0lf %0.0lf\n", c, d);
                    flag = 1;
                    break;
                }
                c++;
            }
            if (flag == 1)
                break;
        }
    }
    return 0;
}
