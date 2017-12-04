#include <stdio.h>
#include <string.h>

int main ()
{
    int n, i, j, y, x, k, l, top;
    char c[52][3];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        y = 0;
        top = 26;

        for (j = 0; j < 52; j++)
            scanf(" %s", c[j]);

        for (l = 0; l < 3; l++)
        {
            if (c[top][0] > '2' && c[top][0] < '9')
                x = c[top][0] - 48;
            else x = 10;
            y += x;
            top = top - 11 + x;
        }
        for (j = top + 1, k = 27; k < 52; j++, k++)
            strcpy(c[j], c[k]);
        printf("Case %d: %s\n", i+1, c[y-1]);
    }
    return 0;
}
