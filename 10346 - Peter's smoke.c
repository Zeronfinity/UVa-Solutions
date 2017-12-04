#include<stdio.h>

int main()
{
    int n, k, s;

    while(scanf("%d %d", &n, &k) == 2)
    {
        s = 0;
        s += n;
        while(n>=k)
        {
            s += n/k;
            n = n/k + n%k;
        }
        printf("%d\n", s);
    }

    return 0;
}
