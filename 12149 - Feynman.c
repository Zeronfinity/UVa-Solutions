#include <stdio.h>
int main ()
{
    unsigned long long n;
    while(scanf("%lld", &n))
    {
        if(n==0)
            break;
        printf("%lld\n", n*(n+1)*(2*n+1)/6);
    }

    return 0;
}
