#include <stdio.h>
int main ()
{
    int a[3], b[2], c[3], i, j, count, temp, ans, k;

    while(scanf("%d %d %d %d %d", &c[0], &c[1], &c[2], &b[0], &b[1]))
    {
        count = 0;
        a[0] = c[0];
        a[1] = c[1];
        a[2] = c[2];
        if (a[0]==0 && a[1]==0 && a[2]==0 && b[0]==0 && b[1]==0)
            break;

        for (i = 0; i < 2; i++)
            for (j = 1; j < 3; j++)
                if (a[i] > a[j])
                {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
        for (j=0; j<2; j++)
            for (i=0; i < 3; i++)
                if (b[j] < a[i])
                {
                    count++;
                    a[i] = 0;
                    i = 4;
                }
        if (count == 2)
            printf("-1\n");
        else
        {
            if (count == 0)
                ans = 1;
            else
                for (i=2; i >= 0; i--)
                    if (a[i] != 0)
                    {
                        ans = a[i] + 1;
                        break;
                    }

            for (k=0; k<4; k++)
            {
                for (i = 0; i < 2; i++)
                    if (ans == b[i])
                        ans++;
                for (j = 0; j < 3; j++)
                    if (ans == c[j])
                        ans++;
            }


            if (ans > 52)
                printf("-1\n");
            else printf("%d\n", ans);
        }
    }
    return 0;
}
