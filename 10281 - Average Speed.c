#include <stdio.h>
#include <string.h>

int main ()
{
    int i, flag=0, len;
    char g, a[100], b[100], c[100];
    double d=0, t=0, v=0;
    strcpy(a, "00:00:00 0");
    strcpy(b, a);
    while (scanf("%[^\n]s", a)!=EOF)
    {
        scanf("%c", &g);
        strcpy(c, a);
        len = strlen(a);
        if (a[1] == ':')
        {
            for(i=len; i>=0; i--)
                a[i+1] = a[i];
            a[0] = '0';
        }
        if(len > 8)
        {
            if (flag != 0)
            {
                t = (a[0]*10-b[0]*10+a[1]-b[1] + (double) (a[3]*10-b[3]*10+a[4]-b[4])/60 + (double) (a[6]*10-b[6]*10+a[7]-b[7])/3600 );
                d = d + v*t;
            }
            else flag = 1;
            v = 0;
            for (i=9; a[i]!=0; i++)
                if (a[i] >= '0' && a[i] <= '9')
                    v=v*10+a[i]-'0';
        }
        else
        {
            t = (a[0]*10-b[0]*10+a[1]-b[1] + (double) (a[3]*10-b[3]*10+a[4]-b[4])/60 + (double) (a[6]*10-b[6]*10+a[7]-b[7])/3600 );
            d = d + v*t;
            printf("%s %0.2lf km\n", c, d);
        }

        strcpy(b, a);
    }

    return 0;
}
