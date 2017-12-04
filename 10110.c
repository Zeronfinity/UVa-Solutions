#include <stdio.h>

int main ()
{

    long long n, i;
    int count;
//    while(scanf("%lld", &n))
    for (n=1; n <= 20; n++)
    {
        count = 0;
        if (n==0)
            break;
        for(i = 1; i*i <= n; i++)
        {
            if (n == 1)
            {
                count = 1;
                break;
            }
            if (n%i==0)
                count=count+2;
            if (i*i == n)
                count--;
        }
        printf("%lld => %d\n", n, count);

/*        if (count%2 == 0)
            printf("no\n");
        if (count%2 == 1)
            printf("yes\n"); */

    }



    return 0;
}
