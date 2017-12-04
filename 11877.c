#include <stdio.h>
int main ()
{
    int n, a;

    while(scanf("%d", &n))
    {
        if (n==0)
            break;
        a = 0;
        while (n >= 3)
        {
            a = a + n/3;
            n = n/3 + n%3;
        }
        if (n == 2)
            a++;
        printf("%d\n", a);
    }
    return 0;
}
