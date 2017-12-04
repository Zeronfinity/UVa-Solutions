#include <stdio.h>
int main ()
{
    unsigned int n, i, sum;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d", &n))
    {
        if (n==0)
            break;
        if (n==1)
        {printf("    1  DEFICIENT\n");
        continue;}
        sum = 0;
        for (i=1; i*i <= n; i++)
            if (n%i==0)
            {
                sum += i;
                if (i!=1 && i != (n/i) )
                    sum += n/i;
            }
        if (n < 10000 && n>999)
            printf(" ");
        if (n < 1000 && n>99)
            printf("  ");
        if (n < 100 && n>9)
            printf("   ");
        if (n < 10)
            printf("    ");
        printf("%d", n);
        printf("  ");
        if (sum == n)
            printf("PERFECT\n");
        else if (sum < n)
            printf("DEFICIENT\n");
        else printf("ABUNDANT\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
