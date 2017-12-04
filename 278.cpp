#include <stdio.h>
int main ()
{
    int t, m, n, i, j, count, k, l, a;
    char c;
    scanf("%d", &t);
    while(t--)
    {
        a = 0;
        count = 0;
        scanf(" %c %d %d", &c, &m, &n);

        int b[m][n];

        for (i=0; i<m; i++)
            for (j=0; j<n; j++)
                b[i][j] = 0;

        if (c == 'r')
        {
            if (m <= n)
                printf("%d\n", m);
            else printf("%d\n", n);
            continue;
        }

        for (i=0; i<m; i++)
            for (j=0; j<n; j++)
                {if (b[i][j] == 0)
                {
                    b[i][j] = 1;
                    count++;
                    if (c == 'k')
                    {
                        if (i-2 >= 0 && j-1 >= 0)
                            b[i-2][j-1] = 1;
                        if (i-2 >= 0 && j+1 >= 0)
                            b[i-2][j+1] = 1;
                        if (i-1 >= 0 && j+2 >= 0)
                            b[i-1][j+2] = 1;
                        if (i+1 >= 0 && j+2 >= 0)
                            b[i+1][j+2] = 1;
                        if (i+2 >= 0 && j-1 >= 0)
                            b[i+2][j-1] = 1;
                        if (i+2 >= 0 && j+1 >= 0)
                            b[i+2][j+1] = 1;
                        if (i-1 >= 0 && j-2 >= 0)
                            b[i-1][j-2] = 1;
                        if (i+1 >= 0 && j-2 >= 0)
                            b[i+1][j-2] = 1;
                    }}
            for (k=0; k<m; k++)
            {for (l=0; l<n; l++)
                printf("%d", b[k][l]);
            printf("\n");

/*                    else if (c == 'Q')
                    {

                    }
                    else
                    {

                    } */
                }
        printf("%d\n", count);
}
    }
}
