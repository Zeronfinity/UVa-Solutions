#include <stdio.h>
#include <string.h>

int main ()
{
    int j, k, temp, len, x;
    char s[10000], g[10000];

    while(scanf(" %[^\n]s", g))
    {
        if (!strcmp(g, "DONE"))
            break;

        k = 0;
        temp = 0;
        for (j=0; g[j] != 0; j++)
        {
            if (g[j] >= 'a' && g[j] <= 'z')
            {
                s[k] = g[j];
                k++;
            }

            if (g[j] >= 'A' && g[j] <= 'Z')
            {
                s[k] = g[j] + 32;
                k++;
            }
        }
        s[k] = 0;

        len = strlen(s);

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

        if (temp == 1)
            printf("Uh oh..\n");
        else printf("You won't be eaten!\n");
    }
    return 0;
}
