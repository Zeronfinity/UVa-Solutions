#include <stdio.h>
int main()
{
    int n, a[10], i, flag, ord;
    scanf("%d", &n);
    printf("Lumberjacks:\n");
    while(n--)
    {
        ord = 0;
        for (i=0; i<10; i++)
        {
            scanf("%d", &a[i]);
            if (i==0)
                continue;
            if(i==1)
                if (a[1]>a[0])
                    flag = 0;
                else flag = 1;
            if (flag == 0)
                if (a[i] < a[i-1])
                    ord = 1;
            if (flag == 1)
                if (a[i] > a[i-1])
                    ord = 1;
        }
        if (ord==1)
            printf("Unordered\n");
        else printf("Ordered\n");
    }
    return 0;
}
