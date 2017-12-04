#include <stdio.h>
int main ()
{
    int a, b;
    double x;
    while(scanf("%d:%d", &a, &b))
    {
        if (a==0 && b==0)
            break;
        if (a==12)
            a = 0;
        if ((a*5 + (double) 5/60*b) >= b)
            x = (double) (a*5 + (double) 5/60*b - b);
        else    x = (double) (b - a*5 - (double) 5/60*b);
        if (x>30)
            x = 60-x;
        x *= 6;
        printf("%0.3lf\n", x);
    }
    return 0;
}
