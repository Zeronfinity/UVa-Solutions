#include <stdio.h>
int main ()
{
    long n, i, j, a, b, tempA, tempB, right = 0;
    while (scanf("%ld", &n) == 1)
    {
        if (n==0)
            break;
        for (j = 3; j < n; j = j+2)
        {
            tempA = 0;
            tempB = 0;
            a = j;
            b = n - a;
            for (i = 2; i*i <= a; i++)
            {
                if (a % i == 0)
                {
                    tempA = 1;
                    break;
                }
            }
            if (tempA == 0)
            {
                for (i = 2; i*i <= b; i++)
                {
                    if (b % i == 0)
                     {
                        tempB = 1;
                        break;
                     }
                }

            }
            if (tempA == 0 && tempB == 0)
                {
                    right = 1;
                    break;
                }
        }
        if (right == 1)
            printf("%ld = %ld + %ld\n", n, a, b);
        else printf("Goldbach's conjecture is wrong.");
    }
return 0;
}
