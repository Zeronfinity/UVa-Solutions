#include <stdio.h>
#include <string.h>
#include <math.h>

int main ()
{
    int i, t, j, temp, k, len, x, y;
    double rt;
    char s[10100], g[10100];
    scanf("%d", &t);

    for (i=0; i < t; i++)
    {
        k = 0;
        temp = 0;
        scanf(" %[^\n]s", g);
        for (j=0; g[j] != 0; j++)
        {
            if (g[j] >= 'a' && g[j] <= 'z')
            {
                s[k] = g[j];
                k++;
            }
        }
        s[k] = 0;
        len = strlen(s);
        if (sqrt(len) != round(sqrt(len)))
            temp = 1;
        if (len%2 == 1)
            for (j=0, x=len-1; j != x; j++, x--)
                if (s[j] != s[x])
                {
                    temp = 1;
                    break;
                }
        if (len%2 == 0)
            for (j=0, x=len-1; x-j >= 1; j++, x--)
                if (s[j] != s[x])
                {
                    temp = 1;
                    break;
                }
        y = round(sqrt(len));
        printf("Case #%d:\n", i+1);
        if (temp == 1)
            printf("No magic :(\n");
        else printf("%d\n", y);
    }

    return 0;
}
