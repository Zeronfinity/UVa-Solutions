#include <stdio.h>
#include <string.h>

int main ()
{
    int i, j, k;
    double d, min;
    long n, p, r, max;
    char winner[100], req[100], prop[100], requ[100];

    for (j = 1; ; j++)
    {
        max = 0;
        min = 10000000;

        scanf("%ld %ld", &n, &p);

        if (n == 0 && p == 0)
            break;

        for (i = 0; i < n; i++)
                scanf(" %[^\n]s", req);

        for (i = 0; i < p; i++)
        {
            scanf(" %[^\n]s", prop);

            scanf("%lf %ld", &d, &r);

            for (k = 0; k < r; k++)
                scanf(" %[^\n]s", requ);

            if (r >= max)
                {
                    if (r == max && d >= min)
                        continue;
                    max = r;

                    min = d;

                    strcpy(winner, prop);
                }
        }
        if (j > 1)
            printf("\n");
        printf("RFP #%d\n%s\n", j, winner);
    }
    return 0;
}
