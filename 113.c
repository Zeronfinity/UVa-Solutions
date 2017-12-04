#include <stdio.h>
#include <string.h>

int main ()
{
    int n, len, lenn, x, i, j, count;
    char p[2000], res[2000], ns[5];
    while(scanf(" %s %s", ns, p) != EOF)
    {
        n = 0;
        lenn = strlen(ns);
        for (i=0; i < lenn; i++)
            n = 10*n + ns[i] - '0';

        count = 1;

        while (strcmp(ns, p) != 0)
        {
            i = 0, j = 0;
            x = p[0]-'0';
            len = strlen(p);

            while (i != len)
            {
                i++;
                if (x >= n)
                {
                    res[j] = x/n + '0';
                    x = (x%n)*10+p[i] - '0';
                    j++;
                }
                else
                    x = 10*x + p[i] - '0';

            }
            res[j] = 0;
            strcpy(p, res);
            count++;
        }
        printf("%d\n", count);
    }
}
