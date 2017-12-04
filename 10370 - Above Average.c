#include <stdio.h>

int main ()
{
    int i, c, j, sum, n;
    double avg, count;
    scanf("%d", &c);
    for (i=0; i < c; i++)
    {
        sum = 0;
        scanf("%d", &n);
        int a[n];
        for (j=0; j<n; j++)
        {
            scanf("%d", &a[j]);
            sum += a[j];
        }
        avg = sum/n;
        count = 0;
        for (j=0; j<n; j++)
            if (a[j] > avg)
                count++;
        printf("%0.3lf%%\n", count/n*100);
    }
    return 0;
}
