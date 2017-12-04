#include <stdio.h>

int main ()
{
    int n, i, x, temp;
    while(scanf("%d", &n) != EOF)
    {
        temp = 0;
        int a[n], b[n-1];

        for (i = 0; i < (n-1); i++)
            b[i] = 0;

        for (i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);

            if (i == 0)
                continue;
            x = a[i]-a[i-1];
            if (x < 0)
                x *= -1;
            b[x-1] = 1;
        }
        if (n == 1)
        {
            printf("Jolly\n");
            continue;
        }



        for (i = 0; i < (n-1); i++)
            if (b[i] == 0)
                temp = 1;

        if (temp == 1)
                printf("Not jolly\n");
        else printf("Jolly\n");
    }
    return 0;
}
