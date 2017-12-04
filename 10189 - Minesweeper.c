#include <stdio.h>
int main ()
{
    int n, m, r, c, x = 0;
    while(scanf("%d %d", &n, &m))
    {
        x++;

        if (n == 0 && m == 0)
            break;

        if (x > 1)
            printf("\n");


        char a[n][m];

        for (r = 0; r < n; r++)
            for (c = 0; c < m; c++)
                scanf(" %c", &a[r][c]);

        for (r = 0; r < n; r++)
            for (c = 0; c < m; c++)
                if (a[r][c] == '.')
                    a[r][c] = '0';

        for (r = 0; r < n; r++)
            for (c = 0; c < m; c++)
                if(a[r][c] == '*')
                {
                    if ((c+1) < m && a[r][c+1] != '*')
                        a[r][c+1]++;
                    if ((r+1) < n && (c+1) < m && a[r+1][c+1] != '*')
                        a[r+1][c+1]++;
                    if ((r+1) < n && a[r+1][c] != '*')
                        a[r+1][c]++;
                    if ((r+1) < n && (c-1) >=0 && a[r+1][c-1] != '*')
                        a[r+1][c-1]++;
                    if ((c-1) >= 0 && a[r][c-1] != '*')
                        a[r][c-1]++;
                    if ((r-1) >= 0 && (c-1) >=0 && a[r-1][c-1] != '*')
                        a[r-1][c-1]++;
                    if ((r-1) >=0 && a[r-1][c] != '*')
                        a[r-1][c]++;
                    if ((r-1) >= 0 && (c+1) < m && a[r-1][c+1] != '*')
                        a[r-1][c+1]++;
                }
        printf("Field #%d:\n", x);
        for (r = 0; r < n; r++)
        {
            for (c = 0; c < m; c++)
                printf("%c", a[r][c]);
            printf("\n");
        }
    }
    return 0;
}
