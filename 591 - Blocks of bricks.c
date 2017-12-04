#include <stdio.h>
int main ()
{
    int n, i, sum, avg, c=0;
    while(1)
    {
        c++;
        sum = 0;
        scanf("%d", &n);
        if (n == 0)
            break;
        int a[n];
        for (i=0; i <n; i++)
        {
            scanf("%d", &a[i]);
            sum = sum + a[i];
        }
        avg = sum/n;
        sum = 0;
        for (i=0; i < n; i++)
         if (a[i] > avg)
            sum = sum + a[i] - avg;

        printf("Set #%d\nThe minimum number of moves is %d.\n\n", c, sum);
    }
    return 0;
}
