#include <stdio.h>
int main()
{
    int c[10], t, n, i, j;
    scanf("%d", &t);
    while(t--)
    {
        for (i=0; i<10; i++)
            c[i] = 0;
        scanf("%d", &n);
        for (i=1;i <= n;i++)
        {
            j = i;
            while(j!=0)
            {
                c[j%10]++;
                j/=10;
            }
        }
        for (i=0; i<10; i++)
        if (i!=9)
            printf("%d ", c[i]);
        else printf("%d", c[i]);
        printf("\n");
    }
    return 0;
}
