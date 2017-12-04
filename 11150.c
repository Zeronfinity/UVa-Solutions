#include <stdio.h>
int main ()
{
    int n, a;

    while(scanf("%d", &n) != EOF)
    {
        a = n;
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
