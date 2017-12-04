#include <stdio.h>
int sumr[100][100][100];
int main ()
{
    int n, i, j, k, x, y, sum, max, sump;
    while(scanf("%d", &n)!=EOF)
    {
        max = -127;
        sum = 0;
        int num[n][n];

        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                scanf("%d", &num[i][j]);



        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
            {
                sump = 0;
                for (k=j; k<n; k++)
                {
                    sumr[i][j][k] = num[i][k];
                    sumr[i][j][k] += sump;
                    sump = sumr[i][j][k];
                }
            }



        for (i=0; i<n; i++)
            for (j=i; j<n; j++)
                for (x=0; x<n; x++)
                    for (y=x; y<n; y++)
                    {
                        sum = 0;
                        for (k=x; k<=y; k++)
                            sum += sumr[k][i][j];
                        if (sum > max)
                            max = sum;
                    }
        printf("%d\n", max);
    }
    return 0;
}
